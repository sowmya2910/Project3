/*
 * data.c
 *
 *  Created on: 04-Dec-2017
 *      Author: Meow
 */

#include  <stdio.h>
#include  <math.h>
#include <stdio.h>                            /* Including header files */
#include <stdint.h>
#include <stdlib.h>


#include <stdbool.h>
#include "data.h"
#include "memory.h"

typedef union {
long	L;
float	F;
}	LF_t;

#define PRINT_FREEDOM

#ifdef PRINT_FREEDOM
#define print(...)
#endif

/* Definition of my_itoa function */

int8_t * my_itoa(int8_t * str,int32_t data,int32_t base)
{
	if((NULL != str) && (base>DATA_NUM_ZERO))       /* Check for NULL pointer and base >0 */
	{
		bool negativeSignBit = false;           /* Initializing variables one for counter and the other for check for negative input data */
		int8_t increment =DATA_NUM_ZERO;

		if(data == DATA_NUM_ZERO)              	/* Check for input data is zero. If zero returning ascii value of character '0' */
		{
			*str = '0';
			str++;
			increment++;
		}

		if(data <DATA_NUM_ZERO && base==DATA_NUM_TEN)
                                                                /* Check for input data is negative. Making negativeSignBit to true
		                                                    and converting data to positive */
		{
			negativeSignBit = true;
			data = -data;
		}
		                                                /* Check for input data is greater than zero */
		if(data>DATA_NUM_ZERO)
		{
			                                         /* Loop untill the data becomes zero */
			                                         /* Logic for itoa:Converting input integer to ascii value by adding ascii character    '0' to each digit in the input number, to convert input to ascii character */
			while(data != DATA_NUM_ZERO)
			{

				uint8_t remainder = data % base;
				                                 /* For base hexamdecimal, remainder is greater than nine. For lower bases,
				                                    remainder will be lower than nine */
				if(remainder>DATA_NUM_NINE)
				{
					*str = (remainder-DATA_NUM_TEN) + 'a';
				}
				else
				{
					*str = remainder + '0';
				}
				if(base != DATA_NUM_ZERO)
				{
					data = data/base;
				}
				str++;
				increment++;
			}
		}
		                                                /* If input data is negative. adding ascii character '-' at the end of the string */
		if(negativeSignBit == true)
		{
			*str = '-';
			str++;
			increment++;
		}
		*str = '\0';
		                                            /* Calling my_reverse function of 'memory.h' to reverse the character array pointer by pointer str */
		my_reverse((uint8_t *)(str-increment),(uint32_t)increment);
		return str;
	}
	else
	{
		                                            /* Returning -1 for error cases */
		return DATA_NUM_ZERO;
	}
}

/*Definition of my_atoi function*/

int32_t my_atoi(int8_t * str)
{
	                                                   /* Check for NULL pointer */
	if(str != NULL)
	{
		                                          /* Initializing variables one for checking negative input data and the other for sum */
		int32_t sum = DATA_NUM_ZERO;
		int8_t signBit	= DATA_NUM_ONE;
		if(*str == '-')
		{
			signBit = DATA_NUM_NEGATIVEONE;
			str++;
		}
		                                         /* Loop untill the string terminates by null charater */
		                                         /* Logic for atoi:Converting input ascii value to integer by subtracting the ascii value '0'
		                                          from input ascii value pointed by *str and left shifting towards MSB */
		while(*str != '\0')
		{
			                                 /* check for if any character alphabet is present in the given input */
			                                 /* if there is any charcter alphabet in the input then returning error case */
			if(*str < '0' || *str > '9')
			{
				return DATA_ERROR_VALUE;
			}
			else
			{
				sum = ((sum<<DATA_NUM_THREE)+(sum<<DATA_NUM_ONE)) + ((*str)-'0');
				str++;
			}
		}
		return signBit*sum;
	}
	else
	{
		/* Returning -1 for error cases */
		return DATA_ERROR_VALUE;
	}
}

/*Definition of big_to_little32 function*/

int8_t big_to_little32(uint32_t * data, uint32_t length)
{
	                                                         /* Check for NULL pointer and length >0 */
	if((data!=NULL) && (length>DATA_NUM_ZERO))
	{

		                                                 /* Declaring ptr pointer variabe for input data */
		uint8_t *ptr;
		ptr = (uint8_t *)data;
		uint32_t temp;
		                                                /* Loop untill the given input length*/
		                                               /* Logic for big_to_little32:Swapping the numbers so that the MSB wil be stored in lower address byte and LSB will be stored in higher address byte  */
		                                                 /* Byte 4 swapped with Byte 1, and Byte 2 is swapped with Byte 3 */
		for(uint8_t index=DATA_NUM_ZERO;index<length;index++)
		{

			temp = *ptr;
			*ptr=*(ptr+DATA_NUM_THREE);
			*(ptr+DATA_NUM_THREE) = temp;
			temp =*(ptr+DATA_NUM_ONE);
			*(ptr+DATA_NUM_ONE) = *(ptr+DATA_NUM_TWO);
			*(ptr+DATA_NUM_TWO) = temp;
			ptr = ptr+DATA_NUM_FOUR;
		}
		return DATA_NUM_ZERO;
	}
	else
	{
		                                               /* Returning -1 for error cases */
		return DATA_ERROR_VALUE;
	}
}

/*Definition of little_to_big32 function*/

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	                                                       /* Check for NULL pointer and length >0 */
	if((data!=NULL) && (length>DATA_NUM_ZERO))
	{
		                                                 /* Declaring ptr pointer variabe for input data */
		uint8_t *ptr;
		ptr = (uint8_t *)data;
		uint32_t temp;
		                                                 /* Loop untill the given input length*/
		                                                /* Logic for big_to_little32:Swapping the numbers so that the LSB wil be stored in lower address byte and MSB will be stored in higher address byte */
		for(uint8_t index=DATA_NUM_ZERO;index<length;index++)
		{
			temp = *ptr;
			*ptr=*(ptr+DATA_NUM_THREE);
			*(ptr+DATA_NUM_THREE) = temp;
			temp =*(ptr+DATA_NUM_ONE);
			*(ptr+DATA_NUM_ONE) = *(ptr+DATA_NUM_TWO);
			*(ptr+DATA_NUM_TWO) = temp;
			ptr = ptr+DATA_NUM_FOUR;
		}
		return DATA_NUM_ZERO;
	}
	else
	{
		/* Returning -1 for error cases */
		return DATA_ERROR_VALUE;
	}
}
