#ifndef CACHESIM_H_INCLUDED
#define CACHESIM_H_INCLUDED

typedef unsigned char Byte;
typedef unsigned char bool;

typedef struct CacheLine {
    bool valid;
    bool dirty;
    unsigned long tag;
    int age; // For LRU
    Byte* data;
} CacheLine;

typedef struct CacheSet {
    CacheLine* lines;  // Dynamic array of lines per set
} CacheSet;

extern CacheSet* cache;
extern long HIT;
extern long MISS;
extern int cacheSize;
extern int blockSize;
extern int associativity;
extern int setCount;
extern int offsetLen;
extern int indexLen;
extern char replacementPolicy[10]; // "LRU" or "RR"

int init(int cSize, int bSize, int assoc, const char* policy);
int calAddr(unsigned long addr, unsigned long* tag, unsigned long* setIdx, unsigned long* offset);
int access(unsigned long addr);

#endif