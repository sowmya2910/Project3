/**
* @file platform.h
* @brief An abstraction for disabling printf() in KL25z
*
* This header file provides an abstraction for disabling printf() in KL25z
*
* @author Sowmya Ramakrishnan,Vinayak Srivatsan Kovalam Mohan
* @date October 2, 2017
*
*/
#ifndef __platform_H__
#define __platform_H__
//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

//***********************************************************************************
// function prototypes
//***********************************************************************************
/******************************************************************//****
 * @brief printf()
 * This function is used for printing nothing and disabling the function
 ***********************************************************************/
#ifdef PLATFORM_KL25Z

printf(NULL);

#endif
#endif
