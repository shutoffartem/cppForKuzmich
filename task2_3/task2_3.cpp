#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if(n % 2 == 0 && n % 8 == 0 && n % 16 == 0)
	{
		cout << "YES" << endl;	
	}
	else
	{
		cout << "NO" << endl;
	}

	cout << oct << n << endl;
	cout << hex << n << endl;
}
