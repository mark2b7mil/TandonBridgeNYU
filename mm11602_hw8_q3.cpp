#include <iostream>

void printArray(int arr[], int arrSize);
//reverses array by iterating from front and back and reversing integers
void reverseArray(int arr[], int arrSize);
//removes odd integers by moving even integers to front of array and shrinking size of array size for every odd integer and returning by reference
void removeOdd(int arr[], int& arrSize);
//iterating from front and back and flipping digits to the left if odd and to the right if even
void splitParity(int arr[], int arrSize);

int main()
{
	int arr1[10] = { 9, 2, 14, 12, -3 };
	int arr1Size = 5;

	int arr2[10] = { 21, 12, 6, 7, 14 };
	int arr2Size = 5;

	int arr3[10] = { 3, 6, 4, 1, 12 };
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

}

void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

//reverses array by iterating from front and back and reversing integers
void reverseArray(int arr[], int arrSize) {
	int length = arrSize, temp = 0;
	for (int i = 0, k = length-1; i < length / 2; i++, k--) {
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

//removes odd integers by moving even integers to front of array and shrinking size of array size for every odd integer and returning by reference
void removeOdd(int arr[], int& arrSize) {
	int size = arrSize, evenCounter = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0) {
			arr[evenCounter] = arr[i];
			evenCounter++;
		}
		else {
			size--;
		}
	}
	arrSize = size;
}

//iterating from front and back and flipping digits to the left if odd and to the right if even
void splitParity(int arr[], int arrSize) {
	int back = arrSize-1, start = 0, temp = 0;
	while (start < back) {
		while (start < back && arr[start] % 2 != 0) {
			start++;
		}
		while (start < back && arr[back] % 2 == 0) {
			back--;
		}
		if (start < back) {
			temp = arr[start];
			arr[start] = arr[back];
			arr[back] = temp;
			start++;
			back--;
		}
	}
}