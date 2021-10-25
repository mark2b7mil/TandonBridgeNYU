#include <iostream>

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int size);
void inputArray(int arr[], int size);

int main()
{
	int n = 0;
	int resArrSize = 0;
	int* missingArr = nullptr;

	//asks for number of inputs, and initializes dynamic array with value
	std::cout << "How many integers in your array?" << std::endl;
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Please enter " << n << " numbers from 0 to " << n << " separated by a space, (including 0 and " << n << "): " << std::endl;

	inputArray(arr, n);

	missingArr = findMissing(arr, n, resArrSize);

	std::cout << "The missing integers are: " << std::endl;
	printArray(missingArr, resArrSize);

	delete[] missingArr;
	missingArr = nullptr;
	delete[] arr;
	arr = nullptr;


}

//loops through array and prints values
void printArray(int arr[], int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << "]";
}

//gets input and puts it into array initialized above
//checks if the input is a collection of valid integers and if not asks for input again
void inputArray(int arr[], int size) {
	int inputTemp = 0;
	for (int i = 0; i < size; ) {
		std::cin >> inputTemp;
		if (inputTemp >= 0 && inputTemp <= size) {
			arr[i] = inputTemp;
			i++;
		}
		else {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Enter valid integers" << std::endl;
			i = 0;
		}
	}
}

/*
finds any missing integers by first initializing a counter array that increments a value in the array that correspond to each input,
so if input is 1 then the element at counterArr[1] increments by 1. Then loops over all the elements in the counter array and keeps track 
of the elements that are missing. Then a new dynamic array is initialized with the size of how many missing numbers there are.
then places all missing elements in the new missing number array.
*/
int* findMissing(int arr[], int n, int& resArrSize)
{
	int* counterArr = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		counterArr[i] = 0;
	}
	int missingNumsCount = 0;

	for (int i = 0; i < n; i++) {
		counterArr[arr[i]]++;
	}
	for (int i = 0; i <= n; i++) {
		if (counterArr[i] == 0) {
			missingNumsCount++;
		}
	}
	int* missingNumArr = new int[missingNumsCount];
	int missingArrCounter = 0;
	for (int i = 0; i <= n; i++) {
		if (counterArr[i] == 0) {
			missingNumArr[missingArrCounter] = i;
			missingArrCounter++;
		}
	}
	delete[] counterArr;
	counterArr = nullptr;
	resArrSize = missingNumsCount;
	return missingNumArr;
}
