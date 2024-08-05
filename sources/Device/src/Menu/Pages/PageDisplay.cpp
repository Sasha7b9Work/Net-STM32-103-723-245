// 2022/05/05 13:14:44 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Settings/Settings.h"


extern const DPage pageMain;


DEF_CHOICE_2( chPressure,
    "��������",
    *PageDisplay::PageMeasures::self,
    gset.display.show_measure[TypeMeasure::Pressure],
    "����", "���"
)

DEF_CHOICE_2(chIllumination,
    "������������",
    *PageDisplay::PageMeasures::self,
    gset.display.show_measure[TypeMeasure::Illumination],
    "����", "���"
)

#ifdef TYPE_1
DEF_CHOICE_2(chVelocity,
    "��������",
    *PageDisplay::PageMeasures::self,
    gset.display.show_measure[TypeMeasure::Velocity],
    "����", "���"
)
#endif

DEF_CHOICE_2(chTemperature,
    "�����������",
    *PageDisplay::PageMeasures::self,
    gset.display.show_measure[TypeMeasure::Temperature],
    "����", "���"
)

DEF_CHOICE_2(chHumidity,
    "���������",
    *PageDisplay::PageMeasures::self,
    gset.display.show_measure[TypeMeasure::Humidity],
    "����", "���"
)

static void CloseMeasures()
{
    PageDisplay::PageMeasures::self->Close();
};

DEF_BUTTON( bCloseMeasures,
    "�������",
    *PageDisplay::PageMeasures::self,
    CloseMeasures
)

#ifdef TYPE_1
DEF_PAGE_6( pageMeasures, //-V1027
    "���������",
    *PageDisplay::self,
    chPressure,
    chIllumination,
    chTemperature,
    chHumidity,
    chVelocity,
    bCloseMeasures
)
#endif

#ifdef TYPE_2
DEF_PAGE_5(pageMeasures, //-V1027
    "���������",
    *PageDisplay::self,
    chPressure,
    chIllumination,
    chTemperature,
    chHumidity,
    bCloseMeasures
)
#endif


void ClosePageDisplay()
{
    PageDisplay::self->Close();
}

DEF_BUTTON( bClosePageDisplay,
    "�������",
    *PageDisplay::self,
    ClosePageDisplay
)

DEF_PAGE_2(pageDisplay, //-V1027
    "�������",
    pageMain,
    pageMeasures,
    bClosePageDisplay
)

const Page * const PageDisplay::self = (const Page *)&pageDisplay;
const Page * const PageDisplay::PageMeasures::self = (const Page *)&pageMeasures;
