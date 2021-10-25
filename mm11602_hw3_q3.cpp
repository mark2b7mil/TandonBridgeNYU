#include <iostream>
#include <cmath>

//Write	a	program	that	does	the	following :
//• Ask	user	to	input	three	Real numbers	a, band c.They	represent	the	parameters	of	a
//quadratic	equation	ax^2 + bx + c = 0
//• Classify	to	one	of	the	following :
//-’Infinite	number	of	solutions’(for	example, 0x^2+ 0x + 0 = 0 has	infinite
//	number	of	solutions)
//	- ’No	solution’(for	example, 0x^2+ 0x + 4 = 0 has	no	solution)
//	- ’No	real	solution’(for	example, x^2+ 4 = 0 has	no	real	solutions)
//	- ’One	real	solution’
//	- ’Two	real	solutions’
//	• In	cases	there	are	1 or 2	real	solutions, also	print	the	solutions.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	value	of	a : 1
//Please	enter	value	of	b : 4
//Please	enter	value	of	c : 4
//This	equation	has	a	single	real	solution	x = -2.0

int main()
{
	double a{}, b{}, c{}, solution_1{}, solution_2{};

	std::cout << "Please enter value of a: ";
	std::cin >> a;
	std::cout << "Please enter value of b: ";
	std::cin >> b;
	std::cout << "Please enter value of c: ";
	std::cin >> c;

	//establishing discriminant in the quadratic equation to make if else if statments easier to understand and set up
	double discriminant{ (b * b) - (4 * a * c) };

	//first if statement establishes whether a is 0 and if not then using the discriminant to figure out how many solutions there are and what they are
	if (a != 0) {
		if (discriminant > 0) {
			solution_1 = (-b + sqrt(discriminant)) / (2 * a);
			solution_2 = (-b - sqrt(discriminant)) / (2 * a);
			std::cout << "This equation has two real solutions x=" << solution_1 << " or x=" << solution_2 << std::endl;
		}
		else if (discriminant < 0) {
			std::cout << "This equation has no real solution" << std::endl;
		}
		else {
			solution_1 = -b / (2 * a);
			if (solution_1 == -0) {
				solution_1 = 0;
			}
			std::cout << "This equation has one real solution x=" << solution_1 << std::endl;
		}
	}
	else {
		if (a == 0 && b == 0 && c == 0) {
			std::cout << "This equation has an infinite number of solutions" << std::endl;
		}
		else if (a == 0 && b == 0 && c != 0) {
			std::cout << "This equation has no solution" << std::endl;
		}
		//When a is 0 and the other values aren't then the equation is linear and has one solution
		else if (a == 0 && b != 0 && c != 0) {
			solution_1 = -(c / b);
			std::cout << "This equation is not quadratic, but linear, and has one solution x=" << solution_1 << std::endl;
		}

	}
}