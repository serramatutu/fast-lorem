/*
A multithreaded implementation that delegates paragraph
generation to each thread and writes to output in batches.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>

#include "util.h"

#define NUM_THREADS 4
#define BUF_SIZE (65536 * NUM_THREADS * 8)
#define CACHE_LINE_SIZE 64
#define MEM_PAGE_SIZE 4096

#define THREAD_BUF_SIZE (BUF_SIZE / NUM_THREADS)

typedef struct ThreadControl {
    uint num;
    uint seed;
    sem_t workAvailable;
    sem_t workFinished;
} ThreadControl;

ThreadControl controls[NUM_THREADS];

// align buf to memory pages for efficient padding
__attribute__((aligned(MEM_PAGE_SIZE))) char buf[BUF_SIZE];

void* generatorThread(void* arg) {
    ThreadControl* control = (ThreadControl*)arg;

    // starting position for writes
    uint start = THREAD_BUF_SIZE * control->num;
    uint end = THREAD_BUF_SIZE * (control->num + 1);

    // Buffer which is (hopefully) be cached. Write directly to it
    // and copy it to the actual buf in batches
    // char cachedBuf[CACHE_LINE_SIZE];

    while (1) {
        sem_wait(&control->workAvailable);

        uint pos = start;
        while (pos < end) {
            pos += paragraph(&control->seed, buf);
        }

        sem_post(&control->workFinished);
    }
}

pthread_t initThread(uint num, int baseSeed) {
    ThreadControl* control = controls + num;

    // initialize the thread control
    control->num = num;
    control->seed = baseSeed + num;
    sem_init(&control->workAvailable, 0, 0);
    sem_init(&control->workFinished, 0, 0);

    // create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, generatorThread, (void*)control);

    return thread;
}

void writeFile(FILE* file, void* buf, uint n) {
    int fileNumber = fileno(file);
    while (n) {
        ssize_t written = write(fileNumber, buf, n);

        if (written >= 0) {
            n -= written;
            buf += written;
        }
    }
}

int main() {
    pthread_t threads[NUM_THREADS];

    uint baseSeed = time(NULL);
    for (uint i = 0; i < NUM_THREADS; i++) {
        threads[i] = initThread(i, baseSeed);
    }

    while (1) {
        // wakeup all worker threads
        for (uint i = 0; i < NUM_THREADS; i++) {
            sem_post(&controls[i].workAvailable);
        }

        // wait for all threads to finish work
        for (uint i = 0; i < NUM_THREADS; i++) {
            sem_wait(&controls[i].workFinished);
        }

        // IO
        writeFile(stdout, buf, BUF_SIZE);
    }
}
