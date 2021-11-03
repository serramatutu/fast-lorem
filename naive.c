/*
A naive implementation of a Lorem Ipsum generator 
without any trickeries or weird optimizations.

This program uses normal printf to perform IO paragraph by paragraph.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "util.h"

int main() {
    srand(time(NULL));
    uint seed = rand();

    char buf[LOREM_MAX_PARAGRAPH_SIZE];

    while (1) {
        uint pos = paragraph(&seed, buf);
        buf[pos] = '\0';
        printf("%s", buf);
    }
}
