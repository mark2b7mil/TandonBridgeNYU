#include <iostream>

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{

	int arrSize = 0;
	std::cout << "How many numbers in your array?" << std::endl;
	std::cin >> arrSize;
	int* arr = new int[arrSize];
	std::cout << "Please enter " << arrSize << " numbers separated by a space." << std::endl;
	//inputting numbers into array
	for (int i = 0; i < arrSize; i++) {
		std::cin >> arr[i];
	}

	std::cout << std::endl;

	oddsKeepEvensFlip(arr, arrSize);

	//printing updated array
	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	delete[] arr;
	arr = nullptr;
}


/*
creates a dynamic array that uses a counter from the back of the array to place even numbers
and a counter from the front for the odd integers. then copies elements from the function array elements to the elements in the main function array.
*/
void oddsKeepEvensFlip(int arr[], int arrSize) {
	int oddStart = 0;
	int evenEnd = arrSize - 1;
	int temp = arrSize;
	int* tempArr = new int[arrSize];
	int evenCounter = 0;
	int oddCounter = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0) {
			tempArr[evenEnd - evenCounter] = arr[i];
			evenCounter++;
		}
		else {
			tempArr[oddStart + oddCounter] = arr[i];
			oddCounter++;
		}
	}
	for (int i = 0; i < arrSize; i++) {
		arr[i] = tempArr[i];
	}
	delete [] tempArr;
	tempArr = nullptr;
}