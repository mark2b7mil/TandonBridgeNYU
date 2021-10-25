#include <iostream>
#include <string>
#include <algorithm>

std::string justLettersLowerCase(std::string str);
void lowerCase(std::string& str);
bool isAnagram(std::string str1, std::string str2, std::string alphabet);

int main()
{
	//using alphabet string to initialize counters and compare values
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string string1;
	std::string string2;

	std::cout << "Please enter the first of two string:" << std::endl;
	std::getline(std::cin, string1);
	std::cout << "Please enter the second of two string:" << std::endl;
	std::getline(std::cin, string2);

	//adjusting original string to be all lowercase and getting rid of spaces and punctuation
	std::string string1Adjusted = justLettersLowerCase(string1);
	std::string string2Adjusted = justLettersLowerCase(string2);

	if (isAnagram(string1Adjusted, string2Adjusted, alphabet)) {
		std::cout << "The two strings are anagrams." << std::endl;
	}
	else {
		std::cout << "The two strings are NOT anagrams." << std::endl;
	}

}

/*
* checking if two strings are anagrams and returning bool value 
* initializing two counter arrays that keep track of the character values in each string
* by incrementing the int in the element of the array that is associated with the letter
*/
bool isAnagram(std::string str1, std::string str2, std::string alphabet) {
	int alphSize = alphabet.length();
	int* counterArr1 = new int[alphSize];
	int* counterArr2 = new int[alphSize];

	for (int i = 0; i < alphSize; i++) {
		counterArr1[i] = 0;
		counterArr2[i] = 0;
	}

	for (int i = 0; i < str1.length(); i++) {
		counterArr1[alphabet[str1[i] - 'a'] - 'a']++;
	}

	for (int i = 0; i < str2.length(); i++) {
		counterArr2[alphabet[str2[i] - 'a'] - 'a']++;
	}

	for (int i = 0; i < alphSize; i++) {
		if (counterArr1[i] != counterArr2[i]) {
			delete [] counterArr1;
			delete [] counterArr2;
			counterArr1 = nullptr;
			counterArr2 = nullptr;
			return false;
		}
	}
	delete[] counterArr1;
	delete[] counterArr2;
	counterArr1 = nullptr;
	counterArr2 = nullptr;
	return true;
}

//changing any uppercase letters to lowercase
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

//gets rid of spaces and punctuation and returns updated string
//uses lowerCase function
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
