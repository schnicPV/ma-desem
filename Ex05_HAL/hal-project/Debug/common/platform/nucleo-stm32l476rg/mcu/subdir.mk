################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/platform/nucleo-stm32l476rg/mcu/mcu.cpp 

OBJS += \
./common/platform/nucleo-stm32l476rg/mcu/mcu.o 

CPP_DEPS += \
./common/platform/nucleo-stm32l476rg/mcu/mcu.d 


# Each subdirectory must supply rules for building sources it contributes
common/platform/nucleo-stm32l476rg/mcu/%.o common/platform/nucleo-stm32l476rg/mcu/%.su: ../common/platform/nucleo-stm32l476rg/mcu/%.cpp common/platform/nucleo-stm32l476rg/mcu/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DTC_STM32CUBEIDE -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/platform/nucleo-stm32l476rg" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu

clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu:
	-$(RM) ./common/platform/nucleo-stm32l476rg/mcu/mcu.d ./common/platform/nucleo-stm32l476rg/mcu/mcu.o ./common/platform/nucleo-stm32l476rg/mcu/mcu.su

.PHONY: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-mcu

