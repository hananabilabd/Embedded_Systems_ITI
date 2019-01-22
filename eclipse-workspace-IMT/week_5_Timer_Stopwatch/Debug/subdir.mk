################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../Interrupt.c \
../Keypad.c \
../LCD.c \
../SevenSegment.c \
../Timer.c \
../main.c 

OBJS += \
./ADC.o \
./DIO.o \
./Interrupt.o \
./Keypad.o \
./LCD.o \
./SevenSegment.o \
./Timer.o \
./main.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./Interrupt.d \
./Keypad.d \
./LCD.d \
./SevenSegment.d \
./Timer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


