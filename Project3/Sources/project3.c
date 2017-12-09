/*
 * project3.c
 *
 *  Created on: 08-Dec-2017
 *      Author: Meow
 */

#include "fsl_device_registers.h"
#include "MKL25Z4.h"
#include "spi.h"
#include "nordic.h"
#include "gpio.h"
#include<stdio.h>
#include<stdint.h>
#include"rtc.h"
#include"circbuf.h"
#include"log.h"
#include"analysis.h"
#include"uart.h""
void main(){
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
			nrf_write_config(0x02);
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
}
#define FRDM

#define NUM_CHAR_RECV 16

b_logger *log;

	CB_e error_code;

	uint8_t char_recv[NUM_CHAR_RECV];
	uint8_t data;
	analysis_t *analysis;
 	char error_message1[100] = "Malloc failed";

	log_initialize();

	log = (b_logger*)malloc(sizeof(b_logger));
	//create_log_item(&log,LOGGER_INITIALIZED,0,0);
	//log_item(&log);

	b_logger *log2 = NULL;

/*	if(log2 == NULL){
		//create_log_item(&log,LOG_ERROR,strlen(error_message1),&error_message1);
		//log_item(&log,1);
		LOG_ITEM(log, LOG_ERROR, strlen(error_message1), &error_message1, 1);
	}*/
	LOG_ITEM(log, LOGGER_INITIALIZED, 0, 0, 0 );

	//clock_config();
	rtc_init();

	while(1)
	{

	}

	//create_log_item(&log,GPIO_INITIALIZED,0,0);
	//log_item(&log);
	LOG_ITEM(log, GPIO_INITIALIZED, 0, 0, 0);

	//log = (b_logger*)malloc(sizeof(b_logger));
	//create_log_item(&log,SYSTEM_INITIALIZED,0,0);
	//log_item(&log);
	LOG_ITEM(log, SYSTEM_INITIALIZED, 0, 0, 0);


	while(1){

		/*if (interrupt){
					LOG_RAW_INTR(seconds);
					interrupt = 0;
				}*/

		error_code = CB_IsBufferEmpty(&rx_buf);
		if(error_code==CB_Not_Empty && rx_buf.count == NUM_CHAR_RECV){

			analysis = (analysis_t *)malloc(sizeof(analysis_t));
			analyze_bytes(&rx_buf, analysis, NUM_CHAR_RECV);

			LOG_ITEM(log, DATA_ANALYSIS_STARTED, 0, 0, 0);

			for(uint8_t i=0; i<16; i++){
				data = CB_RemoveItem(&rx_buf);
				char_recv[i] = data;
			}

			//create_log_item(&log,DATA_RECEIVED,16,&char_recv);
			//log_item(&log);
			LOG_ITEM(log, DATA_RECEIVED, NUM_CHAR_RECV, &char_recv, 1);

			//create_log_item(&log,DATA_ALPHA_COUNT,1,&analysis->alpha);
			//log_item(&log);
			LOG_ITEM(log, DATA_ALPHA_COUNT, 1, &analysis->alpha, 0);

			//create_log_item(&log,DATA_NUMERIC_COUNT,1,&analysis->num);
			//log_item(&log);
			LOG_ITEM(log, DATA_NUMERIC_COUNT, 1, &analysis->num, 0);

			//create_log_item(&log,DATA_PUNCTUATION_COUNT,1,&analysis->punc);
			//log_item(&log);
			LOG_ITEM(log, DATA_PUNCTUATION_COUNT, 1, &analysis->punc, 0);

			//create_log_item(&log,DATA_MISC_COUNT,1,&analysis->misc);
			//log_item(&log);
			LOG_ITEM(log, DATA_MISC_COUNT, 1, &analysis->misc, 0);

			//create_log_item(&log,DATA_ANALYSIS_COMPLETED,0,0);
			//log_item(&log,0);
			LOG_ITEM(log, DATA_ANALYSIS_COMPLETED, 0, 0, 0);
		}
	}

	destroy_log_item(&log);

    /* This for loop should be replaced. By default this loop allows a single stepping. */
	// for (;;) {
    // uart_send_byte('P');
    // x = uart_receive_byte();
    // uart_send_byte(x);
	//}
    return 0;
}

void RTC_Seconds_IRQHandler()
{
	START_CRITICAL();
	uint32_t time = RTC_TSR;
	uint8_t log;
	LOG_ITEM(log, HEARTBEAT, 1, &time, 0);
	time_calc();
	LOG_RAW_STRING(" Date: ");
	LOG_RAW_INTR(myrtc.day);
	LOG_RAW_STRING("/");
	LOG_RAW_INTR(myrtc.month);
	LOG_RAW_STRING("/");
	LOG_RAW_INTR(myrtc.year);
	LOG_RAW_STRING(" Time: ");
	LOG_RAW_INTR(myrtc.hours);
	LOG_RAW_STRING(":");
	LOG_RAW_INTR(myrtc.minutes);
	LOG_RAW_STRING(":");
	LOG_RAW_INTR(myrtc.seconds);
	STOP_CRITICAL();
}

uint8_t i;
	/* Testing DMA memmove and memzero */
	uint8_t string1[10]={1,2,3,4,5,6,7,8,9,10};
	uint8_t string2[7]={'A','B','C','D','E','F','G'};
	uint8_t a=0;
	uint8_t *src = &a;
	uint8_t *src1 = string1;
	uint8_t *dst = string2;
	UART_configure();					//  Configuring UART //

	//memmove_dma_one_byte(src1,dst,1);  // Memmove DMA one byte transfer  //
	//memmove_dma_two_byte(src1,dst,2);  // Memmove DMA two byte transfer  //
	//memmove_dma_four_byte(src1,dst,4); // Memmove DMA four byte transfer //

	//__enable_irq();					// Enabling interrupt //
	//memzero_dma_one_byte(src,dst,1);  // Memzero DMA one byte transfer  //
	//memzero_dma_two_byte(src,dst,2);  // Memzero DMA two byte transfer  //
	//memzero_dma_four_byte(src,dst,4); // Memzero DMA four byte transfer //

    /* This for loop should be replaced. By default this loop allows a single stepping. */
	}
	}
