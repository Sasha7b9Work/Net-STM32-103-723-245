// 2022/8/4 13:37:46 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


#define TIME_MS Timer::CurrentTime()


namespace Timer
{
    uint CurrentTime();
}



// ��������� ��� ������� �������
struct TimeMeterMS
{
    TimeMeterMS();

    // ���������� ������ �������
    void Reset();

    void Pause();

    void Continue();

    // ������� ����������� ������ � ������� ������ Reset()
    uint ElapsedTime();

private:

    uint time_reset;        // �� ����� ������� ������������� ElapsedTime()
    uint time_pause;        // � ���� ������ ��������� �� �����
};
