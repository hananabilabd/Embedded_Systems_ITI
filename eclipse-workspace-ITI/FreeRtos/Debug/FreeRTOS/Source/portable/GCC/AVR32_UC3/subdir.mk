################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/GCC/AVR32_UC3/port.c 

S_UPPER_SRCS += \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/GCC/AVR32_UC3/exception.S 

OBJS += \
./FreeRTOS/Source/portable/GCC/AVR32_UC3/exception.o \
./FreeRTOS/Source/portable/GCC/AVR32_UC3/port.o 

S_UPPER_DEPS += \
./FreeRTOS/Source/portable/GCC/AVR32_UC3/exception.d 

C_DEPS += \
./FreeRTOS/Source/portable/GCC/AVR32_UC3/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/GCC/AVR32_UC3/exception.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/GCC/AVR32_UC3/exception.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/portable/GCC/AVR32_UC3/port.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/GCC/AVR32_UC3/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\AVR32_UC3" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


