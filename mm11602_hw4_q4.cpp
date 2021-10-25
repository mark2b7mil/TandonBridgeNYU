#include <iostream>
#include <cmath>

//Question 4:
//Write two versions of a program that reads a sequence of positive integers from the user,
//calculates their geometric mean, and print the geometric mean.
//Notes :
//	2. In	order	to	calculate	the	n - th root	of	a	number,	you	should	call	the	pow function,	located
//	in	the	cmath library.
//	Your two versions should read the integer sequence in two ways :
//	a) First read the length of the sequence.
//	For example, an execution would look like :
//	Please enter the length of the sequence : 3
//	Please enter your sequence :
//	1
//	2
//	3
//	The geometric mean is : 1.8171
//	b) Keep reading the numbers until - 1 is entered.
//	For example, an execution would look like :
//	Please enter a non - empty sequence of positive integers, each one in a separate line.End your
//	sequence by typing - 1 :
//	1
//	2
//	3
//	- 1
//	The geometric mean is : 1.8171

int main()
{
	//declaring and initializing variables, im initializing separate input and total variables because if you run the two 
	//versions one after the other using th same total and input variables, it would output incorrectly
	//and i think it increases readability slightly 
	//using larger data type for totals because these values can get big fast
	int sequenceLength{}, input1{}, input2{ 1 }, inputCounter{}, inputCounter2{};
	double  geoMean{}, nthRoot{};
	unsigned long long int total1{ 1 }, total2{ 1 };

	std::cout << "Please enter the length of the sequence: ";
	std::cin >> sequenceLength;
	std::cout << "Please enter your sequence:" << std::endl;
	
	//using a for loop to get the number of inputs specified in the sequence length variable using a variable i 
	//that is initialized in the for loop arguments. also updating total for each input
	for (int i{}; i < sequenceLength; i++) {
		std::cin >> input1;
		total1 *= input1;
	}
	
	//calculating the nth root with the input sequence length and casting to double, calculating geometric mean underneath
	nthRoot = (double)1 / sequenceLength;
	geoMean = pow(total1, nthRoot);

	std::cout << "The geometric mean is: " << geoMean << std::endl;



	std::cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << std::endl;
	//in the while loop im placing the total calculation before the input so that when -1 is typed we don't use that for the total
	while (input2 > 0) {
		total2 *= input2;
		std::cin >> input2;
		//if we type -1 we should not add that to the counter, it's not a valid input, hence the if statement
		if (input2 > 0) {
			inputCounter2 += 1;
		}
	}

	//calculating the nth root with the input sequence length and casting to double, calculating geometric mean underneath
	nthRoot = (double)1 / inputCounter2;
	geoMean = pow(total2, nthRoot);

	std::cout << "The geometric mean is: " << geoMean << std::endl;
}