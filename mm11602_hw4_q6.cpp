#include <iostream>

//Write	a	program	that	asks	the user	to	input	a	positive	integer	n, and print	all	of	the	numbers
//from	1	to	n that	have	more	even	digits	than	odd	digits.
//For	example, if	n = 30, the	program	should	print :
//2
//4
//6
//8
//20
//22
//24
//26
//28

int main()
{

	int input, evenNumbers, oddNumbers;

	std::cout << "Please enter a positive integer: ";
	std::cin >> input;

	//outer for loop is to iterate over all positive numbers up until and including the input
	for (int i{1}; i <= input; i++) {
		//after every loop the even count and odd count should be reinitialized to zero
		evenNumbers = 0;
		oddNumbers = 0;
		//inner for loop is to iterate over all digits of the current value of i from the outer loop
		//dividing the number by 10 after every loop drops the right most digit
		for (int testNum{ i }; testNum != 0; testNum /= 10) {
			//if else if statements are testing for evenness and if it's even we increment evenNumbers
			//if not even then we increment oddNumbers
			if (testNum % 2 == 0) {
				evenNumbers += 1;
			}
			else if (testNum % 2 != 0){
				oddNumbers += 1;
			}
		}
		if (evenNumbers > oddNumbers) {
			std::cout << i << std::endl;
		}
	}
}