#include <iostream>

int jumpIt(int arr[], int arrSize);

int main()
{
	int arrSize = 0;
	std::cout << "How many elements on your game board?" << std::endl;
	std::cin >> arrSize;

	//checks for correct input
	while (arrSize < 1) {
		std::cout << "Enter a positive number of elements" << std::endl;
		std::cin >> arrSize;
	}

	arrSize += 1;
	int* arr = new int[arrSize];
	arr[0] = 0;
	std::cout << "Please enter " << arrSize-1 << " integers." << std::endl;
	for (int i = 1; i < arrSize; i++) {
		std::cin >> arr[i];
	}

	std::cout << jumpIt(arr, arrSize) << std::endl;
}

/*
Recursively calls the function twice, one call to account for a single jump and another to account for a double jump, the jumps are compared and whichever
one results with the smallest number, it is added to the count that is returned from the function
*/
int jumpIt(int arr[], int arrSize) {
	int temp = 0;
	int temp2 = 0;
	int curr = 0;
	if (arrSize <= 3) {
		curr = arr[arrSize-1];
	}
	else {
		temp = jumpIt(arr, arrSize - 1);

		temp2 = jumpIt(arr, arrSize - 2);

		curr = arr[arrSize - 1];
		
		if (temp < temp2) {
			curr += temp;
		}
		else {
			curr += temp2;
		}
	}
	return curr;
}

