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


void Device::Init()
{
    HAL::Init();

    ST7735::Init();

    BME280::Init();

    HC12::Init();

#ifdef TYPE_1
    CG_Anem::Init();
#endif

    BH1750::Init();

    Keyboard::Init();

    InterCom::SetDirection((Direction::E)(Direction::CDC | Direction::HC12 | Direction::Display));
}


void Device::Update()
{
    float temp = 0.0f;
    float pressure = 0.0f;
    float humidity = 0.0;

    if (BME280::GetMeasures(&temp, &pressure, &humidity))
    {
        InterCom::Send(TypeMeasure::Temperature, temp);
        InterCom::Send(TypeMeasure::Pressure, pressure);
        InterCom::Send(TypeMeasure::Humidity, humidity);
    }

#ifdef TYPE_1

    float velocity = 0.0f;

    if (CG_Anem::GetMeasure(&velocity))
    {
        InterCom::Send(TypeMeasure::Velocity, velocity);
    }
#endif

    float illumination = 0.0f;

    if (BH1750::GetMeasure(&illumination))
    {
        InterCom::Send(TypeMeasure::Illumination, illumination);
    }

    Keyboard::Update();

    Display::Update();
}
