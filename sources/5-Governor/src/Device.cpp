// 2022/04/27 11:48:13 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Device.h"
#include "Hardware/Modules/HC12/HC12.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/Modules/BME280/BME280.h"
#include "Hardware/Modules/CG-Anem/CG-Anem.h"
#include "Hardware/Modules/BH1750/BH1750.h"
#include "Hardware/CDC/CDC.h"
#include "Hardware/Modules/ST7735/ST7735.h"
#include "Hardware/Timer.h"
#include "Hardware/InterCom.h"
#include "Display/Display.h"
#include "Hardware/Keyboard.h"
#include "Hardware/Modules/Laser/Laser.h"


void Device::Init()
{
    HAL::Init();

    CDC::Init();

    Timer::Delay(1000);
}


void Device::Update()
{
    HAL_USART1::Update();

    Laser::Update();

/*
    static float prev_angle = -100.0f;

    Keyboard::Update();

    if (Keyboard::GetAngleFull() != prev_angle)
    {
        prev_angle = Keyboard::GetAngleFull();

        CDC::TransmitF("Angle %.1f/%.1f", Keyboard::GetAngleRelative(), prev_angle);
    }
*/
}
