#include <iostream>
#include <string>

std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
int wordCounter(std::string sentence);
void printStringArray(std::string str[], int strArrSize);

int main()
{
	std::string sentence;
	int outWordsArrSize = 0;
	std::string* strArr = nullptr;

	std::cout << "Please enter a sentence" << std::endl;
	std::getline(std::cin, sentence);
	strArr = createWordsArray(sentence, outWordsArrSize);
	printStringArray(strArr, outWordsArrSize);
}

/*
loops over elements in str and prints each element
*/
void printStringArray(std::string str[], int strArrSize) {
	std::cout << "[ ";
	for (int i = 0; i < strArrSize; i++) {
		std::cout << '"' << str[i] << '"' << ' ' ;
	}
	std::cout << "]";
}

/*
initializes a new array with the size of the amount of words in the sentence, using the wordCounter function.
then it loops over the string of the sentence and when the iterator meets a character the character is appended to a temp string, when the iterator
then gets to a space or appropriate puncuation it gets out of the loop, the temp string is added to the array that holds strings
*/
std::string* createWordsArray(std::string sentence, int& outWordsArrSize)
{
	int newArrSize = wordCounter(sentence);
	std::string* strArr = new std::string[newArrSize];
	int arrCounter = 0;

	for (int i = 0; i < sentence.length() && arrCounter < newArrSize; i++) {
		if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
			std::string tempStr;
			int letterCounter = 0;
			for (int k = 0; sentence[k + i] != ' ' && sentence[k + i] != ',' && sentence[k + i] != '.' && sentence[k + i] != '\0' && sentence[k + i] != '!' && sentence[k + i] != '?'; k++) {
				letterCounter++;
				tempStr += sentence[k + i];
			}
			i += letterCounter;
			strArr[arrCounter] = tempStr;
			arrCounter++;
		}
	}
	outWordsArrSize = newArrSize;
	return strArr;
}

/*
counts all words in a string by looping until a character is found, then a new loop starts that terminates when a space or appropriate punctuation is found
then the letter counter is added to the overall sentence counter, ensuring n runtime.
*/
int wordCounter(std::string sentence) {
	int wordCount = 0;
	for (int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
			int letterCounter = 0;
			for (int k = 0; sentence[k + i] != ' ' && sentence[k + i] != ',' && sentence[k + i] != '.' && sentence[k + i] != '\0'; k++) {
				letterCounter++;
			}
			i += letterCounter;
			wordCount++;
		}
	}
	return wordCount;
}
