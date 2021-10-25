#include <iostream>

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main()
{
	int n;
	std::cout << "Input a positive integer: ";
	std::cin >> n;
	printTriangle(n);
	std::cout << std::endl;
	printOpositeTriangles(n);
	std::cout << std::endl;
	printRuler(n);
}

/*
recursively prints a triangle by recursively going down to the base case of 1 and when it pops out of a instance of printTri
an appropraite number of stars are printed according to the value of n in the current stack copy of printTri
*/
void printTriangle(int n)
{
	if (n == 1) {
		std::cout << '*' << std::endl;
	}
	else {
		printTriangle(n - 1);
		for (int i = 0; i < n; i++) {
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}

/*
recursively prints an opposite triangle, first prints n number of stars and then calls itself recursively which prints n-1 number of triangles
after each stack frame pops off, n number of stars is printed again.
*/
void printOpositeTriangles(int n)
{
	if (n == 1) {
		std::cout << '*';
	}
	else {
		for (int i = 0; i < n; i++) {
			std::cout << '*';
		}
		std::cout << std::endl;
		printOpositeTriangles(n - 1);
		std::cout << std::endl;
		if (n == 2) {
			std::cout << '*' << std::endl;
		}
		for (int i = 0; i < n; i++) {
			std::cout << '*';
		}
	}
}

/*
Prints a ruler according to input n. For n, printRuler calls for n-1, printing '-' then printing n '-', and the number depends on the stack frame you're on
The second printRuler recursive call is then called to account for the second half of the ruler.
*/
void printRuler(int n) 
{
	if (n == 1) {
		std::cout << '-' << std::endl;
	}
	else {
		printRuler(n - 1);
		for (int i = 0; i < n; i++) {
			std::cout << '-';
		}
		std::cout << std::endl;
		printRuler(n - 1);
	}
}