#include <iostream>

//Write	two versions of	a	program	that	reads	a	positive	integer	n, and prints	the	first	n even
//numbers.
//a) In	the	first, use	a	while loop.
//b) In	the	second, use	a	for loop.
//Each	section	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	a	positive	integer : 3
//2
//4
//6

int main()
{
	int integerCounter{};
	int counter{1};

	std::cout << "Please enter a positive integer: ";
	std::cin >> integerCounter;

	//comparing counter to 2 times the integerCounter input allows us to iterate over the odd and even integers without running out of loops
	while (counter <= (integerCounter*2)) {
		//if the counter mod 2 is 0 then the number is even and we should print it
		if (counter % 2 == 0) {
			std::cout << counter << std::endl;
		}
		counter++;
	}

	//initializing i as counter variable in the for loop arguments
	for (int i{1}; i <= (integerCounter*2); i++) {
		//if the counter mod 2 is 0 then the number is even and we should print it
		if (i % 2 == 0) {
			std::cout << i << std::endl;
		}
	}
}