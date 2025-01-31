#include "defines.h"
#include "Hardware/CDC/CDC.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/Modules/HC12/HC12.h"
#include <stm32f1xx_hal.h>


void NMI_Handler(void)
{
}


__attribute__ ((noreturn)) void HardFault_Handler(void)
{
    while (1)
    {
    }
}


__attribute__ ((noreturn)) void MemManage_Handler(void)
{
    while (1)
    {
    }
}


__attribute__ ((noreturn)) void BusFault_Handler(void)
{
    while (1)
    {
    }
}


__attribute__ ((noreturn)) void UsageFault_Handler(void)
{
    while (1)
    {
    }
}


void SVC_Handler(void)
{

}


void DebugMon_Handler(void)
{

}


void PendSV_Handler(void)
{

}


void SysTick_Handler(void)
{
    HAL_IncTick();
}


void USB_LP_CAN1_RX0_IRQHandler(void)
{
    HCDC_OnIRQHandler();
}

void USART1_IRQHandler(void)
{
    HAL_UART_IRQHandler((UART_HandleTypeDef *)HC12::handle);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *)
{
    HC12::ReceiveCallback();
}
