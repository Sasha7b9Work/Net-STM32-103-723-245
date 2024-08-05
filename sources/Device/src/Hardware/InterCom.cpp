// Sasha7b9@tut.by (c)
#include "defines.h"
#include "Hardware/InterCom.h"
#include "Hardware/CDC/CDC.h"
#include "Modules/HC12/HC12.h"
#include "Modules/ST7735/ST7735.h"
#include "Display/Display.h"
#include "Utils/Text/String.h"
#include "Utils/Buffer.h"
#include "Utils/Math.h"
#include "Settings/Settings.h"

#ifdef GUI
    #include "Hardware/LAN/ClientTCP.h"
#endif


namespace InterCom
{
    /*
    *  ������ ���������.
    *  0       - 'A'
    *  1       - 'B'
    *  2       - 'C'
    *  3       - type
    *  4...7   - ID
    *  8...11  - hash[12...15]
    *  12...15 - value
    */

    Direction::E direction = Direction::_None;

    Buffer<uint8, 16> CreateMessage(TypeMeasure::E type, float value)
    {
        Buffer<uint8, 16> message;

        message[0] = 'A';
        message[1] = 'B';
        message[2] = 'C';
        message[3] = (uint8)type;

        uint id = Settings::GetID();

        std::memcpy(&message[4], &id, 4);

        std::memcpy(&message[12], &value, 4);

        uint hash = Math::CalculateHash(&value, 4);

        std::memcpy(&message[8], &hash, 4);

        return message;
    }
}


void InterCom::SetDirection(Direction::E dir)
{
    direction = dir;
}


void InterCom::Send(TypeMeasure::E type, float measure)
{
    static const pchar names[TypeMeasure::Count] =
    {
        "Pressure",
        "Luminance",
        "Temperature",
        "Humidity"
#ifdef TYPE_1
        , "Velocity"
#endif
    };

    static const pchar units[TypeMeasure::Count] =
    {
        "hPa",
        "lk",
        "degress Celsius",
        "%%"
#ifdef TYPE_1
        , "m/s"
#endif
    };

    if (direction & Direction::Display)
    {
        Display::SetMeasure(type, measure);
    }

    if (direction & Direction::CDC)
    {
        String<> message("%s : %f %s", names[type], measure, units[type]);

        CDC::Transmit(message.c_str(), message.Size() + 1);
    }

    if (direction & Direction::HC12)
    {
        Buffer<uint8, 16> data = CreateMessage(type, measure);

        HC12::Transmit(data.Data(), data.Size());
    }

#ifdef GUI

    Buffer<uint8, 16> data = CreateMessage(type, measure);

    ClientTCP::Transmit(data.Data(), data.Size()); 

#endif
}
