#include <iostream>

int main()
{
	int posInt;

	std::cout << "Please enter a positive integer:" << std::endl;
	std::cin >> posInt;

	//outer for loop variable is increasing by 1 everytime we start a new line, 
	//and the inner for loop variable is increasing by 1 everytime we multiply the inner loop variable by the outer loop variable
	for (int i{1}; i <= posInt; i++) {
		for (int k{1}; k <= posInt; k++) {
			std::cout << i * k << "\t";
		}
		std::cout << std::endl;
	}
}