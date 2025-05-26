#include <iostream>
#include <array>

int main()
{
	int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 18, 52};

	std::cout << sizeof(arr)/sizeof(arr[0]);
	double wantedItem;
	std::cin >> wantedItem;
	int minIndex = 0;
	int maxIndex = sizeof(arr)/sizeof(arr[0]) - 1;
	int middleIndex = maxIndex/2;


	while (minIndex <= maxIndex)
	{
		std::cout << "max " << maxIndex << std::endl;
		std::cout << minIndex << std::endl;
		std::cout << middleIndex << std::endl;
		
		if (arr[middleIndex] > wantedItem)
		{
			maxIndex = middleIndex;
			middleIndex = maxIndex / 2;
		}
		else if(arr[middleIndex] < wantedItem)
		{
			minIndex = middleIndex;
			middleIndex = (minIndex + maxIndex) / 2;
		}
		else
		{
			std::cout << middleIndex;
			return 0;
		}

		if (middleIndex == minIndex)
		{
			break;
		}
	}

	std::cout << "madsx " << maxIndex << std::endl;
	std::cout << "No matches found";
}
