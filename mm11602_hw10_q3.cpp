#include <iostream>
#include <vector>

int* arrInput(int& length);
void searchArr(int searchNum, int inputArr[], int arrLength);
void main1();
std::vector<int> vecInput();
void searchVec(std::vector<int> vecInt, int searchNum);
void main2();

int main()
{
	//dynamic array
	main1();
	//vector
	main2();


}

//main1 runs program with dynamic array allocation
void main1() {
	int arrLength = 0;
	int* inputArr = new int[arrLength];

	std::cout << "Please enter a sequence of positive integers, each in a separate line." << std::endl;
	std::cout << "End your input by typing -1." << std::endl;

	inputArr = arrInput(arrLength);


	int searchNum = 0;

	std::cout << "Please enter a number you want to search." << std::endl;
	std::cin >> searchNum;

	searchArr(searchNum, inputArr, arrLength);
}

//main2 runs program with vector
void main2() {
	
	std::vector<int> vecInt;

	std::cout << "Please enter a sequence of positive integers, each in a separate line." << std::endl;
	std::cout << "End your input by typing -1." << std::endl;

	vecInt = vecInput();

	int searchNum = 0;

	std::cout << "Please enter a number you want to search." << std::endl;
	std::cin >> searchNum;

	searchVec(vecInt, searchNum);
}

/*
Searches array inputArr for searchNum with arr length that's gotten from arrInput.
First it loops over the array and checks each element against the searchNum and if the number matches then foundCounter is incremented
A new dynamic array is initialized with the size of foundCounter and then it loops over the original array and when the searchNum matches the array element the foundArr
array stores the line number(s). Then the line numbers are printed.
*/
void searchArr(int searchNum, int inputArr[], int arrLength) {
	int foundCounter = 0;

	for (int i = 0; i < arrLength; i++) {
		if (inputArr[i] == searchNum) {
			foundCounter++;
		}
	}

	int* foundArr = new int[foundCounter];
	int foundArrCounter = 0;

	for (int i = 0; i < arrLength; i++) {
		if (inputArr[i] == searchNum) {
			foundArr[foundArrCounter] = i + 1;
			foundArrCounter++;
		}
	}
	if (foundArrCounter == 0) {
		std::cout << searchNum << " is not in the list." << std::endl;
	}
	else {
		std::cout << searchNum << " shows in lines ";
		for (int i = 0; i < foundArrCounter; i++) {
			std::cout << foundArr[i];
			if (i < foundArrCounter - 1) {
				std::cout << ", ";
			}
		}
		std::cout << ".";
		std::cout << std::endl;
	}

	delete[] foundArr;
	foundArr = nullptr;
}

/*
Takes input until -1 or anything smaller is input. For every input inputCounter is incremented and the input counter is checked against double counter which makes sure that we are
not inputting more elements than the new array is set up for. If inputcounter matches doublecounter then it initializes a new dynamic array with double the elements, copying the previous array to the original array
then inputting the new value and moving the pointer of the original array to the new array and clearing the new array. Returns the array of inputs and updates the length of the array by argument
*/
int* arrInput(int& length)
{
	int input = 0;
	int inputCounter = 0;
	int doubleCounter = 1;
	int* arr = new int[doubleCounter];

	while (input != -1) {
		std::cin >> input;
		if (input > 0) {
			inputCounter++;
			if (inputCounter == doubleCounter) {
				doubleCounter *= 2;
				int* arrNew = new int[doubleCounter];
				for (int i = 0; i < inputCounter - 1; i++) {
					arrNew[i] = arr[i];
				}
				arrNew[inputCounter - 1] = input;
				delete[] arr;
				arr = arrNew;
				arrNew = nullptr;
			}
			else {
				arr[inputCounter - 1] = input;
			}
		}
		else if (input == 0 || input < -1) {
			std::cout << "Positive integer please" << std::endl;
		}
	}
	length = inputCounter;
	return arr;
}

/*
initializes vector and pushes back every input value up until -1 is input.
returns the vector.
*/
std::vector<int> vecInput()
{
	int input = 0;
	std::vector<int> vector;
	while (input != -1) {
		std::cin >> input;
		if (input > 0) {
			vector.push_back(input);
		}
		else if (input == 0 || input < -1) {
			std::cout << "Positive integer please" << std::endl;
		}
	}

	return vector;
}

/*
loops over the vector and prints the line number when the seachNum matches an element in the array
*/
void searchVec(std::vector<int> vecInt, int searchNum) {
	std::vector<int> lineNum;
	for (int i = 0; i < vecInt.size(); i++) {
		if (vecInt[i] == searchNum) {
			lineNum.push_back(i+1);
		}
	}

	if (lineNum.size() == 0) {
		std::cout << searchNum << " is not in the list." << std::endl;
	}
	else {
		std::cout << searchNum << " shows in lines ";
		for (int i = 0; i < lineNum.size(); i++) {
			std::cout << lineNum[i];
			if (i < lineNum.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << ".";
	}
	std::cout << std::endl;
}
