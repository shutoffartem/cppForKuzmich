#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float p, r;
	int t;
	cout << "Enter initial amount" << endl;
	cin >> p;
	cout << "Enter time period" << endl;
	cin >> t;
	cout << "Enter interest rate" << endl;
	cin >> r;

	cout << "\n" << (int)(p*t*r / 100) << endl;
	cout << fixed << setprecision(2) << p*t*r / 100 << endl;
}
