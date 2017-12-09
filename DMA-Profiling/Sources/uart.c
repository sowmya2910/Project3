/*
 * uart.c
 *
 *  Created on: 04-Dec-2017
 *      Author: Meow
 */

#include "UART.h"



void uart0_config(){

	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;                        /* Enabling clock for PORTA module */

	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;												/* Enabling clock gate for UART0 */

	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(UART_NUM_ONE);						/* Selecting clock source for UART0 either MCGFLLCLK clock or MCGPLLCLK/2 clock */


	PORTA_PCR1 = PORT_PCR_MUX(UART_NUM_TWO);									/* Setting MUX to Alternative 2 to enable UART0 */
	PORTA_PCR2 = PORT_PCR_MUX(UART_NUM_TWO);

	UART0_C1 = UART_NUM_ZERO;																	/* Setting 8 bit data and disabling parity for UART0 */

	UART0_C2 = UART_NUM_ZERO;																	/* Setting 8 bit data and disabling parity for UART0 */


	uint16_t baud = (uint16_t) (DEFAULT_SYSTEM_CLOCK/(BAUD_RATE*OVER_SAMPLING_RATIO));			/* Baud rate calculation */

	UART0_BDH |= (baud >> UART_NUM_EIGHT) & UART0_BDH_SBR_MASK;															/* Storing the SBR bits of 8 to 11 */
	UART0_BDL = (baud & UART0_BDL_SBR_MASK);																								/* Storing the SBR bits of 0 to 7 */

	UART0_C2 = (UART_C2_RIE_MASK | UART0_C2_RE_MASK | UART0_C2_TE_MASK);  /* Enabling Tx and Rx interrupt */


	NVIC_EnableIRQ(UART0_IRQn);																/* Set NVIC interrupts */
	NVIC_SetPriority(UART0_IRQn,UART_NUM_TWO);								/* Setting priority of UART0 */



}

inline UART_e uart_send_byte(uint8_t item) {

	if(item != NULL){
		while(!(UART0_S1 & UART_S1_TDRE_MASK));                /* loop till transmit data register is empty */
		UART0_D = item;																			 /* Sending the data */
		return eUART_SUCCESS;
	}
	else{
		return eUART_FAILURE;
	}
	printf("\n");
}

inline UART_e uart_send_n_bytes(uint8_t* item, uint32_t length) {

	if(item != NULL && length >UART_NUM_ZERO){
		uint32_t counter ;																		/* loop for the length of the n byte sequence */
		for(counter = UART_NUM_ZERO; counter < length; counter++){
			uart_send_byte(*item);
			item++;
		}
		return eUART_SUCCESS;
	}
	else{
		return eUART_FAILURE;
	}
}

inline UART_e uart_receive_byte(uint8_t *ptr) {


		while(!(UART0_S1 & UART_S1_RDRF_MASK));                 /* loop till the  receive buffer is full */
		*ptr = UART0_D;
		return eUART_SUCCESS;

}


