#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(std::string str);

int main()
{
	std::string word;

	std::cout << "Please enter a word: ";
	std::cin >> word;
	if (isPalindrome(word)) {
		std::cout << word << " is a palindrome." << std::endl;
	}
	else {
		std::cout << word << " is not a palindrome." << std::endl;
	}

}

//checking if str is palidrome by iterating from front and back
bool isPalindrome(std::string str) {
	int length = str.length();
	int frontIterator = 0, backIterator = length -1, test = 0;
	
	//if there is an uppercase letter converting to lowercase
	for (int i = 0; i < length; i++) {
		str[i] = tolower(str[i]);
	}
	while (str[frontIterator] == str[backIterator] && backIterator > frontIterator) {
		test++;
		backIterator--;
		frontIterator++;
	}
	if (test == length / 2) {
		return true;
	}
	else {
		return false;
	}

}