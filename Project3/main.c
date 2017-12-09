#include "MKL25Z4.h"
#include "DMA.h"
static int i = 0;

int main(void)
{
	/* Testing DMA memove and memzero */
	uint8_t  string1[120]={1,2,3,4,5,6,7,8,9,10};
	uint8_t string2[120]={1,2,3,4,5,6,7,8,9,10};
	int8_t a =0;
	uint8_t *src = &a;
	uint8_t *src1 = string1;
	uint8_t *dst = string2;

	configure_timer1();
	uart0_config();							/*  Configuring UART */
	start_timer1();                         /* Starting Timer */
	__enable_irq();
	memzero_dma_four_byte(src,dst,10);     /* memzero dma two dma transfer called */
	stop_timer1();						   /* Stopping timer and calculating time */

	start_timer1();						   /* Starting Timer */
	__enable_irq();
	memove_dma_four_byte(src1,dst,10);     /* memove dma two byte transfer called */
	stop_timer1();                         /* stopping timer */

	 //profiler_FRDM_DMA_memmove_one_byte();

	 // profiler_FRDM_STD_LIB_memzero();

	 // profiler_FRDM_STD_LIB_MEMOVE();

     //	 profiler_FRDM_non_DMA_memzero();

	 // profiler_FRDM_NON_DMA_memove();


    /* This for loop should be replaced. By default this loop allows a single stepping. */
    for (;;) {
        i++;
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////