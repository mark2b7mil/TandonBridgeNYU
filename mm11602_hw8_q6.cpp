#include <iostream>
#include <string>

//takes a string and examines each substring using checkifnum and converttox. 
//checks every substring by checking for first character and calculating how long the string is until the next blank space
//uses distance until next blank space to store in counter for looping over substring
void checkString(std::string& str);
//checks if the subtring is a string consisting of only numbers
bool checkIfNum(std::string str, int start, int end);
//takes a substring and converts it to x's
void convertToX(std::string& str, int start, int end);

int main()
{

	std::string text;

	std::cout << "Please enter a line of text:" << std::endl;
	getline(std::cin, text);
	checkString(text);
	std::cout << text << std::endl;

}

//takes a string and examines each substring using checkifnum and converttox. 
//checks every substring by checking for first character and calculating how long the string is until the next blank space
//uses distance until next blank space to store in counter for looping over substring
void checkString(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '\0' && str[i] != ' ') {
			int endCounter = 0;
			for (int g = i; str[g] != ' ' && str[g] != '\0' && str[g] >= '0'; g++) {
				endCounter++;
			}
			if (checkIfNum(str, i, endCounter)) {
				convertToX(str, i, endCounter);
			}
			i += endCounter;
		}
	}
}

//checks if the subtring is a string consisting of only numbers
bool checkIfNum(std::string str, int start, int end) {
	for (int k = start; k < start+end; k++) {
		if (str[k] < '0' || str[k] > '9') {
			return false;
		}
	}
	return true;
}

//takes a substring and converts it to x's
void convertToX(std::string& str, int start, int end) {
	for (int j = start; j < start+end; j++) {
		str[j] = 'x';
	}
}
