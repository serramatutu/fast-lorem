/*
A naive implementation of a Lorem Ipsum generator 
without any trickeries or weird optimizations.

This program uses normal printf to perform IO paragraph by paragraph.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vocab.h"
static char* vocab[] = LOREM_VOCAB;

#define MAX_COMMAS 4

// 8 sentences of 40 words with 4 commas, 1 period and max word size, plus delimiter
#define MAX_PARAGRAPH_SIZE (8 * 40 * (4 + 1) * LOREM_MAX_WORD_LEN + 2)

int randRange(int min, int max) {
    return (rand() / (float)RAND_MAX) * (max - min) + min;
}

char capitalize(char c) {
    return c - ('a' - 'A');
}

uint word(char* buf, uint pos) {
    uint index = randRange(0, sizeof(vocab) / sizeof(char*) - 1);
    uint wordLen = strlen(vocab[index]);
    memcpy(buf + pos, vocab[index], wordLen);
    return pos + wordLen;
}

uint sentence(char* buf, uint pos) {
    uint startPos = pos;
    u_char words = randRange(3, 40);

    u_char commas;
    if (words <= 6) {
        commas = randRange(0, 1);
    }
    else if (words <= 12) {
        commas = randRange(0, 2);
    }
    else {
        commas = randRange(1, 4);
    }

    uint commaPos[MAX_COMMAS];
    for (uint i = 0; i < commas; i++) {
        uint sectorSize = words / commas;
        commaPos[i] = randRange(i * sectorSize, (i + 1) * sectorSize - 1);
    }

    char nextComma = commas > 0 ? 0 : -1;

    for (uint i = 0; i < words - 1; i++) {
        pos = word(buf, pos);

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

    pos = word(buf, pos);
    buf[pos] = '.';
    pos++;

    buf[startPos] = capitalize(buf[startPos]);

    return pos;
}

uint paragraph(char* buf) {
    u_char sentences = randRange(3, 8);
    uint pos = 0;

    for (char i = 0; i < sentences - 1; i++) {
        pos = sentence(buf, pos);
        buf[pos] = ' ';
        pos++;
    }
    pos = sentence(buf, pos);

    buf[pos] = '\n';
    buf[pos+1] = '\n';
    pos += 2;

    return pos;
}

int main() {
    char buf[MAX_PARAGRAPH_SIZE];

    while (1) {
        uint pos = paragraph(buf);
        buf[pos] = '\0';
        printf("%s", buf);
    }
}
