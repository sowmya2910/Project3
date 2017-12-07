/*
 * uart.c
 *
 *  Created on: 03-Dec-2017
 *      Author: Meow
 */

/**
* @file uart.c
* @brief This file contains functions which perform UART operations
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date December 3, 2017
*
*/

//***********************************************************************************
//Includes
//***********************************************************************************

#include "UART.h"

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;                      // Enabling clock for PORTA module //
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;						// Enabling clock gate for UART0 //
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(UART_NUM_ONE);			// Selecting clock source for UART0 either MCGFLLCLK clock or MCGPLLCLK/2 clock //
	PORTA_PCR1 = PORT_PCR_MUX(UART_NUM_TWO);				// Setting MUX to Alternative 2 to enable UART0 //
	PORTA_PCR2 = PORT_PCR_MUX(UART_NUM_TWO);
	UART0_C1 = UART_NUM_ZERO;								// Setting 8 bit data and disabling parity for UART0 //
	UART0_C2 = UART_NUM_ZERO;								// Setting 8 bit data and disabling parity for UART0 //
	uint16_t baud = (uint16_t) (DEFAULT_SYSTEM_CLOCK/(BAUD_RATE*OVER_SAMPLING_RATIO));			// Baud rate calculation //
	UART0_BDH |= (baud >> UART_NUM_EIGHT) & UART0_BDH_SBR_MASK;									// Storing the SBR bits of 8 to 11 //
	UART0_BDL = (baud & UART0_BDL_SBR_MASK);				// Storing the SBR bits of 0 to 7 //
	UART0_C2 = (UART_C2_RIE_MASK | UART0_C2_RE_MASK | UART0_C2_TE_MASK);  // Enabling Tx and Rx interrupts //
	NVIC_EnableIRQ(UART0_IRQn);											  // Set NVIC interrupts //
	NVIC_SetPriority(UART0_IRQn,UART_NUM_TWO);							  // Setting priority of UART0 //
}

