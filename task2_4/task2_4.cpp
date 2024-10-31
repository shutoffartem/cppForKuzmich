#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const float minTemp = -459.67;
	float temp;
	cin >> temp; 
	if(temp >= minTemp)
	{
		cout << fixed << setprecision(2) << (temp - 32) * 5 / 9 << endl;
	}
	else
	{
		cout << "Incorrect value" << endl;
	}	
}
