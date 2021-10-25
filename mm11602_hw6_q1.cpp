#include <iostream>

int fib(int n);

int main()
{
	int input{};

	std::cout << "Please enter a positive integer: ";
	std::cin >> input;
	std::cout << fib(input) << std::endl;
}

int fib(int n) {
	//declaring/initializing variables
	int counter{ 2 }, first{ 1 }, second{ 1 }, temp{};

	//for loop only starts if input n is gretaer than counter, otherwise 1 is output from variable named second
	for (counter; counter < n; counter++) {
		temp = first + second;
		first = second;
		second = temp;
	}

	return second;
}