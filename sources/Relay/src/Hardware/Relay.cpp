// 2024/08/06 11:34:14 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/Relay.h"
#include <stm32f1xx_hal.h>

/*
*   Реле подлючено к выводу 42 - PB6
*/


void Relay::Init()
{
    GPIO_InitTypeDef is;

    is.Pin = GPIO_PIN_7;
    is.Mode = GPIO_MODE_OUTPUT_PP;
    is.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOB, &is);
}


void Relay::On()
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
}


void Relay::Off()
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
}
