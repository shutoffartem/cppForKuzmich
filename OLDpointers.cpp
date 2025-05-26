#include <iostream>

int main()
{
	char a[6] = "hello";
	const char* h = "hello world!";
	char* p = a;
	char dest[50];

	for (int i = 0; i < 5; i++)
	{
		std::cout << *(a+i) << std::endl;

	}

	while (*p)
	{
		std::cout << *p++;
	}

	p = a;
	char* b = dest;
	
	while(*b++ = *p++);

	std::cout << dest << std::endl;

	b = dest;
	*(b+1) = 'a';

	std::cout << dest << std::endl;
	
	int c[255] = {0};
	const char* ph = h;
	
	while(*ph)
		c[(*ph++)]++;
	
	for (char i = 0; i < 255; i++)
		std::cout << i << ": " << c[i] << std::endl; 
}
