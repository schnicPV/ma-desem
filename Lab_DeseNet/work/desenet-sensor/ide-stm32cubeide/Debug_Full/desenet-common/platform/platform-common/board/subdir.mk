################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board/ledflasher.cpp 

OBJS += \
./desenet-common/platform/platform-common/board/ledflasher.o 

CPP_DEPS += \
./desenet-common/platform/platform-common/board/ledflasher.d 


# Each subdirectory must supply rules for building sources it contributes
desenet-common/platform/platform-common/board/ledflasher.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board/ledflasher.cpp desenet-common/platform/platform-common/board/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-desenet-2d-common-2f-platform-2f-platform-2d-common-2f-board

clean-desenet-2d-common-2f-platform-2f-platform-2d-common-2f-board:
	-$(RM) ./desenet-common/platform/platform-common/board/ledflasher.d ./desenet-common/platform/platform-common/board/ledflasher.o ./desenet-common/platform/platform-common/board/ledflasher.su

.PHONY: clean-desenet-2d-common-2f-platform-2f-platform-2d-common-2f-board

