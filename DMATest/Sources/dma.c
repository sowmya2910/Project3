/*
 * dma.c
 *
 *  Created on: 03-Dec-2017
 *      Author: Meow
 */

/**
 * @file main.c
 * @brief This file consists of the functions to be used for DMA operations
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date December 3, 2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include "DMA.h"

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
* @brief DMA_configure()
* This function configures the DMA to the given settings
* @return nothing
***********************************************************************/

void DMA_configure(void)
{
			SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;         		//Clock is enabled to DMAmux
			SIM_SCGC7 |= SIM_SCGC7_DMA_MASK; 					//Clock is enabled to DMA
			DMAMUX0_CHCFG0 = 0x00;			                    // DMA MUX channel is disabled
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;              // Clearing Done mask

}

/******************************************************************//****
* @brief memmove_dma_one_byte()
* This function moves 1 byte from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_one_byte( void * src, void * dst, uint32_t DMASize)
{
			DMA_configure(); //DMA configure function is called
			DMA_SAR0 = (uint32_t)src; //Source address is set
			if(DMASize % DMA_ONE == DMA_ZERO) //Checking if remainder of size divided by 1 is zero
			{
				DMA_DSR_BCR0 |= DMASize;					// Setting the data transfer size
				/* Initializing DMA */
				DMA_DCR0 |= DMA_DCR_AA_MASK;                // Enabling Auto align mask //
				DMA_DCR0 |=	DMA_DCR_EINT_MASK;				// Enabling interrupt after successful operation //
				DMA_DCR0 |=	DMA_DCR_SSIZE(1);			    // Setting source size to 8 bits //
				DMA_DCR0 |=	DMA_DCR_DSIZE(1);				// Setting destination size to 8 bits //
				DMA_DCR0 |=	DMA_DCR_SINC_MASK;              // Source Address increments after successful operation //
				DMA_DCR0 |=	DMA_DCR_DINC_MASK;              // Destination address increments //
				DMA_DAR0 = (uint32_t)dst;
				DMA_DCR0 |= DMA_DCR_EINT_MASK;				// Enable DMA Interrupt
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;	// Enabling the  DMA Channel source //
				DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);	// Selecting DMA Channel //
				DMA_DCR0 |= DMA_DCR_START_MASK;             // Starting DMA transfer //
			}
}

/******************************************************************//****
* @brief memmove_dma_two_byte()
* This function moves 2 bytes from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_two_byte( void * src, void * dst, uint32_t DMASize)
{
			    DMA_configure(); //DMA configure function is called
			    DMA_SAR0 = (uint32_t)src; //Source address is set
			    if(DMASize % DMA_TWO == DMA_ZERO) //Checking if remainder of size divided by 2 is zero
			    {
			    	DMA_DSR_BCR0 |= DMASize;			  // Setting the data transfer size
			    	/* Initializing DMA */
			    	DMA_DCR0 |= DMA_DCR_AA_MASK;          // Enabling Auto align mask //
			    	DMA_DCR0 |=	DMA_DCR_EINT_MASK;		  //  Enabling interrupt after successful operation //
			    	DMA_DCR0 |=	DMA_DCR_SSIZE(2);		  // Setting source size to 16 bits //
			    	DMA_DCR0 |=	DMA_DCR_DSIZE(2);		  // Setting Destination size to 16 bits //
			    	DMA_DCR0 |=	DMA_DCR_SINC_MASK;        // Source Address increments after successful operation //
			    	DMA_DCR0 |=	DMA_DCR_DINC_MASK;        // Destination address increments //
			    	DMA_DAR0 = (uint32_t)dst;
			    	DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;	 // Enabling the  DMA Channel source //
			    	DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);	 // Selecting DMA Channel //
			    	DMA_DCR0 |= DMA_DCR_START_MASK;              // Starting DMA transfer //
				}

}

/******************************************************************//****
* @brief memmove_dma_four_byte()
* This function moves 4 bytes from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_four_byte( void * src, void * dst, uint32_t DMASize)
{
			    DMA_configure(); //DMA configure function is called
			    DMA_SAR0 = (uint32_t)src;  //Source address is set
				if(DMASize % DMA_FOUR == DMA_ZERO)  //Checking if remainder of size divided by 4 is zero
				{
					DMA_DSR_BCR0 |= DMASize;			// Setting the data transfer size //
					/* Initializing DMA */
					DMA_DCR0 |= DMA_DCR_AA_MASK;        // Enabling Auto align mask //
					DMA_DCR0 |=	DMA_DCR_EINT_MASK;		//  Enabling interrupt after successful operation //
					DMA_DCR0 |=	DMA_DCR_SSIZE(0);		// Setting source size to 32 bits //
					DMA_DCR0 |=	DMA_DCR_DSIZE(0);		// Setting Destination size to 32 bits //
					DMA_DCR0 |=	DMA_DCR_SINC_MASK;      // Source Address increments after successful operation //
					DMA_DCR0 |=	DMA_DCR_DINC_MASK;      // Destination address increments //
					/* Initializing DMA */
					DMA_DAR0 = (uint32_t)dst;
					DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;	// Enabling the  DMA Channel source //
					DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);	// Selecting DMA Channel //
					DMA_DCR0 |= DMA_DCR_START_MASK;             // Starting DMA transfer //
				}
				else
				{	// If DMASize is not a multiple of 4 or 2 or an odd number */
					DMA_DSR_BCR0 |= DMASize - (DMASize % DMA_FOUR);	  // Setting the data transfer size //
					/* Initializing DMA */
					DMA_DCR0 |= DMA_DCR_AA_MASK;            // Enabling Auto aligned //
					DMA_DCR0 |=	DMA_DCR_EINT_MASK;			//  Enabling interrupt after successful operation //
					DMA_DCR0 |=	DMA_DCR_SSIZE(0);			// Setting source size to 32 bits //
					DMA_DCR0 |=	DMA_DCR_DSIZE(0);			// Setting Destination size to 32 bits //
					DMA_DCR0 |=	DMA_DCR_SINC_MASK;          // Source Address increments after successful operation //
					DMA_DCR0 |=	DMA_DCR_DINC_MASK;          // Destination address increments //
					DMA_DAR0 = (uint32_t)dst;
					DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		// Enabling the  DMA Channel source //
					DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		// Selecting DMA Channel //
					DMA_DCR0 |= DMA_DCR_START_MASK;                // Starting DMA transfer //
				}

}

/******************************************************************//****
* @brief memzero_dma_one_byte()
* This function moves 1 byte from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_one_byte( void * src, void * dst, uint32_t DMASize)
{
			   DMA_configure(); //DMA configure function is called
			   DMA_SAR0 = (uint32_t)src;   //Source address is set
			   if(DMASize % DMA_ONE == DMA_ZERO) //Checking if remainder of size divided by 1 is zero
			   {
				   DMA_DSR_BCR0 |= DMASize;		//Setting the data transfer size
				   /* Initializing DMA */
				   DMA_DCR0 |=    DMA_DCR_AA_MASK;              // Enabling Auto align mask //
				   DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			//  Enabling interrupt after successful operation //
				   DMA_DCR0 |=	   DMA_DCR_SSIZE(1);			// Setting source size to 8 bits //
				   DMA_DCR0 |=	   DMA_DCR_DSIZE(1);			// Setting Destination size to 8 bits //
				   DMA_DCR0 |=	   DMA_DCR_DINC_MASK;           // Destination address increments //
				   DMA_DAR0 = (uint32_t)dst;
				   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;	// Enabling the  DMA Channel source //
				   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);	// Selecting DMA Channel //
				   DMA_DCR0 |= DMA_DCR_START_MASK;              // Starting DMA transfer //
			   }

}

/******************************************************************//****
* @brief memzero_dma_two_byte()
* This function moves 2 bytes from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_two_byte( void * src, void * dst, uint32_t DMASize)
{
			   DMA_configure(); //DMA configure function is called
			   DMA_SAR0 = (uint32_t)src;   //Source address is set
	     	   if(DMASize % DMA_TWO == DMA_ZERO) //Checking if remainder of size divided by 2 is zero
	     	   {
	     		   DMA_DSR_BCR0 |= DMASize;			// Setting the data transfer size
	     		   /* Initializing DMA */
	     		   DMA_DCR0 |=    DMA_DCR_AA_MASK;        	// Enabling Auto align mask //
	     		   DMA_DCR0 |=	   DMA_DCR_EINT_MASK;		// Enabling interrupt after successful operation //
	     		   DMA_DCR0 |=	   DMA_DCR_SSIZE(2);		// Setting source size to 16 bits //
	     		   DMA_DCR0 |=	   DMA_DCR_DSIZE(2);		// Setting Destination size to 16 bits //
	     		   DMA_DCR0 |=	   DMA_DCR_DINC_MASK;       // Destination address increments //
	     		   DMA_DAR0 = (uint32_t)dst;
	     		   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		// Enabling the  DMA Channel source //
	     		   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		// Selecting DMA Channel //
	     		   DMA_DCR0 |= DMA_DCR_START_MASK;                  // Starting DMA transfer //
				}
}

/******************************************************************//****
* @brief memzero_dma_four_byte()
* This function moves 4 bytes from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_four_byte( void * src, void * dst, uint32_t DMASize)
{
			   DMA_configure(); //DMA configure function is called
			   DMA_SAR0 = (uint32_t)src;      //Source address is set
			   if(DMASize % DMA_FOUR == DMA_ZERO) //Checking if remainder of size divided by 4 is zero
			   {
				   DMA_DSR_BCR0 |= DMASize;				// Setting the data transfer size
				   /* Initializing DMA */
				   DMA_DCR0 |=    DMA_DCR_AA_MASK;           // Enabling Auto align mask //
				   DMA_DCR0 |=	   DMA_DCR_EINT_MASK;		 //  Enabling interrupt after successful operation //
				   DMA_DCR0 |=	   DMA_DCR_SSIZE(0);		 // Setting source size to 32 bits //
				   DMA_DCR0 |=	   DMA_DCR_DSIZE(0);		 // Setting Destination size to 32 bits //
				   DMA_DCR0 |=	   DMA_DCR_DINC_MASK;        // Destination address increments //
				   DMA_DAR0 = (uint32_t)dst;
				   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		// Enabling the  DMA Channel source //
				   DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);		// Selecting DMA Channel //
				   DMA_DCR0 |= DMA_DCR_START_MASK;                  // Starting DMA transfer //
			   }
			   else
			   {
				  DMA_DSR_BCR0 |= DMASize - (DMASize % DMA_FOUR);	// Setting the data transfer size //
				  /* Initializing DMA */
				  DMA_DCR0 |=    DMA_DCR_AA_MASK;               // Enabling Auto aligned //
				  DMA_DCR0 |=	   DMA_DCR_EINT_MASK;			//  Enabling interrupt after successful operation //
				  DMA_DCR0 |=	   DMA_DCR_SSIZE(0);			// Setting source size to 32 bits //
				  DMA_DCR0 |=	   DMA_DCR_DSIZE(0);			// Setting Destination size to 32 bits //
				  DMA_DCR0 |=	   DMA_DCR_DINC_MASK;           // Destination address increments //
				  DMA_DAR0 = (uint32_t)dst;
				  DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;		// Enabling the  DMA Channel source //
				  DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_SOURCE(49);	// Selecting DMA Channel //
				  DMA_DCR0 |= DMA_DCR_START_MASK;               // Starting DMA transfer //
			   }

}

