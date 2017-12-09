/**
 * @file conversion.c
 * @brief This file contains functions which perform basic data manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 2, 2017
 *
 */

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
 * @brief my_itoa()
 * This function converts data from a standard integer type into an ASCII string
 * @data Data to be converted
 * @ptr Pointer which points to the resultant ASCII string
 * @base Integer value of the base to which conversion is to happen
 * @return Length of the converted data (including a negative sign)
 ***********************************************************************/
#include"conversion.h"
uint8_t my_itoa(int32_t data,uint8_t* ptr, uint32_t base)
{
	/* Initializing variables */
	int f=0;
	uint8_t len=1;
	uint8_t t;
	int8_t i=0,j=0;	
	/* Checking if data is NULL */		       
	if(data==0)
  	{
		/* Initializing to null and returning 0*/
    		*(ptr+len++)='0';
    		return 0;
  	}
	if (data<0) /* Checking if data is negative */
  	{
		/* Setting flag to 1 and changing sign */
   		f=1;
   		data = -1*data;
  	}
	while(data!=0) /* Checking if data is not zero (zero conditions) */
  	{
		/* Calculating remainder */
   		uint32_t remainder=data % base;
		/* Checking remainder and changing pointer value */
   		if(remainder>9)
    		{
      			*(ptr+len++)=(remainder-10)+'a';
     		}
   		else
     		{
      			*(ptr+len++)= remainder+'0';
     		}
		/* Dividing data by base */
 		data = data/base;
  	}
	if(f==1) /* Checking if flag is 1 */
  	{
		/* Appending with - */
   		*(ptr+len++)='-'; 
  	}
	/* Initializing i and j */
	i=len-1;
	j=0;
	/* Check if start of ptr is less than its length */
 	while(j <i)				
       	{
		/* Swap operation */
         	t= *(ptr+j);
         	*(ptr+j) = *(ptr+i);
         	*(ptr+i)=t;
		/* Increment j and decement i */
         	j++;
         	i--;
       	}
	/* Append last character to null*/
	*(ptr+len)='\0';
	printf("%s\n",ptr);
	/* Return length */
	return len;
}

/******************************************************************//****
 * @brief my_atoi()
 * This function converts data from an ASCII string into an integer type
 * @ptr Pointer which points to the character string to convert
 * @digits Number of digits in the character set
 * @base Integer value of the base
 * @return Converted 32 bit signed integer
 ***********************************************************************/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
	/* Initializing variables */
	int f;
	int i=0,j=0;
	int32_t val=0;
	int32_t count=0;
	int32_t final=0;
	/* Checking if ASCII value is negative */
	if(*ptr == '-')
	{
		i++;
		j++;
		count++;
		/* Initializing flag to 1 */
		f=1;
	}
	/* Checking if base is 10 */
	if(base==10)
	{
		/* Conversion */
		while(i<digits-1)
  		{
			final= final*10+*(ptr+i)-'0';
			i++;
  		}
	}
	/* Checking if base is 2 */
	if(base==2)
	{
		/* Conversion */
		while(i<digits-1)
  		{
   			final = final + *(ptr+i) * (2^(digits-2-i));
   			i++;
  		}
	}
	/* Checking if base is 16 */
	if(base==16)
	{
		/* Conversion */
		while(i<digits-1) 
  		{
  			if((*(ptr+i)-'0')>9)
   			{
   				val = *(ptr+i)-'a'+10;
   
   			}
  			else
  			{
  				val=*(ptr+i);
  				val = val - '0';
  			}  
			i++;
			final =final*16+val;
		}
	}
	/* Checking if flag is 1 */
	if(f==1)
	{
		/* Changing sign of final value */
		final= -1*final;
	}
	/* Return final converted value */
	return final;
}



/******************************************************************//****
 * @brief big_to_little32()
 * This function converts an array of data in memory from big endian
 * representation to little endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t big_to_value32(uint32_t *data,uint32_t length)
{
    uint32_t value;
    if(length!=0)
    {
	/*The conversion is done from big to little endian */
    	value=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
	/* Length is decremented and data is incremented */
        length--;
        data++;
    }
    else
    {
    	return 0;
    }
return value;
}

/******************************************************************//****
 * @brief little_to_big32()
 * This function converts an array of data in memory from little endian
 * representation to big endian
 * @data Memory location of data
 * @length Length of memory
 * @return If the conversion fails for any reason, an error is returned
 ***********************************************************************/
int8_t little_to_big32(uint32_t *data,uint32_t length)
{
    	uint32_t value;
    	if(length!=0)
	{
		/* The conversion is done from little to big endian */
        	value=((*data &0X000000FF)<<24)|((*data &0X0000FF00)<<8)|((*data &0X00FF0000)>>8)|((*data &0XFF000000)>>24);
		/* Length is decremented and data is incremented */
        	length--;
        	data++;
    	}
        else
        {
    		return 0;
        }
	return value;
}
