################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/initialevent.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xf.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfevent.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfnulltransition.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfreactive.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfstaticevent.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfthread.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xftimeout.cpp \
C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xftimeoutmanager.cpp 

OBJS += \
./xf/initialevent.o \
./xf/xf.o \
./xf/xfevent.o \
./xf/xfnulltransition.o \
./xf/xfreactive.o \
./xf/xfstaticevent.o \
./xf/xfthread.o \
./xf/xftimeout.o \
./xf/xftimeoutmanager.o 

CPP_DEPS += \
./xf/initialevent.d \
./xf/xf.d \
./xf/xfevent.d \
./xf/xfnulltransition.d \
./xf/xfreactive.d \
./xf/xfstaticevent.d \
./xf/xfthread.d \
./xf/xftimeout.d \
./xf/xftimeoutmanager.d 


# Each subdirectory must supply rules for building sources it contributes
xf/initialevent.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/initialevent.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xf.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xf.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xfevent.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfevent.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xfnulltransition.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfnulltransition.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xfreactive.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfreactive.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xfstaticevent.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfstaticevent.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xfthread.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xfthread.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xftimeout.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xftimeout.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
xf/xftimeoutmanager.o: C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/xf/xftimeoutmanager.cpp xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DIDE_STM32CUBEIDE -DTC_STM32CUBEIDE -DUSE_DISPLAY -DDISPLAY_DRIVER_SSD1608 -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/.." -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/../src" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/ide-stm32cubeide/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/nucleo-stm32l476rg/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform/platform-common/board" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/platform" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Lab_DeseNet/work/desenet-sensor/src/common/mdw/desenet" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-xf

clean-xf:
	-$(RM) ./xf/initialevent.d ./xf/initialevent.o ./xf/initialevent.su ./xf/xf.d ./xf/xf.o ./xf/xf.su ./xf/xfevent.d ./xf/xfevent.o ./xf/xfevent.su ./xf/xfnulltransition.d ./xf/xfnulltransition.o ./xf/xfnulltransition.su ./xf/xfreactive.d ./xf/xfreactive.o ./xf/xfreactive.su ./xf/xfstaticevent.d ./xf/xfstaticevent.o ./xf/xfstaticevent.su ./xf/xfthread.d ./xf/xfthread.o ./xf/xfthread.su ./xf/xftimeout.d ./xf/xftimeout.o ./xf/xftimeout.su ./xf/xftimeoutmanager.d ./xf/xftimeoutmanager.o ./xf/xftimeoutmanager.su

.PHONY: clean-xf

