// 2022/04/20 08:54:03 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "usbd_cdc.h"


struct CDC
{
    static void Init();

    static uint8 Transmit(const void *buffer, int size);

    static void TransmitF(char *buffer, ...);

    static void OnIRQHandler();

    static void *handlePCD;        // PCD_HandleTypeDef
};
