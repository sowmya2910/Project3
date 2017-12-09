/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file project1_test.c
 * @brief This file is to be used to project 1.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "platform.h"
#include "project1.h"
#include "memory.h"
#include"memoryopt.h"
#include "conversion.h"
#include "debug.h"
#include "profiler_BBB.h"
#define BASE_16 16
#define BASE_10 10


void project1()
{
  profiler_BBB_std_library_memmove();
  profiler_BBB_std_library_memset();
  profiler_BBB_non_DMA_memmove();
  profiler_BBB_non_DMA_memset();
  profiler_BBB_non_DMA_opt_memmove();
  profiler_BBB_non_DMA_OPT_memset();
  
}
