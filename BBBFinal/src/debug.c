/**
 * @file debug.c
 * @brief This file contains a function print_memory() to print memory in hex when compile time switch is enabled in the makefile.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 2, 2017
 *
 */

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
 * @brief print_memory()
 * This function takes a pointer to memory and prints hex output of bytes
 * @start Pointer variable pointing to the memory to be printed
 * @length Length of bytes to be printed
 * @return void
 ***********************************************************************/
#include"debug.h"
#ifdef VERBOSE
void print_memory(uint8_t* start,uint32_t length)
{
	uint32_t i;
	/* Check if length is not zero */
	while(length != 0)
	{
		/* Print each byte of memory in Hexadecimal */
		printf("The byte in hexadecimal %x \n ",*start);
		/* Increment start and decrement length */
		start++;
		length--;
	}
}
#else /* If VERBOSE is not defined */
void print_memory(uint8_t* start,uint32_t length)
	{
		/* Do NULL */
		printf("NULL");
		
	}
#endif
