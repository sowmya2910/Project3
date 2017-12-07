/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file main.c
 * @brief This file consists of the main() function to be used for DMA
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date December 3, 2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include "MKL25Z4.h"
#include "DMA.h"
#include "uart.h"

//***********************************************************************************
//Function Definition
//***********************************************************************************

/******************************************************************//****
 * @brief function to perform DMA memmove and memzero operations
 * @return void
 ***********************************************************************/

int main(void)
{
	/* Testing DMA memmove and memzero */
	uint8_t string1[10]={1,2,3,4,5,6,7,8,9,10};
	uint8_t string2[7]={'A','B','C','D','E','F','G'};
	uint8_t a=0;
	uint8_t *src = &a;
	uint8_t *src1 = string1;
	uint8_t *dst = string2;
	UART_configure();					//  Configuring UART //
	__enable_irq();					// Enabling interrupt //
	//memmove_dma_one_byte(src1,dst,1);  // Memmove DMA one byte transfer  //
	//memmove_dma_two_byte(src1,dst,2);  // Memmove DMA two byte transfer  //
	//memmove_dma_four_byte(src1,dst,4); // Memmove DMA four byte transfer //

	__enable_irq();					// Enabling interrupt //
	//memzero_dma_one_byte(src,dst,1);  // Memzero DMA one byte transfer  //
	//memzero_dma_two_byte(src,dst,2);  // Memzero DMA two byte transfer  //
	//memzero_dma_four_byte(src,dst,4); // Memzero DMA four byte transfer //

}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
