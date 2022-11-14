################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/xf/initialevent.cpp \
../common/xf/xf.cpp \
../common/xf/xfevent.cpp \
../common/xf/xfnulltransition.cpp \
../common/xf/xfreactive.cpp \
../common/xf/xfstaticevent.cpp \
../common/xf/xfthread.cpp \
../common/xf/xftimeout.cpp \
../common/xf/xftimeoutmanager.cpp 

OBJS += \
./common/xf/initialevent.o \
./common/xf/xf.o \
./common/xf/xfevent.o \
./common/xf/xfnulltransition.o \
./common/xf/xfreactive.o \
./common/xf/xfstaticevent.o \
./common/xf/xfthread.o \
./common/xf/xftimeout.o \
./common/xf/xftimeoutmanager.o 

CPP_DEPS += \
./common/xf/initialevent.d \
./common/xf/xf.d \
./common/xf/xfevent.d \
./common/xf/xfnulltransition.d \
./common/xf/xfreactive.d \
./common/xf/xfstaticevent.d \
./common/xf/xfthread.d \
./common/xf/xftimeout.d \
./common/xf/xftimeoutmanager.d 


# Each subdirectory must supply rules for building sources it contributes
common/xf/%.o common/xf/%.su: ../common/xf/%.cpp common/xf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DTC_STM32CUBEIDE -c -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/mdw" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg/mcu" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/common/platform/nucleo-stm32l476rg" -I"C:/Users/nicis/HESSO/MSc_ElE/MA_DeSEm/ma-desem/Ex05_HAL/hal-project/platform/nucleo-stm32l476rg" -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-xf

clean-common-2f-xf:
	-$(RM) ./common/xf/initialevent.d ./common/xf/initialevent.o ./common/xf/initialevent.su ./common/xf/xf.d ./common/xf/xf.o ./common/xf/xf.su ./common/xf/xfevent.d ./common/xf/xfevent.o ./common/xf/xfevent.su ./common/xf/xfnulltransition.d ./common/xf/xfnulltransition.o ./common/xf/xfnulltransition.su ./common/xf/xfreactive.d ./common/xf/xfreactive.o ./common/xf/xfreactive.su ./common/xf/xfstaticevent.d ./common/xf/xfstaticevent.o ./common/xf/xfstaticevent.su ./common/xf/xfthread.d ./common/xf/xfthread.o ./common/xf/xfthread.su ./common/xf/xftimeout.d ./common/xf/xftimeout.o ./common/xf/xftimeout.su ./common/xf/xftimeoutmanager.d ./common/xf/xftimeoutmanager.o ./common/xf/xftimeoutmanager.su

.PHONY: clean-common-2f-xf

