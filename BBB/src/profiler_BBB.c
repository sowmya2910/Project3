/*
 * profiler_BBB.c
 *
 *  Created on: 07-Dec-2017
 *      Author: Meow
 */

#include "profiler_BBB.h"
#include "memoryopt.h"




/**********************************************************
*
* FUNCTION : getTimeMoveMem(void * destination, const void * source, size_t num)
* FUNCTION DESCRIPTION : This function is a profiler which is used to check the time taken for function memmove and mezero/memset
*
************************************************************/

double getTimeMoveMem_std(uint8_t * destination, uint8_t  * source, uint32_t num)
{
	struct  timeval st, et;
	gettimeofday(&st, NULL);
	memmove(destination, source, num);
	gettimeofday(&et, NULL);
	double value= (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
	return value;
}

/**********************************************************
*
* FUNCTION : profiler_BBB_std_library_memove()
* FUNCTION DESCRIPTION : This function profiles  standard library function memove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_BBB_std_library_memmove(void){

	printf("Standard Library MEMMOVE PROFILING \n ");

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
        double time_spent; double first, second;
	time_t start, stop;
	struct  timeval st, et;
	double time_elapsed;

	/*********************************** 10 Bytes MEMMOVE standard C library  function on BBB **************************************/


	time_elapsed = getTimeMoveMem_std(dst, src, TEN_BYTES);
	printf("Time spent for 10 bytes for std library memmove in seconds : %f\n",time_elapsed);


	/*********************************** 100 Bytes MEMMOVE standard C library  function on BBB **************************************/

	time_elapsed = getTimeMoveMem_std(dst1, src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes for std library memove in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMMOVE standard C library  function on BBB **************************************/


	time_elapsed = getTimeMoveMem_std(dst2, src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes for std library memove in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMMOVE standard C library  function on BBB **************************************/

	time_elapsed = getTimeMoveMem_std(dst3, src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes for std library memove in seconds : %f\n",time_elapsed);

}


/**********************************************************
*
* FUNCTION : profiler_BBB_std_library_memset()
* FUNCTION DESCRIPTION : This function profiles  standard library function memset for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

double getTimeMoveSet_std(uint8_t * source, uint32_t num)
{
	struct  timeval st, et;
	gettimeofday(&st, NULL);
	memset(source, 0, num);
	gettimeofday(&et, NULL);
	return (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
}




void profiler_BBB_std_library_memset(void){

	printf("Standard Library MEMSET PROFILING \n ");

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
	clock_t start, stop;
	double  time_spent;
	struct  timeval st, et;
	double time_elapsed;

	/*********************************** 10 Bytes MEMSET standard C library  function on BBB **************************************/
	time_elapsed = getTimeMoveSet_std(src, TEN_BYTES);
	printf("Time spent for 10 bytes for std libraray memset in seconds : %f\n",time_elapsed);

	/*********************************** 100 Bytes MEMSET standard C library  function on BBB **************************************/
	time_elapsed = getTimeMoveSet_std(src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes for std libraray memset in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMSET standard C library  function on BBB **************************************/

	time_elapsed = getTimeMoveSet_std(src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes for std libraray memset in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMSET standard C library  function on BBB **************************************/
	time_elapsed = getTimeMoveSet_std(src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes for std libraray memset in seconds : %f\n",time_elapsed);


}

/**********************************************************
*
* FUNCTION : getTimeMoveMem(void * destination, const void * source, size_t num)
* FUNCTION DESCRIPTION : This function is a profiler which is used to check the time taken for function memmove and mezero/memset
*
************************************************************/

double getTimeMoveMem(uint8_t * destination, uint8_t * source, uint32_t num)
{
	struct timeval st, et;
	gettimeofday(&st, NULL);
	my_memmove(source, destination, num);
	gettimeofday(&et, NULL);
	return (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
}

/**********************************************************
*
* FUNCTION : profiler_BBB_non_DMA_memmove()
* FUNCTION DESCRIPTION : This function profiles  non DMA function memmove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_BBB_non_DMA_memmove(void){

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
    double time_spent; double first, second;
	time_t start, stop;
	struct  timeval st, et;
	double time_elapsed;
	printf(" NON DMA MEMMOVE PROFILING \n ");
	/*********************************** 10 Bytes MEMMOVE non DMA  function on BBB **************************************/


	time_elapsed = getTimeMoveMem(dst, src, TEN_BYTES);
	printf("Time spent for 10 bytes of NON DMA memmove in seconds : %f\n",time_elapsed);


	/*********************************** 100 Bytes MEMMOVE non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveMem(dst1, src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes of non DMA memmove in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMMOVE non DMA  function on BBB **************************************/


	time_elapsed = getTimeMoveMem(dst2, src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes of non DMA memmove in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMMOVE non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveMem(dst3, src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes of non DMA memmove in seconds : %f\n",time_elapsed);

}


/**********************************************************
*
* FUNCTION : profiler_BBB_non_DMA_memset()
* FUNCTION DESCRIPTION : This function profiles  non DMA function memset for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

double getTimeMoveSet(uint8_t  * source, uint32_t num)
{
	struct  timeval st, et;
	gettimeofday(&st, NULL);
	my_memset(source, num, 0);
	gettimeofday(&et, NULL);
	return (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
}




void profiler_BBB_non_DMA_memset(void){

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
	clock_t start, stop;
	double  time_spent;
	struct  timeval st, et;
	double time_elapsed;

	printf(" NON DMA MEMSET PROFILING \n ");

	/*********************************** 10 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSet(src, TEN_BYTES);
	printf("Time spent for 10 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 100 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSet(src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMSET non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveSet(src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSet(src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes  of non DMA memset in seconds : %f\n",time_elapsed);


}

/**********************************************************
*
* FUNCTION : getTimeMoveMemOPT(void * source, const void * destination, size_t num)
* FUNCTION DESCRIPTION : This function is a profiler which is used to check the time taken for opt function memmove and mezero/memset
*
************************************************************/

double getTimeMoveMemOPT(uint8_t * destination, uint8_t * source, uint32_t num)
{
	struct timeval st, et;
	gettimeofday(&st, NULL);
	my_opt_memmove(source, destination, num);
	gettimeofday(&et, NULL);
	return (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
}

/**********************************************************
*
* FUNCTION : profiler_BBB_non_DMA_opt_memmove()
* FUNCTION DESCRIPTION : This function profiles  non DMA opt function memmove for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

void profiler_BBB_non_DMA_opt_memmove(void){

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
    	double time_spent; double first, second;
	time_t start, stop;
	struct  timeval st, et;
	double time_elapsed;
	printf(" NON DMA OPT MEMMOVE PROFILING \n ");
	/*********************************** 10 Bytes MEMMOVE non DMA  function on BBB **************************************/


	time_elapsed = getTimeMoveMemOPT(dst, src, TEN_BYTES);
	printf("Time spent for 10 bytes of NON DMA OPT memmove in seconds : %f\n",time_elapsed);


	/*********************************** 100 Bytes MEMMOVE non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveMemOPT(dst1, src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes of non DMA OPT memmove in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMMOVE non DMA  function on BBB **************************************/


	time_elapsed = getTimeMoveMemOPT(dst2, src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes of non DMA OPT memmove in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMMOVE non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveMemOPT(dst3, src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes of non DMA OPT memmove in seconds : %f\n",time_elapsed);

}

/**********************************************************
*
* FUNCTION : profiler_BBB_non_DMA_OPT_memset()
* FUNCTION DESCRIPTION : This function profiles  non DMA OPT function memset for 10 , 100, 1000, 5000 bytes on BBB
*
************************************************************/

double getTimeMoveSetOPT(uint8_t  * source, uint32_t num)
{
	struct  timeval st, et;
	gettimeofday(&st, NULL);
	my_opt_memset(source, num, 0);
	gettimeofday(&et, NULL);
	return (double)(((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec))/1000000.0;
}




void profiler_BBB_non_DMA_OPT_memset(void){

	uint8_t  src[TEN_BYTES] = "newstrings" , dst[TEN_BYTES];
	uint8_t src1[HUNDRED_BYTES] = "123456789" ,dst1[HUNDRED_BYTES];
	uint8_t src2[THOUSAND_BYTES] = "123456" , dst2[THOUSAND_BYTES];
	uint8_t src3[FIVE_THOUSAND_BYTES] = "123" , dst3[FIVE_THOUSAND_BYTES];
	clock_t start, stop;
	double  time_spent;
	struct  timeval st, et;
	double time_elapsed;

	printf(" NON DMA OPT MEMSET PROFILING \n ");

	/*********************************** 10 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSetOPT(src, TEN_BYTES);
	printf("Time spent for 10 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 100 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSetOPT(src1, HUNDRED_BYTES);
	printf("Time spent for 100 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 1000 Bytes MEMSET non DMA  function on BBB **************************************/

	time_elapsed = getTimeMoveSetOPT(src2, THOUSAND_BYTES);
	printf("Time spent for 1000 bytes of non DMA memset in seconds : %f\n",time_elapsed);

	/*********************************** 5000 Bytes MEMSET non DMA  function on BBB **************************************/
	time_elapsed = getTimeMoveSetOPT(src3, FIVE_THOUSAND_BYTES);
	printf("Time spent for 5000 bytes  of non DMA memset in seconds : %f\n",time_elapsed);


}
