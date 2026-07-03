#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "FreeRTOS.h"
#include "task.h"

#define DWT_CTRL (*((volatile uint32_t *)(0xE0001000)))

// Task Handlers
void Task1_Handler(void * parameter);
void Task2_Handler(void * parameter);

// Function to create a delay (in milliseconds)
void delay_ms(uint32_t milliseconds)
{
  SysCtlDelay((SysCtlClockGet() / 3000) * milliseconds);
}

int main(void)
{
  // Set the system clock to 80 MHz
  SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

  uint32_t clockFreq = SysCtlClockGet();

  // Enable the GPIO Port F peripheral
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

  // Wait for the GPIO module to be ready
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

  // Configure PF3 as output (Green LED)
  // First unlock the pin (required for PF0 and PF4-7)
  GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_2);

  // Set PF3 as a GPIO output
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

  // Enable the Cycle Counting for TimeStamp for segger
  DWT_CTRL |= 1<<0;

  // call the Segger sysview
  SEGGER_SYSVIEW_Conf();
  vInitPrioGroupValue();

  // Create the Task
  BaseType_t TaskCreateState;

  TaskCreateState =  xTaskCreate(Task1_Handler, "Task-1", 200, NULL, 2, NULL);
  configASSERT(TaskCreateState == pdPASS);
  TaskCreateState =  xTaskCreate(Task2_Handler, "Task-2", 200, NULL, 2, NULL);
  configASSERT(TaskCreateState == pdPASS);

  // Start the Segger Sysview
  SEGGER_SYSVIEW_Start(); 

  // Start the real time scheduler.
  vTaskStartScheduler();

  // Main loop - blink the green LED
  while(1)
  {
      // if we reach here something gone bad
  }


}

void Task1_Handler(void * parameter)
{
    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
    }
}

void Task2_Handler(void * parameter)
{
    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    }

}



