################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/heap_4.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/portable/MemMang/heap_4.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


