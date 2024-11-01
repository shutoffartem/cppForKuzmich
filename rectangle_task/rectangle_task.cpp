#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a - 1; i++)
	{
		cout << '*';
	}
	cout << '*' << endl;
	for (int i = 0; i < b - 1; i++)
	{
		cout << '*';
		for (int j = 0; j < a - 2; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	for (int i = 0; i < a; i++)
        {
                cout << '*';
        }
	cout << endl;	
	return 0;
}
