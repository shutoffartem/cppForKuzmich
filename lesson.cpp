#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

// test
int get_random_int()
{
    return rand();
}

int get_random_int(int a)
{
    return rand() % (a + 1);
}

int get_random_int(int first, int last)
{
   return first + rand() % (last - first + 1);
}

int binary_search(int* arr, int size, int target)
{
    int left = 0, right = size;
    while (left != right)
    {
        int mid = (left + right) / 2; 

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }

        else 
        {
            right = mid;
        }
    }

    return -1;
}


int search(int* arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector vector1;

    for (int i = 0; i < 50; i++)
    {
        vector1.push_back(i);
    }

    for (int i = 0; i < vector1.size; i++){
	    std::cout << vector1[i] << " ";
    }
}

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
