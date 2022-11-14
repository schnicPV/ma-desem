#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#define TARGET_PLATFORM_NUCLEO_STM32L476RG

// ISR priorities starting from the highest urgency (Cortex-Mx specific)
enum ISR_Priorities
{
	TSM_PRIO,				/* TIM used for time slots */
    SYSTICK_PRIO,			/* Cortex System Tick Interrupt (SysTick_IRQn) */
    NRF24_PRIO,
    UART1_PRIO,
    UART2_PRIO,
    EXTI9_5_PRIO,
};

#define USE_TRACE				1		/* Enables/disables trace */
#define USE_USART2_TRACE		1		/* Use UART2 as output */
#define TRACE_UART_INDEX        1       /* Ex.: index 0 means use UART1 */
#define TRACE_FORMAT_LINUX		1		/* Set to one if the host is a Linux based OS */
#define TRACE_BUFFER_SIZE		256		/* Trace internal buffer size */

#endif // PLATFORM_CONFIG_H
