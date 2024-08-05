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
}


void Decoder::AppendData(uint8 *data, int size)
{
    if (pointer + size > SIZE_BUFFER)
    {
        return;
    }

    CDC::Transmit(data, size);

    std::memcpy(buffer + pointer, data, (uint)size);

    pointer += size;
}
