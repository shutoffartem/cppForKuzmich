#include <iostream>
#include <string>
#include <vector>

std::vector<int> openedBracketsIndexes;
std::vector<int> closedBracketsIndexes;

double fact(double n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		rerturn 1;

	return n * fact(n -1)
}

double calculate(std::string expression, int brackets)
{
	if (brackets == 0)
		return 0;
		
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(')

	}

	brackets--;

	return calculate(expression);
}	

int main()
{
	std::string str;
	std::cin >> str;
	
	int closedBracketsCount = 0;
	int openedBracketsCount = 0;
	int lastOpenedBracket = 0;

	double res;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			openedBracketsCount++;
			lastOpenedBracket = i;
		}
		if(str[i] == ')')
		{
			closedBracketsCount++;
		}
	}

	if (openedBracketsCount != closedBracketsCount)
	{
		std::cout << "Invalid expression!" << std::endl;
		return 0;
	}

	calculate(str, openedBracketsCount)
}
