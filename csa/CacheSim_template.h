/**
 * CacheSim.h
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
**/
#ifndef CACHESIM_H_INCLUDED
#define CACHESIM_H_INCLUDED

/* Please adjust parameters here */
#define LOGC 3
#define OFFSETLEN 2
#define CACHE_SIZE 1024*(1<<LOGC)
#define BLOCK_SIZE 1<<OFFSETLEN
#define INDEX_SIZE CACHE_SIZE/BLOCK_SIZE
#define INDEXLEN 10+LOGC-OFFSETLEN
#define TAGLEN 32-INDEXLEN-OFFSETLEN
typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache{
    bool valid;
    bool dirty;
    unsigned long tag;
	Byte data[BLOCK_SIZE];
};

#endif // CACHESIM_H_INCLUDED