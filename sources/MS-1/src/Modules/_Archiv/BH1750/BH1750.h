// 2022/02/21 15:39:55 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Storage/Measure.h"

/*
* ������ ������������
*/

namespace BH1750
{
    void Init();

    bool GetMeasure(Measure *);
}
