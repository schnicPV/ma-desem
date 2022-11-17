#include "mcu/mcu.h"
#include "main.h"
#include "board/led.h"

void Led::initialize()
{
    // The green LED of the Nucleo board is on MCU pin PA5.

	// Note: GPIO configuration code is generated by STM32CubeIDE
    //       and is located in the 'Core/Src/main.c' file.
    //
    //       Double-click on the hal-project.ioc file for more details.
    //
    // This means that in this method no additional hardware initialization
    // code must be called. It is already implemented in the MX_GPIO_Init()
    // function in the 'Core/Src/main.c' file and also called in the main()
    // function!
}

void Led::turnOn()
{
	// TODO: Call HAL_GPIO_WritePin(...) function to set GPIO pin connected to the LED.
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin ,GPIO_PIN_SET);
}

void Led::turnOff()
{
    // TODO: Same procedure as mentioned above to turn of the LED.
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin ,GPIO_PIN_SET);
}
