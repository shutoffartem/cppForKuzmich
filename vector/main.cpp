#include <iostream>
#include "vector.h"

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

    std::cout << "that's all folks";
}

