// 2024/08/05 11:57:45 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Hardware/CDC/Decoder.h"
#include "Hardware/CDC/CDC.h"
#include <cstring>


namespace Decoder
{
#define SIZE_BUFFER 128

    static uint8 buffer[SIZE_BUFFER];
    static int pointer = 0;

    static void AppendSymbol(uint8);

    // Возвращает true, если buffer начинается с pchar
    static bool BeginIs(pchar);
}


void Decoder::AppendData(uint8 *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        AppendSymbol(*data++);
    }

    if (std::strchr((pchar)buffer, 0x0d))
    {
        if (BeginIs("#RELAY ON"))
        {
            CDC::Transmit("Relay on\n");
        }
        else if (BeginIs("#RELAY OFF"))
        {
            CDC::Transmit("Relay off\n");
        }

        pointer = 0;
    }
}


bool Decoder::BeginIs(pchar text)
{
    return std::memcmp(buffer, text, std::strlen(text)) == 0;
}


void Decoder::AppendSymbol(uint8 symbol)
{
    if (symbol == 0x0a)
    {
        return;
    }

    if (pointer == SIZE_BUFFER)
    {
        pointer = 0;
    }

    if (pointer == 0)
    {
        if (symbol != '#')
        {
            return;
        }
    }

    buffer[pointer++] = symbol;
}
