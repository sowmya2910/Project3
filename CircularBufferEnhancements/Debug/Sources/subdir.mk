################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/circbuf.c \
../Sources/data.c \
../Sources/logger_q.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/uart.c 

OBJS += \
./Sources/circbuf.o \
./Sources/data.o \
./Sources/logger_q.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/uart.o 

C_DEPS += \
./Sources/circbuf.d \
./Sources/data.d \
./Sources/logger_q.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


