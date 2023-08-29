################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Buzzer.c \
../Src/Fuel.c \
../Src/HeadAndParkingLights.c \
../Src/Indicators.c \
../Src/LCD.c \
../Src/MemoryMapping.c \
../Src/USART.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Buzzer.o \
./Src/Fuel.o \
./Src/HeadAndParkingLights.o \
./Src/Indicators.o \
./Src/LCD.o \
./Src/MemoryMapping.o \
./Src/USART.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Buzzer.d \
./Src/Fuel.d \
./Src/HeadAndParkingLights.d \
./Src/Indicators.d \
./Src/LCD.d \
./Src/MemoryMapping.d \
./Src/USART.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F405RGTx -c -I../Inc -I"C:/Users/uwf1kor/Desktop/Embedded C Training/CMSIS/Include" -I"C:/Users/uwf1kor/Desktop/Embedded C Training/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Buzzer.d ./Src/Buzzer.o ./Src/Buzzer.su ./Src/Fuel.d ./Src/Fuel.o ./Src/Fuel.su ./Src/HeadAndParkingLights.d ./Src/HeadAndParkingLights.o ./Src/HeadAndParkingLights.su ./Src/Indicators.d ./Src/Indicators.o ./Src/Indicators.su ./Src/LCD.d ./Src/LCD.o ./Src/LCD.su ./Src/MemoryMapping.d ./Src/MemoryMapping.o ./Src/MemoryMapping.su ./Src/USART.d ./Src/USART.o ./Src/USART.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

