#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter 3 parallelepiped dimentions" << endl;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << "Surface area: " << 2*(a*b + a*c + b*c) << endl;
	cout << "Volume: " << a*b*c << endl;
}
