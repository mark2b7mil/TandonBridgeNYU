#include <iostream>

//Question 2:
//In this question we will use a simplified version of the Roman Numerals System to represent
//positive integers.
//The digits in this system are I, V, X, L, C, Dand M.Each digit corresponds to a decimal value, as
//showed in the following table :
//Roman digit I V X L C D M
//Decimal value 1 5 10 50 100 500 1000
//A number in the simplified Roman numerals system is a sequence of Roman digits, which follow
//these 2 rules :
//	1. The digits form a monotonically non - increasing sequence.That is the value of each digit is
//	less than or equal to the value of the digit that came before it.
//	For example, DLXXVI is a monotonically non - increasing sequence of Roman digits, but XIV is
//	not.
//	2. There is no limit on the number of times that ‘M’ can appear in the number.
//	‘D’, ‘L’and ‘V’ can each appear at most one time in the number.
//	‘C’, ‘X’and ‘I’ can each appear at most four times in the number.
//	For example : IIII, XVIIand MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman
//	numeral system, but IIIII, XIV, VVIand CCXLIII are not.
//	Write a program that reads from the user a(decimal) number, and prints it’s representation in
//	the simplified Roman numerals system.
//	Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Enter decimal number :
//147
//147 is CXXXXVII

int main()
{
	//initializing counter input variable along with all counters we need for each roman numeral
	int decimalNumber{}, vCounter{ 1 }, xCounter{ 4 }, lCounter{ 1 }, cCounter{ 4 }, dCounter{ 1 };

	std::cout << "Enter decimal number: " << std::endl;
	std::cin >> decimalNumber;

	std::cout << decimalNumber << " is ";

	//for as long as the input remains greater than zero we are looping through the series of if and if else 
	//statements that output roman digits from greatest to least.
	while (decimalNumber > 0) {
		//each if else if block takes the form of checking if the decimal number is greater than the corresponding value
		//of roman numeral and if so outputing that roman numeral and decreasing our input decimal number by the
		//value of the roman numeral added, i'm also decreasing the counter of each roman numeral for each use, if applicable
		if (decimalNumber >= 1000) {
			std::cout << "M";
			decimalNumber -= 1000;
		}
		else if (decimalNumber >= 500 && dCounter > 0) {
			std::cout << "D";
			decimalNumber -= 500;
			dCounter -= 1;
		}
		else if (decimalNumber >= 100 && cCounter > 0) {
			std::cout << "C";
			decimalNumber -= 100;
			cCounter -= 1;
		}
		else if (decimalNumber >= 50 && lCounter > 0) {
			std::cout << "L";
			decimalNumber -= 50;
			lCounter -= 1;
		}
		else if (decimalNumber >= 10 && xCounter > 0) {
			std::cout << "X";
			decimalNumber -= 10;
			xCounter -= 1;
		}
		else if (decimalNumber >= 5 && vCounter > 0) {
			std::cout << "V";
			decimalNumber -= 5;
			vCounter -= 1;
		}
		//we don't need a counter for the I numeral because it should naturally never output more than 4 times, if all other logic is sound
		else if (decimalNumber >= 1) {
			std::cout << "I";
			decimalNumber -= 1;
		}
		
	}

}