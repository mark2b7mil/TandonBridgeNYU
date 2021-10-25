#include <iostream>
#include <cmath>

//Write a program that reads from the user a positive integer(in a decimal representation), and
//prints its binary(base 2) representation.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Enter decimal number :
//76
//The	binary	representation	of	76	is	1001100
//Implementation Requirements :
//1. You are supposed to implement the algorithm that converts to base 2. You should not use
//any string or special cout functionalities to make the conversion.
//2. You are not allowed to use arrays.

int main()
{
	//declaring and initializing variables, using unsigned long long int because for large decimal numbers
	//normal int quickly runs out of space.
	int decimalNumber{}, tensPower{};
	unsigned long long int binaryNumber{};

	std::cout << "Enter a decimal number:" << std::endl;
	std::cin >> decimalNumber;

	//beginning cout here to not have to use a different variable to print the original decimal number
	std::cout << "The binary representation of " << decimalNumber << " is ";

	//as long as our input number is greater than zero we are looping through. with every loop we are
	//checking whether our input mod 2 is 1, and if so we add 1 times 10 to the power of a counter variable
	//that starts at 0. with every next loop, regardless if the if statement runs, we divide our input by 2,
	//and increment our tens power counter so we can add a 1 or zero to the next number in binary form.
	while (decimalNumber > 0) {
		if (decimalNumber % 2 == 1) {
			binaryNumber += 1 * pow(10, tensPower);
		}
		decimalNumber /= 2;
		tensPower += 1;
	}

	std::cout << binaryNumber << std::endl;
}