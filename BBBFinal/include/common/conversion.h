/**
* @file conversion.h
* @brief An abstraction for functions containing basic data manipulation operations
*
* This header file provides an abstraction of manipulating data via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 2, 2017
*
*/
#ifndef __CONVERSION_H__
#define __CONVERSION_H__
//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//***********************************************************************************
// function prototypes
//***********************************************************************************
/******************************************************************//****
 * @brief my_itoa()
 * This function converts data from a standard integer type into an ASCII string
 * @data Data to be converted
 * @ptr Pointer which points to the resultant ASCII string
 * @base Integer value of the base to which conversion is to happen
 * @return Length of the converted data (including a negative sign)
 ***********************************************************************/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/******************************************************************//****
 * @brief my_atoi()
 * This function converts data from an ASCII string into an integer type
 * @ptr Pointer which points to the character string to convert
 * @digits Number of digits in the character set
 * @base Integer value of the base
 * @return Converted 32 bit signed integer
 ***********************************************************************/
int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base);

/******************************************************************//****
 * @brief big_to_little32()
 * This function converts an array of data in memory from big endian
 * representation to little endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t big_to_little32(uint32_t* data, uint32_t length);

/******************************************************************//****
 * @brief little_to_big32()
 * This function converts an array of data in memory from little endian
 * representation to big endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t little_to_big32(uint32_t* data, uint32_t length);

#endif /* __CONVERSION_H__ */
