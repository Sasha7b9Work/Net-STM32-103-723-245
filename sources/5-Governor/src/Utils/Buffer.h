#pragma once
#include <cstring>


template<class T, int size_buffer>
class Buffer
{
public:

    Buffer() : size(0) {}; //-V730

    T *Data() { return buffer; }

    // Возвращает количество элементов в буфере
    int Size() const
    {
        return size;
    }

    void Clear()
    {
        size = 0;
    }

    void Append(T value)
    {
        if (Size() + sizeof(T) > size_buffer)
        {

        }
        else
        {
            std::memcpy(&buffer[size], &value, sizeof(T));
            size += sizeof(T);
        }
    }

    T &operator[](uint i)
    {
        if ((int)i >= 0 && (int)i < Size())
        {
            return buffer[i];
        }

        static T null(0);

        return null;
    }

    T &operator[](int i)
    {
        if (i >= 0 && i < Size())
        {
            return buffer[i];
        }

        static T null(0);

        return null;
    }

protected:

    int size;

    T buffer[size_buffer];
};

