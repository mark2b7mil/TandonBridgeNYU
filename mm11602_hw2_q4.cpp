#include <iostream>
#include <iomanip>

//Write	a	program	that	reads	from	the	user	two positive	integers, and prints	the	result	of
//when	we add, subtract	multiply, divide, divand mod	them.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	two	positive	integers, separated	by	a	space :
//14			4
//14 + 4 = 18
//14 – 4 = 10
//14 * 4 = 56
//14 / 4 = 3.5
//14	div	4 = 3
//14	mod	4 = 2

int main()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	int int1{}, int2{};
	std::cout << "Please enter two positive integers, separated by a space: " << std::endl;
	std::cin >> int1 >> int2;
	std::cout << int1 << " + " << int2 << " = " << int1 + int2 << std::endl;
	std::cout << int1 << " - " << int2 << " = " << int1 - int2 << std::endl;
	std::cout << int1 << " * " << int2 << " = " << int1 * int2 << std::endl;
	std::cout << int1 << " / " << int2 << " = " << (double)int1 / (double)int2 << std::endl;
	std::cout << int1 << " div " << int2 << " = " << int1 / int2 << std::endl;
	std::cout << int1 << " mod " << int2 << " = " << int1 % int2 << std::endl;
}