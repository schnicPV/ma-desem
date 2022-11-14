################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../app/buttonmanager.cpp \
../app/factory.cpp 

OBJS += \
./app/buttonmanager.o \
./app/factory.o 

CPP_DEPS += \
./app/buttonmanager.d \
./app/factory.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o app/%.su: ../app/%.cpp app/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DTC_STM32CUBEIDE -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/platform/nucleo-stm32l476rg" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app

clean-app:
	-$(RM) ./app/buttonmanager.d ./app/buttonmanager.o ./app/buttonmanager.su ./app/factory.d ./app/factory.o ./app/factory.su

.PHONY: clean-app

