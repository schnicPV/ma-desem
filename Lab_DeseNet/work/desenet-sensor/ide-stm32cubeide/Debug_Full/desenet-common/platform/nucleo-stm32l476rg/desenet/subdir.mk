################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.cpp 

OBJS += \
./desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.o \
./desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.o 

CPP_DEPS += \
./desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.d \
./desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.d 


# Each subdirectory must supply rules for building sources it contributes
desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.cpp desenet-common/platform/nucleo-stm32l476rg/desenet/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.cpp desenet-common/platform/nucleo-stm32l476rg/desenet/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-desenet

clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-desenet:
	-$(RM) ./desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.d ./desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.o ./desenet-common/platform/nucleo-stm32l476rg/desenet/nrftransceiverdriver.su ./desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.d ./desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.o ./desenet-common/platform/nucleo-stm32l476rg/desenet/timeslotmanager.su

.PHONY: clean-desenet-2d-common-2f-platform-2f-nucleo-2d-stm32l476rg-2f-desenet

