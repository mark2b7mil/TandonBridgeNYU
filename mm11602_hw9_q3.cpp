#include <iostream>

void printArray(int* arr, int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main()
{

	int arrSize;
	std::cout << "How many integers in your array?" << std::endl;
	std::cin >> arrSize;
	int* arr = new int[arrSize];
	std::cout << "Please enter " << arrSize << " positive and/or negative integers separated by a space" << std::endl;
	for (int i = 0; i < arrSize; i++) {
		std::cin >> arr[i];
	}

	//calling and printing result of function 1
	int posNumsSize = 0;
	int* posNums1 = getPosNums1(arr, arrSize, posNumsSize);
	printArray(posNums1, posNumsSize);
	delete posNums1;
	posNums1 = nullptr;


	//calling and printing result of function 2
	int* posNumsSizePtr = new int;
	*posNumsSizePtr = 0;
	int* posNums2 = getPosNums2(arr, arrSize, posNumsSizePtr);
	printArray(posNums2, *posNumsSizePtr);
	delete posNumsSizePtr;
	posNumsSizePtr = nullptr;


	//calling and printing result of function 3
	//initializing appropriate pointers and pointer arrays
	int* outPositiveArr = nullptr;
	int posNumsSize3 = 0;
	getPosNums3(arr, arrSize, outPositiveArr, posNumsSize3); 
	printArray(outPositiveArr, posNumsSize3);
	delete[] outPositiveArr;
	outPositiveArr = nullptr;


	//calling and printing result of function 4
	//initializing appropriate pointers and pointer arrays
	int* outPositiveArr2 = nullptr;
	int* posNumsSize4 = new int;
	*posNumsSize4 = 0;
	getPosNums4(arr, arrSize, &outPositiveArr2, posNumsSize4);
	printArray(outPositiveArr2, *posNumsSize4);
	delete [] outPositiveArr2;
	outPositiveArr2 = nullptr;
	delete posNumsSize4;
	posNumsSize4 = nullptr;
	delete [] arr;
	arr = nullptr;
}

void printArray(int* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

//returns a pointer to the array with positive numbers and updates the size by function argument reference
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int newArraySize = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArraySize++;
		}
	}
	int* positiveArr = new int[newArraySize];
	int newArrIndex = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			positiveArr[newArrIndex] = arr[i];
			newArrIndex++;
		}
	}
	outPosArrSize = newArraySize;
	return positiveArr;
}

//returns a pointer to the array with positive numbers and updates the size by dereferencing the size pointer and inputting new value
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	int newArraySize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArraySize++;
		}
	}
	int* positiveArr = new int[newArraySize];
	int newArrIndex = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			positiveArr[newArrIndex] = arr[i];
			newArrIndex++;
		}
	}
	*outPosArrSizePtr = newArraySize;
	return positiveArr;
}

//updates the positive array by pointer reference and the size of the array by reference as well
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	int newArraySize = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArraySize++;
		}
	}
	int newArrIndex = 0;
	int* posArr = new int[newArraySize];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[newArrIndex] = arr[i];
			newArrIndex++;
		}
	}
	delete[] outPosArr;
	outPosArr = posArr;
	posArr = nullptr;
	outPosArrSize = newArraySize;
}

//creates a new array with only positive values and changes the input pointer to point to that array
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	int newArraySize = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArraySize++;
		}
	}
	int newArrIndex = 0;
	int* posArr = new int[newArraySize];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[newArrIndex] = arr[i];
			newArrIndex++;
		}
	}
	delete* outPosArrPtr;
	*outPosArrPtr = posArr;
	*outPosArrSizePtr = newArraySize;
	posArr = nullptr;
}