#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "vocab.h"

static char* vocab[] = LOREM_VOCAB;

#define MAX_COMMAS 4

int randRange(uint* seed, int min, int max) {
    return (rand_r(seed) / (float)RAND_MAX) * (max - min) + min;
}

char capitalize(char c) {
    return c - ('a' - 'A');
}

uint word(uint* seed, char* buf, uint pos) {
    uint index = randRange(seed, 0, sizeof(vocab) / sizeof(char*) - 1);
    uint wordLen = strlen(vocab[index]);
    memcpy(buf + pos, vocab[index], wordLen);
    return pos + wordLen;
}

uint sentence(uint* seed, char* buf, uint pos) {
    uint startPos = pos;
    u_char words = randRange(seed, 3, 40);

    u_char commas;
    if (words <= 6) {
        commas = randRange(seed, 0, 1);
    }
    else if (words <= 12) {
        commas = randRange(seed, 0, 2);
    }
    else {
        commas = randRange(seed, 1, 4);
    }

    uint commaPos[MAX_COMMAS];
    for (uint i = 0; i < commas; i++) {
        uint sectorSize = words / commas;
        commaPos[i] = randRange(seed, i * sectorSize, (i + 1) * sectorSize - 1);
    }

    char nextComma = commas > 0 ? 0 : -1;

    for (uint i = 0; i < words - 1; i++) {
        pos = word(seed, buf, pos);

        // comma
        if (i == commaPos[nextComma]) {
            buf[pos] = ',';
            pos++;

            nextComma++;
            // cannot put comma over itself
            if (commaPos[nextComma] == i) {
                commaPos[nextComma]++;
            }

            if (nextComma == commas) {
                nextComma = -1;
            }
        }

        buf[pos] = ' ';
        pos++;
    }

    pos = word(seed, buf, pos);
    buf[pos] = '.';
    pos++;

    buf[startPos] = capitalize(buf[startPos]);

    return pos;
}

uint paragraph(uint* seed, char* buf) {
    u_char sentences = randRange(seed, 3, 8);
    uint pos = 0;

    for (char i = 0; i < sentences - 1; i++) {
        pos = sentence(seed, buf, pos);
        buf[pos] = ' ';
        pos++;
    }
    pos = sentence(seed, buf, pos);

    buf[pos] = '\n';
    buf[pos+1] = '\n';
    pos += 2;

    return pos;
}

#endif