################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/croutine.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/event_groups.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/list.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/queue.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/stream_buffer.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/tasks.c \
H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/timers.c 

OBJS += \
./FreeRTOS/Source/croutine.o \
./FreeRTOS/Source/event_groups.o \
./FreeRTOS/Source/list.o \
./FreeRTOS/Source/queue.o \
./FreeRTOS/Source/stream_buffer.o \
./FreeRTOS/Source/tasks.o \
./FreeRTOS/Source/timers.o 

C_DEPS += \
./FreeRTOS/Source/croutine.d \
./FreeRTOS/Source/event_groups.d \
./FreeRTOS/Source/list.d \
./FreeRTOS/Source/queue.d \
./FreeRTOS/Source/stream_buffer.d \
./FreeRTOS/Source/tasks.d \
./FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/croutine.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/event_groups.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/list.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/queue.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/stream_buffer.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/stream_buffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/tasks.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS/Source/timers.o: H:/Softwares/FreeRTOSv10.2.0/FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Device Drivers\02-Projects\FreeRtos\Config" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\include" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\MemMang" -I"H:\Softwares\FreeRTOSv10.2.0\FreeRTOS\Source\portable\GCC\ATMega323" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


