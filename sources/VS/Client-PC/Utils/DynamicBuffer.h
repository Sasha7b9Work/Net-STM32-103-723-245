// 2022/08/24 15:11:13 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


// ������ ���������� � ������������� size_chunk
template<int size_chunk>
class DynamicBuffer
{
public:
    DynamicBuffer();

    void Append(uint8 *data, int size);

    int Size() const
    {
        if (!buffer)
        {
            return 0;
        }

        return last - first;
    }

    uint8 *Data() { return buffer + first; }

    // ������������ ������. ��� ���� ������ �� ������ �����������
    void Realloc(int size);

    // ������ num_bytes ���� �� ������ ������
    void RemoveFirst(int num_bytes);

    // ��������� ����� (������ �� ������ ������ �����)
    void Compact();

private:

    uint8 *buffer;      // ����� �������� ������. 0, ���� ������ �� ��������
    int    capacity;    // ������� ���� ��������.
    int    first;       // ������ �������������� �������
    int    last;        // ��������� �������������� �������
};
