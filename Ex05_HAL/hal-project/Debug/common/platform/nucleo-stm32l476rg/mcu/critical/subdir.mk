################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/platform/nucleo-stm32l476rg/mcu/critical/critical.c 

C_DEPS += \
./common/platform/nucleo-stm32l476rg/mcu/critical/critical.d 

OBJS += \
./common/platform/nucleo-stm32l476rg/mcu/critical/critical.o 


# Each subdirectory must supply rules for building sources it contributes
common/platform/nucleo-stm32l476rg/mcu/critical/%.o common/platform/nucleo-stm32l476rg/mcu/critical/%.su: ../common/platform/nucleo-stm32l476rg/mcu/critical/%.c common/platform/nucleo-stm32l476rg/mcu/critical/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DTC_STM32CUBEIDE -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/platform/nucleo-stm32l476rg" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-critical

clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-critical:
	-$(RM) ./common/platform/nucleo-stm32l476rg/mcu/critical/critical.d ./common/platform/nucleo-stm32l476rg/mcu/critical/critical.o ./common/platform/nucleo-stm32l476rg/mcu/critical/critical.su

.PHONY: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu-2f-critical

