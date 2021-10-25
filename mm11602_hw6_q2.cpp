#include <iostream>

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main()
{
	int treeSize;
	char symbol;

	std::cout << "Please enter the size of the tree as a positive integer, and the symbol used to draw the tree, separated by a space:" << std::endl;
	std::cin >> treeSize >> symbol;
	std::cout << std::endl;

	printPineTree(treeSize, symbol);
}

//printing shifted triangle 
void printShiftedTriangle(int n, int m, char symbol) {
	//looping over number of lines
	for (int lineNum{ 1 }; lineNum <= n; lineNum++) {
		//looping over number of spaces
		for (int spaces{}; spaces < m + n - lineNum; spaces++) {
			std::cout << " ";
		}
		//looping over number of symbols
		for (int symb{}; symb < lineNum * 2 - 1; symb++) {
			std::cout << symbol;
		}
		std::cout << std::endl;
	}
}

//using printShiftedTriangle to output pine tree based on new n and symbol as function arguments
//using for loop to update arguments for printShiftedTriangle based rules for printing the tree
void printPineTree(int n, char symbol) {
	for (int triangles{}, lines{ 2 }, treeSpaces{n-1}; triangles < n; triangles++, lines++, treeSpaces--) {
		printShiftedTriangle(lines, treeSpaces, symbol);
	}
}