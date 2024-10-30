#include <iostream>
using namespace std;

int main()
{
	const float PI = 3.14;
	float r;

	cout << "Enter circle radius" << endl;
	cin >> r;
	
	cout << "Circle area: " << PI * r*r << endl;
	cout << "Circle lenght: " << 2 * PI * r << endl;
}
