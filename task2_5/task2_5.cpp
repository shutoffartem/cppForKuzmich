#include <iostream>
using namespace std;

int main()
{
	float grade;
	cin >> grade;

	if (grade >= 0 && grade <= 9)
	{
		if (grade >= 0 && grade <= 4.4)
		{
			cout << "Unsatisfactory grade: " << 2.0 << endl;
		}
		else if (grade > 4.4 && grade <= 5.2)
		{
			cout << "Satisfactory grade: " << 3.0 << endl;
		}	
		else if (grade > 5.2 && grade <= 6.2)
		{
			cout << "Decent grade: " << 3.5 << endl;
		}
		else if (grade > 6.2 && grade <= 7.2)
		{
			cout << "Good grade: " << 4.0 << endl;
		}
		else if (grade > 7.2 && grade <= 8.2)
		{
			cout << "Better grade: " << 4.5 << endl;
		}
		else if (grade > 8.2 && grade <= 9)
		{
			cout << "Best grade: " << 5.0 << endl;
		}
	}
	else 
	{
		cout << "Invalid number!" << endl;
	}
}
