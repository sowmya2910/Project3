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

#include "fsl_device_registers.h"
#include "MKL25Z4.h"
#include "spi.h"
#include "nordic.h"
#include"gpio.h"
#include<stdio.h>
#include<stdint.h>

int main(void)
{
	uint8_t config;
	uint8_t *txaddress;
	uint8_t status;
	uint8_t rfch;
	uint8_t rfsetup;
	uint8_t fifostatus;
	uint8_t txaddr[5];
	SPI_init();
	while(1)
	{
		nrf_write_config(NRF_CONFIG_PRIM_RX | NRF_CONFIG_PWR_UP);
		config=nrf_read_config();
		status=nrf_read_status();
		nrf_write_rf_setup(0x06);
		rfsetup=nrf_read_rf_setup();
		nrf_write_rf_ch(0x02);
		rfch=nrf_read_rf_ch();
		fifostatus=nrf_read_fifo_status();
		nrf_write_TX_ADDR();
		txaddress=nrf_read_TX_ADDR();
		for(uint8_t i=0;i<5;i++)
		{
			txaddr[i]=*txaddress;
			txaddress++;
		}
	}
	return 0;

}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
