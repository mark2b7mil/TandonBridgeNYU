#include <iostream>

//Write a program that asks the user to input a positive integer n, and prints a textual image of an
//hourglass made of 2n lines with asterisks.

int main()
{
	std::string space{ " " };
	char star{ '*' };
	int input{}, spaceNumber{}, starNumber{}, lineNumber{ 1 };
	
	std::cout << "Enter a positive integer: ";
	std::cin >> input;

	//making the number of stars equal to one less than two times the input number for outputting to 
	//be set correctly at the beginning
	starNumber = (input * 2) - 1;

	//outside for loop is used to loop over the total lines of output (2n)
	for (int i{ 0 }; i < input*2; i++) {
		//inside for loops are used to iterate over the number of spaces and stars to be printed per line
		for (int j{}; j < spaceNumber; j++) {
				std::cout << space;
		}
		for (int k{}; k < starNumber; k++) {
				std::cout << star;
		}

		std::cout << std::endl;
		//if else if statements are to determine the changes in star and space numbers for every line change
		//not written explicitly is when the line number is the same as our input, nothing changes
		if (lineNumber < input) {
			spaceNumber += 1;
			starNumber -= 2;
		}
		else if (lineNumber > input) {
			spaceNumber -= 1;
			starNumber += 2;
		}
		lineNumber += 1;
	}
}