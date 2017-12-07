/*
 * uart.h
 *
 *  Created on: 03-Dec-2017
 *      Author: Meow
 */

/**
* @file uart.h
* @brief An abstraction for functions containing UART manipulation operations
*
* This header file provides an abstraction of manipulating data in UART
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date December 3, 2017
*
*/

#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_

//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"

//***********************************************************************************
// Macros
//***********************************************************************************

#define TXBUF_LENGTH 500
#define RXBUF_LENGTH 16
#define OVER_SAMPLING_RATIO 16
#define BAUD_RATE 57600
#define UART_NUM_ZERO (0)
#define UART_NUM_ONE (1)
#define UART_NUM_TWO (2)
#define UART_NUM_EIGHT (8)

//***********************************************************************************
// Enum
//***********************************************************************************

typedef enum {
	eUART_SUCCESS,
	eUART_FAILURE
}UART_e;

//***********************************************************************************
// Function prototype
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure();

#endif /* SOURCES_UART_H_ */
