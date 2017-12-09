/*
 * memoryopt.h
 *
 *  Created on: 05-Dec-2017
 *      Author: Meow
 */

#ifndef SOURCES_MEMORYOPT_H_
#define SOURCES_MEMORYOPT_H_

/* Defining  macros */

#define MEMORY_NUM_ZERO (0)
#define MEMORY_NUM_ONE (1)
#define MEMORY_NUM_TWO (2)
#define MEMORY_ERROR_NEGATIVEONE (-1)

/**********************************************************************
* my_memmove
* Function copies characters of length l from src to dst and also checks for overlapping.
* @param src : Source location pointer
* @param dst : Destination location pointer
* @param length: length of bytes
************************************************************************/
uint8_t my_opt_memmove(uint8_t * src, uint8_t * dst, uint32_t length)__attribute__((optimize(3)));

/*********************************************************************
* my_memset
* Function copies value to the first length(number) characters of the string pointed by src.
* @param src : Source location pointer
* @param length : Number of bytes to which the value to be set.
* @param value:  The value to be set to the string pointed by src.
**********************************************************************/
uint8_t my_opt_memset(uint8_t * src, uint32_t length, uint8_t value)__attribute__((optimize(3)));

/*********************************************************************
* my_memzero
* Function sets value zero to the first length(number) characters of the string pointed by src.
* @param src : Source location pointer
* @param length : Number of bytes to which the value zero to be set.
**********************************************************************/

uint8_t my_opt_memzero(uint8_t * src, uint32_t length)__attribute__((optimize(3)));

/**********************************************************************
* my_reverse
* Function takes the source pointer to a memory location and length of the bytes is given. It reverses the array.
  Inputs are the source pointer which points to array and the length of bytes to be reversed.
* @param src : Source location pointer
* @param length : Number of bytes to reverse.
***********************************************************************/

uint8_t  my_opt_reverse(uint8_t * src, uint32_t length)__attribute__((optimize(3)));

#endif

