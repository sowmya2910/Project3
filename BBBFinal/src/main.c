/**
 * @file main.c
 * @brief This file consists of the main() function to be used for project1.c
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 2, 2017
 *
 */

/******************************************************************//****
 * @brief function to call project1()
 * This function calls project1() function defined in project1.c
 * @return void
 ***********************************************************************/
#include<stdio.h>
#include<stdint.h>
#include"project1.h"
#include"profiler_BBB.h"
//extern uint32_t __BUFFER_START;
//uint8_t * ptr = (uint8_t*)&__BUFFER_START;
int main()
{
	
	project1();
	return 0;

	
}
