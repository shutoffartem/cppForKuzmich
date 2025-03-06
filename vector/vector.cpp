#include "vector.h"
#include <iostream>

int& vector::operator[](int n)
{
    return *(data + n);
}

vector::vector() : size(0), capacity(1024), data(0)
{
    resize();
}
    
vector::vector(int _capacity) : size(0), capacity(_capacity), data(0)
{
    resize();
}

vector::~vector()
{
    if (data != 0)
    {
        delete[] data;
    }        
}

void vector::print()
{
    std::cout << "size: " << size << std::endl;
    std::cout << "capacity: " << capacity << std::endl;
}
int vector::get_size()
{
    return size;
}
int vector::get_capacity()
{
    return capacity;
}

void vector::resize()
{
    if (capacity == 0)
    {
        capacity = 1;
    }
    if(data == 0)
    {
        data = new int[capacity];
        return;
    }
    capacity *= 2;
    int* p = new int[capacity];
    for(int i = 0; i < size; i++)
    {
        p[i] = data[i];
    }

    delete[] data;
        
    data = p;
}

void vector::push_back(int n)
{
    if(size >= capacity)
    {
        resize();
    }

    data[size] = n;
    size++;
}


