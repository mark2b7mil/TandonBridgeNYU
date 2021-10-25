#include <iostream>
#include <cmath>
#include <iomanip>

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
	int arrSize;
	std::cout << "How many integers in your array?" << std::endl;
	std::cin >> arrSize;
	int* arr = new int[arrSize];
	std::cout << "Please enter your " << arrSize << " integers, separated by a space." << std::endl;
	for (int i = 0; i < arrSize; i++) {
		std::cin >> arr[i];
	}

	
	std::cout << sumOfSquares(arr, arrSize) << std::endl;
	std::cout << std::boolalpha;
	std::cout << isSorted(arr, arrSize) << std::endl;
}

/*
recursively calls sumofSqaures by shrinking array size until the base case of 1 is met, then taking the square of each next array element
by keeping track of which stack frame the program is in, adds all of the squares of elements to temp
*/
int sumOfSquares(int arr[], int arrSize) {
	int temp = 0;
	if (arrSize == 1) {
		temp += pow(arr[0],2);
	}
	else {
		temp += sumOfSquares(arr, arrSize - 1);
		temp += pow(arr[arrSize - 1], 2);
	}
	return temp;
}

/*
tells if an array is sorted recursively by setting a temp bool variable and drilling down to base case of arrsize of 1 first
base case is always true so when the base function call pops off the stack for arrsize 2 we check if the first element is smaller than the
next element and if the previous iteration of isSorted came back true
*/
bool isSorted(int arr[], int arrSize) {
	bool temp = true;
	if (arrSize == 1) {
		temp = true;
	}
	else {
		temp = isSorted(arr, arrSize - 1);
		if ((arr[arrSize - 2] <= arr[arrSize - 1]) && temp == true) {
			temp = true;
		}
		else {
			temp = false;
		}
	}
	return temp;
}