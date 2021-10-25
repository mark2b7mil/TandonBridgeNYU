#include <iostream>

//uses for loop to input numbers into an array of size arrSize
void inputArray(int arr[], int arrSize);
//finds the minimum value in an array of size arrSize
int minInArray(int arr[], int arrSize);
//loops over array arr and prints all the indices that have the same value as minimumValue
void printSameNumberIndex(int arr[], int arrSize, int minimumValue);

const int ARRAY_SIZE = 20;

int main()
{
	int array[ARRAY_SIZE];

	std::cout << "Please enter " << ARRAY_SIZE << " integers separated by a space:" << std::endl;

	inputArray(array, ARRAY_SIZE);
	std::cout << "The minimum value is " << minInArray(array, ARRAY_SIZE) << " and it's located in the following indices: ";
	//using output from minInArray as minimum value input in printSameNumberIndex
	printSameNumberIndex(array, ARRAY_SIZE, minInArray(array, ARRAY_SIZE));

}

//uses for loop to input numbers into an array of size arrSize
void inputArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		std::cin >> arr[i];
	}
}

//finds the minimum value in an array of size arrSize
int minInArray(int arr[], int arrSize) {
	int minValue = arr[0];
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] < minValue) {
			minValue = arr[i];
		}
	}
	return minValue;
}

//loops over array arr and prints all the indices that have the same value as minimumValue
void printSameNumberIndex(int arr[], int arrSize, int minimumValue) {
	int minValueCheck = minimumValue;
	for (int i = 0; i < arrSize; i++) {
		if (minValueCheck == arr[i]) {
			std::cout << i << " ";
		}
	}
}