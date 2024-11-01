#include <iostream>
using namespace std;

int main()
{
	int lenght, width;
	int num = 0;
	cout << "Enter snake's lenght" << endl;
	cin >> lenght;
	cout << "Enter snake's width" << endl;
       	cin >> width;

	while (num < lenght)
	{
		for (int i = 0; i < width - 1; i++)
		{
			cout << ++num << ' ';
		}

		cout << ++num << endl;

		for (int i = 0; i < width*2 - 1; i++)
		{
			cout << ' ';
		}

		cout << ++num << endl;

		for (int i = 0; i < width; i++)
		{
			cout << num-- + width << ' ';
                 
		}
		num += width * 2;
		cout << endl << ++num << endl;
	}	
}
