/*
 * profiler.h
 *
 *  Created on: 04-Dec-2017
 *      Author: Meow
 */

#ifndef SOURCES_PROFILER_H_
#define SOURCES_PROFILER_H_

//#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include "memory.h"

#define PROFILER_ZERO 0
#define TEN_BYTES 10
#define HUNDRED_BYTES 100
#define THOUSAND_BYTES 1000
#define FIVE_THOUSAND_BYTES 5000


double getTimeMoveMem_std(uint8_t * destination, uint8_t  * source, uint32_t num);

double getTimeMoveSet_std(uint8_t * source, uint32_t num);

void profiler_BBB_std_library_memmove(void);

void profiler_BBB_std_library_memzero(void);

double getTimeMoveMem(uint8_t * destination, uint8_t * source, uint32_t num);

void profiler_BBB_non_DMA_memmove(void);

void profiler_BBB_non_DMA_memset(void);


#endif
