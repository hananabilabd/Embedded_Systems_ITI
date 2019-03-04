################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Oscilliscope.lss \

FLASH_IMAGE += \
Oscilliscope.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Oscilliscope.elf secondary-outputs

# Tool invocations
Oscilliscope.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Oscilliscope.map -mmcu=atmega32 -o "Oscilliscope.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Oscilliscope.lss: Oscilliscope.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Oscilliscope.elf  >"Oscilliscope.lss"
	@echo 'Finished building: $@'
	@echo ' '

Oscilliscope.hex: Oscilliscope.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Oscilliscope.elf  "Oscilliscope.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Oscilliscope.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Oscilliscope.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Oscilliscope.elf
	@echo 'Invoking: AVRDude'
	F:\Programs\Eclipse\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:Oscilliscope.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Oscilliscope.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
