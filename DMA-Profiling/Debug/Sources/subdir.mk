################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/data.c \
../Sources/dma.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/memoryopt.c \
../Sources/profiler.c \
../Sources/timer.c \
../Sources/uart.c 

OBJS += \
./Sources/data.o \
./Sources/dma.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/memoryopt.o \
./Sources/profiler.o \
./Sources/timer.o \
./Sources/uart.o 

C_DEPS += \
./Sources/data.d \
./Sources/dma.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/memoryopt.d \
./Sources/profiler.d \
./Sources/timer.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


