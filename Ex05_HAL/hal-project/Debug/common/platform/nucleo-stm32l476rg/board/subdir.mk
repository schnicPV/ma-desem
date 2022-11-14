################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/platform/nucleo-stm32l476rg/board/board.cpp \
../common/platform/nucleo-stm32l476rg/board/button.cpp \
../common/platform/nucleo-stm32l476rg/board/led.cpp \
../common/platform/nucleo-stm32l476rg/board/trace.cpp 

OBJS += \
./common/platform/nucleo-stm32l476rg/board/board.o \
./common/platform/nucleo-stm32l476rg/board/button.o \
./common/platform/nucleo-stm32l476rg/board/led.o \
./common/platform/nucleo-stm32l476rg/board/trace.o 

CPP_DEPS += \
./common/platform/nucleo-stm32l476rg/board/board.d \
./common/platform/nucleo-stm32l476rg/board/button.d \
./common/platform/nucleo-stm32l476rg/board/led.d \
./common/platform/nucleo-stm32l476rg/board/trace.d 


# Each subdirectory must supply rules for building sources it contributes
common/platform/nucleo-stm32l476rg/board/%.o common/platform/nucleo-stm32l476rg/board/%.su: ../common/platform/nucleo-stm32l476rg/board/%.cpp common/platform/nucleo-stm32l476rg/board/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DTC_STM32CUBEIDE -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/platform/nucleo-stm32l476rg" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-board

clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-board:
	-$(RM) ./common/platform/nucleo-stm32l476rg/board/board.d ./common/platform/nucleo-stm32l476rg/board/board.o ./common/platform/nucleo-stm32l476rg/board/board.su ./common/platform/nucleo-stm32l476rg/board/button.d ./common/platform/nucleo-stm32l476rg/board/button.o ./common/platform/nucleo-stm32l476rg/board/button.su ./common/platform/nucleo-stm32l476rg/board/led.d ./common/platform/nucleo-stm32l476rg/board/led.o ./common/platform/nucleo-stm32l476rg/board/led.su ./common/platform/nucleo-stm32l476rg/board/trace.d ./common/platform/nucleo-stm32l476rg/board/trace.o ./common/platform/nucleo-stm32l476rg/board/trace.su

.PHONY: clean-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-board

