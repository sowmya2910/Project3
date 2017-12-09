/*
 * dma.h
 *
 *  Created on: 03-Dec-2017
 *      Author: Meow
 */

/**
* @file dma.h
* @brief An abstraction for functions containing DMA memmove and memzero operations
*
* This header file provides an abstraction of memmove and memzero using DMA
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date December 3, 2017
*
*/

#ifndef SOURCES_DMA_H_
#define SOURCES_DMA_H_

//***********************************************************************************
// Include files
//***********************************************************************************

#include "MKL25Z4.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//***********************************************************************************
// Macros
//***********************************************************************************

#define DMA_ZERO 0
#define DMA_ONE 1
#define DMA_TWO 2
#define DMA_FOUR 4

//***********************************************************************************
// Function prototypes
//***********************************************************************************

/******************************************************************//****
* @brief DMA_configure()
* This function configures the DMA to the given settings
* @return nothing
***********************************************************************/

void DMA_configure();

/******************************************************************//****
* @brief memmove_dma_one_byte()
* This function moves 1 byte from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_one_byte( void * src, void * dst, uint32_t DMASize);

/******************************************************************//****
* @brief memmove_dma_two_byte()
* This function moves 2 bytes from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_two_byte( void * src, void * dst, uint32_t DMASize);

/******************************************************************//****
* @brief memmove_dma_four_byte()
* This function moves 4 bytes from src to dst using DMA
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memmove_dma_four_byte( void * src, void * dst, uint32_t DMASize);

/******************************************************************//****
* @brief memzero_dma_one_byte()
* This function moves 1 byte from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_one_byte( void * src, void * dst, uint32_t DMASize);

/******************************************************************//****
* @brief memzero_dma_two_byte()
* This function moves 2 bytes from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_two_byte( void * src, void * dst, uint32_t DMASize);

/******************************************************************//****
* @brief memzero_dma_four_byte()
* This function moves 4 bytes from src to dst using DMA (makes value 0)
* @src Source bytes of data
* @dst Destination bytes of data
* @DMASize Number of bytes to transfer
* @return Nothing
***********************************************************************/

void memzero_dma_four_byte( void * src, void * dst, uint32_t DMASize);

#endif /* SOURCES_DMA_H_ */
