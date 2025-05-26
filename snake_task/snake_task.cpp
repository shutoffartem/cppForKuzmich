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
	
	cout << endl;

	while (num < lenght)
	{
		for (int i = 0; i < width - 1; i++)
		{
			if (num < 10)
			{
				cout << ++num << "  ";
			}
			else
			{
				cout << ++num << ' ';
			}	
		}

		cout << ++num << endl;

		for (int i = 0; i < width*2 + width / 2; i++)
		{
			cout << ' ';
		}

		cout << ++num << endl;

		for (int i = 0; i < width; i++)
		{
			if (num + width - 1 < 9)
			{
                                cout << num-- + width << "  ";
			}
			else
			{
				cout << num-- + width << ' ';
			}
		}
		num += width * 2;
		cout << endl << ++num << endl;
	}	
}
