#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "CacheSim1.h"

long HIT;
long MISS;
int cacheSize;
int blockSize;
int associativity;
int setCount;
int offsetLen;
int indexLen;
char replacementPolicy[10];
CacheSet* cache;

int log2_int(int x) {
    int r = 0;
    while (x >>= 1) r++;
    return r;
}

int init(int cSize, int bSize, int assoc, const char* policy) {
    srand(time(NULL)); // For RR
    cacheSize = cSize;
    blockSize = bSize;
    associativity = assoc;
    strcpy(replacementPolicy, policy);

    offsetLen = log2_int(blockSize);
    setCount = cacheSize / (blockSize * associativity);
    indexLen = log2_int(setCount);

    HIT = 0;
    MISS = 0;

    cache = malloc(sizeof(CacheSet) * setCount);
    for (int i = 0; i < setCount; ++i) {
        cache[i].lines = malloc(sizeof(CacheLine) * associativity);
        for (int j = 0; j < associativity; ++j) {
            cache[i].lines[j].valid = 0;
            cache[i].lines[j].dirty = 0;
            cache[i].lines[j].tag = 0;
            cache[i].lines[j].age = 0;
            cache[i].lines[j].data = malloc(blockSize);
        }
    }
    return 0;
}

int calAddr(unsigned long addr, unsigned long* tag, unsigned long* setIdx, unsigned long* offset) {
    *tag = addr >> (offsetLen + indexLen);
    *setIdx = (addr >> offsetLen) & ((1 << indexLen) - 1);
    *offset = addr & ((1 << offsetLen) - 1);
    return 0;
}

int access(unsigned long addr) {
    unsigned long tag, idx, offset;
    calAddr(addr, &tag, &idx, &offset);

    CacheSet* set = &cache[idx];

    // Check for hit
    for (int i = 0; i < associativity; i++) {
        if (set->lines[i].valid && set->lines[i].tag == tag) {
            HIT++;
            if (strcmp(replacementPolicy, "LRU") == 0) {
                set->lines[i].age = 0;
                for (int j = 0; j < associativity; j++) {
                    if (j != i && set->lines[j].valid) set->lines[j].age++;
                }
            }
            return 1;
        }
    }

    // Miss
    MISS++;

    // Find line to replace
    int victim = -1;

    // Try to find an invalid line first
    for (int i = 0; i < associativity; i++) {
        if (!set->lines[i].valid) {
            victim = i;
            break;
        }
    }

    if (victim == -1) {
        if (strcmp(replacementPolicy, "RR") == 0) {
            victim = rand() % associativity;
        } else { // LRU
            int maxAge = -1;
            for (int i = 0; i < associativity; i++) {
                if (set->lines[i].age > maxAge) {
                    maxAge = set->lines[i].age;
                    victim = i;
                }
            }
        }
    }

    // Replace victim
    set->lines[victim].valid = 1;
    set->lines[victim].tag = tag;
    set->lines[victim].age = 0;
    for (int j = 0; j < associativity; j++) {
        if (j != victim && set->lines[j].valid) set->lines[j].age++;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        fprintf(stderr, "Usage:\n\t%s trace_file cache_size block_size associativity policy(LRU|RR)\n", argv[0]);
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening file");
        return 1;
    }

    int cSize = atoi(argv[2])*1024;
    int bSize = atoi(argv[3]);
    int assoc = atoi(argv[4]);
    const char* policy = argv[5];

    init(cSize, bSize, assoc, policy);

    char buff[1025];
    unsigned long addr;

    while (fgets(buff, 1024, input)) {
        sscanf(buff, "0x%x", &addr);
        access(addr);
    }

    fclose(input);

    int total = HIT + MISS;
    printf("Cache Size: %dB | Block: %dB | Assoc: %d-way | Policy: %s\n", cSize, bSize, assoc, policy);
    printf("HIT : %7ld\nMISS: %7ld\nHit Rate : %.2f%%\n", HIT, MISS, 100.0 * HIT / total);

    // Free memory
    for (int i = 0; i < setCount; i++) {
        for (int j = 0; j < associativity; j++) {
            free(cache[i].lines[j].data);
        }
        free(cache[i].lines);
    }
    free(cache);

    return 0;
}