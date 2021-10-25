#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
//#include <algorithm>

//inputs pin as a string, making sure pin is correct length, returning string if its at correct length
std::string inputPin();
//prints pin string with spaces in between characters
void printFormattedPin(const std::string str);
//creates a random pin and returns it as a string
std::string createRandomPinPad();
//compares input pin to stored pin to see if they match, returns boolean value accordingly
bool comparePins(std::string pinPad, std::string randomPinPad, std::string pinInput, std::string storedPin);


const std::string PIN = "01234";
const std::string PIN_PAD = "0123456789";

int main() 
{
	std::string randomPinPad;
	std::string pinInput;

	std::cout << "Please enter your PIN according to the following mapping:" << std::endl;
	std::cout << "PIN: ";
	printFormattedPin(PIN_PAD);
	std::cout << std::endl;
	std::cout << "NUM: ";
	randomPinPad = createRandomPinPad();
	printFormattedPin(randomPinPad);
	std::cout << std::endl;
	pinInput = inputPin();
	if (comparePins(PIN_PAD, randomPinPad, pinInput, PIN)) {
		std::cout << "Your PIN is correct" << std::endl;
	}
	else {
		std::cout << "Your PIN is not correct" << std::endl;
	}

}

//inputs pin as a string, making sure pin is correct length, returning string if its at correct length
std::string inputPin() {
	std::string temp;
	do {
		std::cin >> temp;
		if (temp.length() != PIN.length()) {
			std::cout << "Please enter a " << PIN.length() << " digit PIN." << std::endl;
		}
	} while (temp.length() != PIN.length());

	return temp;
}

//prints pin string with spaces in between characters
void printFormattedPin(const std::string str) {
	for (char x : str) {
		std::cout << x << " ";
	}
}

//creates a random pin and returns it as a string
std::string createRandomPinPad() {
	std::string randomNums = PIN_PAD;
	char nums[3] = { '1','2','3' };
	srand(time(0));
	for (auto i = 0; i < randomNums.length(); i++) {
		randomNums[i] = nums[(rand() % 3)];
	}
	return randomNums;
}

//compares input pin to stored pin to see if they match, returns boolean value accordingly
//first loop runs PIN_LENGTH times to account for the stored pin and new pin index
//second loop runs PIN_PAD_LENGTH times to check each pin index against each pin pad index to check for matches
//if the stored pin index value matches the pin pad index value then it checks if the same is true for the random pin pad and input pin values
bool comparePins(std::string pinPad, std::string randomPinPad, std::string pinInput, std::string storedPin) {
	char temp;
	for (int i = 0; i < storedPin.length(); i++) {
		temp = storedPin[i];
		for (int k = 0; k < pinPad.length(); k++) {
			if (pinPad[k] == temp) {
				if (randomPinPad[k] != pinInput[i]) {
					return false;
				}
			}
		}
	}
	return true;
}

//BELOW IS THE SAME FUNCTIONALITY, JUST IMPLEMENTED USING RAW ARRAYS INSTEAD OF STRINGS, IN CASE YOU PREFER ONE OVER ANOTHER

/*
//prints array
void printArray(const int arr[],const int arrSize);
//populates array with random numbers
void createRandomPinPad(int arr[], int size);
//converts input of integers to an array of separated ints
void convertInputToArray(int input, int arr[]);
//compares a secret pin to the original pin based on index comparisons between a regular array and random array
bool comparePins(const int arr[], int randomArr[],const int size, int pinInput[],const int storedPin[]);

const int PIN[] = { 0,1,2,3,4 };
const int PIN_SIZE = 5;
const int PIN_PAD[10] = { 0,1,2,3,4,5,6,7,8,9 };
const int PIN_PAD_SIZE = 10;

int main()
{

	int randomPinPad[PIN_PAD_SIZE];
	int pinInput;
	int pinInputArray[PIN_SIZE];

	std::cout << "Please enter your PIN according to the following mapping:" << std::endl;
	std::cout << "PIN: ";
	printArray(PIN_PAD, PIN_PAD_SIZE);
	createRandomPinPad(randomPinPad, PIN_PAD_SIZE);
	std::cout << "NUM: ";
	printArray(randomPinPad, PIN_PAD_SIZE);
	std::cin >> pinInput;
	convertInputToArray(pinInput, pinInputArray);

	if (comparePins(PIN_PAD, randomPinPad, PIN_PAD_SIZE, pinInputArray, PIN)) {
		std::cout << "Your PIN is correct" << std::endl;
	}
	else {
		std::cout << "Your PIN is not correct" << std::endl;
	}

}

//prints array, arguments are constant since function isn't supposed to change anything
//works for inputting non-const arrays and sizes
void printArray(const int arr[],const int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

//populates array with random numbers from 1-3
void createRandomPinPad(int arr[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 3) + 1;
	}
}

//converts an integer input to an array
void convertInputToArray(int input, int arr[]) {
	for (int j = 0; j < PIN_SIZE; j++) {
		int temp = input / pow(10, j);
		temp = temp % 10;
		arr[PIN_SIZE - 1 - j] = temp;
	}
}

//takes in original array 0-9 and random array, their sizes which are both ten, and both pins, original and new secret one
//loops through the original pin to find the index for every number in the pin, starting from the last number. 
//then uses that index to compare if the input pin matches with the original pin
bool comparePins(const int arr[], int randomArr[], const int size, int pinInput[], const int storedPin[]) {
	int temp = 0;
	for (int i = 0; i < PIN_SIZE; i++) {
		temp = storedPin[i];
		for (int k = 0; k < size; k++) {
			if (arr[k] == temp) {
				if (randomArr[k] != pinInput[i]) {
					return false;
				}
			}
		}
	}
	return true;
}
*/
