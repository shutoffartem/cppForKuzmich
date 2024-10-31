#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(12) << a + b << endl;
	cout << fixed << setprecision(12) << a - b << endl;
	cout << fixed << setprecision(12) << a * b << endl;
	cout << fixed << setprecision(12) << a / b << endl;
}
