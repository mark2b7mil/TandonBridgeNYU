#include <iostream>

//Question	4:
//Define	the	following	constants :
//const int FLOOR_ROUND = 1;
//const int CEILING_ROUND = 2;
//const int ROUND = 3;
//Write	a	program	that	asks	the	user	to	enter	a	Real	number, then	it	asks	the	user	to	enter	the
//method	by	which	they	want	to	round	that number(floor, ceiling or to	the	nearest	integer).
//The	program	will	then	print	the	rounded	result.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	a	Real	number :
//4.78
//Choose	your	rounding method :
//1.	Floor	round
//2.	Ceiling	round
//3.	Round	to	the	nearest	whole	number
//2
//5
//Implementation	requirements :
//1. Use	a	switch statement.
//2. You	are	not allowed	to	include and use	the	math	library.

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
	double real_number{}, test_number{};
	int rounding_method{};
	int converted_number{};

	std::cout << "Please enter a Real number: ";
	std::cin >> real_number;
	std::cout << "Choose your rounding method:\n1. Floor Round\n2. Ceiling Round\n3. Round to nearest whole number" << std::endl;
	std::cin >> rounding_method;

	//Switch statement for determining which rounding method to use. Much of the logic is based on casting double to ints truncating the decimal values from the double
	switch (rounding_method) {
	case FLOOR_ROUND:
		//Breaking up the floor round into negaive and positive real number cases
		//Floor rounding for positive numbers is simple because casting from double to int will truncate the decimal digits
		if (real_number >= 0) {
			converted_number = (int)real_number;
			std::cout << converted_number << std::endl;
		}
		else {
			//The logic here is to subtract one from the real number input so that it will be less than the next smallest number so I can truncate the decimal digits
			//I am controlling for the case of already rounded numbers like 3.0, subtracting a 1 and truncating won't make sense becuase 3.0 doesn't round down to 2.0, even in floor rounding
			converted_number = (int)(real_number - 1);
			test_number = converted_number - real_number;
			if (test_number == -1) {
				std::cout << (int)real_number << std::endl;
			}
			else {
				std::cout << converted_number << std::endl;
			}
		}
		break;
	case CEILING_ROUND:
		//Breaking up the ceiling round into negaive and positive real number cases
		if (real_number >= 0) {
			//The logic here is to add one to the real number input so that it will be greater than the next number so I can truncate the decimal digits
			//I am controlling for the case of already rounded numbers like 3.0, adding a 1 and truncating won't make sense becuase 3.0 doesn't round up to 4.0, even in ceiling rounding
			converted_number = (int)(real_number + 1);
			test_number = converted_number - real_number;
			if (test_number == 1) {
				std::cout << (int)real_number << std::endl;
			}
			else {
				std::cout << converted_number << std::endl;
			}
		}
		else {
			//Ceiling rounding for negative numbers is easier because truncating the decimals will always get you the ceiling round of the real number
			converted_number = (int)real_number;
			std::cout << converted_number << std::endl;
		}
		break;
	case ROUND:
		//For rounding to nearest whole number I want to separate case of negative rounding and positive rounding
		//For positive rounding I am adding a .5 to the real number input and casting after, because it will truncate correctly if the real number input has a first decimal digit of .5 or more
		if (real_number >= 0) {
			real_number += .5;
			converted_number = (int)real_number;
			std::cout << converted_number << std::endl;
		}
		//Same logic as for positive number rounding just going the other way
		else {
			real_number -= .5;
			converted_number = (int)real_number;
			std::cout << converted_number << std::endl;
		}
		break;
	}


}