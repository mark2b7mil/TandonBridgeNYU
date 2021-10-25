#include <iostream>
#include <cmath>

void printDivisors(int num);

int main()
{

	int input{};
	std::cout << "Please enter a positive integer >= 2: ";
	std::cin >> input;
	printDivisors(input);

}

//function loops up over the square root of the input and then down to get all the devisors of num
void printDivisors(int num) {
	for (int i{ 1 }; i <= static_cast<int>(sqrt(num)); i++) {
		if (num % i == 0) {
			std::cout << i << " ";
		}
	}
	for (int k{ static_cast<int>(sqrt(num))}; k > 0; k--) {
		//not including the square root of num in this if statement because the previous for loop takes care of that case
		if (num % k == 0 && num / k != k) {
				std::cout << num/k << " ";
		}
	}
}