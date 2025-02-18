#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    for (int a = 1; a <= n; a++)
    {
        for (int b = a; b <= n; b++) 
	{
            int c = a * a + b * b;
            int sqrt_c = sqrt(c);
            if (sqrt_c * sqrt_c == c && sqrt_c <= n) 
	    {
                std::cout<< a << " " << b << " " << sqrt_c << "\n";
            }
        }
    }

    return 0;
}

