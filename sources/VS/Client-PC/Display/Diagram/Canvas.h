// 2022/09/05 08:47:51 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Data/Sensors.h"


/*
*   ����� ��������������� ���������
*/


class Canvas : public wxPanel
{
public:

    Canvas(wxWindow *parent, TypeMeasure::E);

    void SetSizeArea(int, int);

private:

    TypeMeasure::E type;

    void OnPaint(wxPaintEvent &);

    // ���������� ��������� �� ���� ��������
    void DrawAllSensors(wxMemoryDC &);

    // ���������� ��������� �� ������ �������
    void DrawSensor(wxMemoryDC &, const wxColour &, const DataArray &, float min, float max, float scale);

    void DrawTimeScale(wxMemoryDC &);

    void DrawTextOnBackground(wxMemoryDC &, pchar, int x, int y, int width, int height);

    // ����������� ����� � ���������� � �� �������
    int TimeToX(const Time &);
};
