#include <iostream>
#include <string>
#include <algorithm>

int wordCounter(std::string str);
std::string justLettersLowerCase(std::string str);
void lowerCase(std::string& str);
void printLetterCount(std::string str, std::string alphabet);

int main()
{

	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string inputString;
	int wordCount = 0;

	std::cout << "Please enter a line of text:" << std::endl;
	std::getline(std::cin, inputString);
	wordCount = wordCounter(inputString);
	std::string justLetters = justLettersLowerCase(inputString);

	std::cout << wordCount << '\t' << "words" << std::endl;
	printLetterCount(justLetters, alphabet);

}
/*
* iterates over a line and counts the amount of words by iterating until the counter runs into a character 
* when the counter runs into a character a new counter runs until it reaches a space or puncutation
* after the second counter runs into an indication of the word ending, the word counter iterates and 
* the word character counter is added to first counter, thus ensuring a linear run time.
*/
int wordCounter(std::string str) {
	int wordCount = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i] != '\0' && str[i] != ',' && str[i] != '.') {
			int letterCounter = 0;
			for (int k = 0; str[k+i] != ' ' && str[k+i] != '\0' && str[k + i] != ',' && str[k + i] != '.'; k++) {
				letterCounter++;
			}
			i += letterCounter;
			wordCount++;
		}
	}
	return wordCount;
}

/*
* prints the number of letters in the string that is passed to the function
* prints alphabetically since the way the values are stored in an array that maps to 
* the alphabet and it prints from a-z so to speak
*/
void printLetterCount(std::string str, std::string alphabet) {
	int alphSize = alphabet.length();
	int* counterArr = new int[alphSize];

	for (size_t i = 0; i < alphSize; i++) {
		counterArr[i] = 0;
	}

	for (size_t i = 0; i < str.length(); i++) {
		counterArr[alphabet[str[i] - 97] - 97]++;
	}

	for (size_t i = 0; i < alphSize; i++) {
		if (counterArr[i] > 0) {
			std::cout << counterArr[i] << "\t" << alphabet[i] << std::endl;
		}
	}
	delete[] counterArr;
	counterArr = nullptr;
}

//converts a string to all lowercase letters
void lowerCase(std::string& str) {
	std::string tempStr;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = std::tolower(str[i]);
		}
		tempStr += str[i];
	}
	str = tempStr;
}

//converts a string to just its characters and lower cases using the lowerCase function
std::string justLettersLowerCase(std::string str) {
	std::string tempStr;
	lowerCase(str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			tempStr += str[i];
		}
	}
	return tempStr;
}