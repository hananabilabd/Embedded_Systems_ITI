################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EEPROM.c \
../I2C.c \
../Keypad.c \
../LCD.c \
../main.c 

OBJS += \
./DIO.o \
./EEPROM.o \
./I2C.o \
./Keypad.o \
./LCD.o \
./main.o 

C_DEPS += \
./DIO.d \
./EEPROM.d \
./I2C.d \
./Keypad.d \
./LCD.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


