#include <iostream>

//Write	a	program	that	asks the	user	to	enter	an	amount	of	money	in	the	format	of	dollarsand
//remaining	cents.The	program	should	calculateand print	the	minimum	number	of	coins
//(quarters, dimes, nickelsand pennies)	that	are	equivalent	to	the	given	amount.
//Hint:	In	order	to	find	the	minimum	number	of	coins, first	find	the	maximum	number	of
//quarters	that	fit	in	the	given	amount	of	money, then	find	the	maximum	number	of	dimes
//that	fit	in	the	remaining	amount, and so	on.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	your	amount	in	the	format	of	dollarsand cents	separated	by	a	space :
//4		37
//4	dollars and 37	cents	are :
//17	quarters, 1	dimes, 0	nickels and 2	pennies

const int QUARTER_VALUE{ 25 };
const int DIME_VALUE{ 10 };
const int NICKEL_VALUE{ 5 };
const int DOLLAR_VALUE{ 100 };

int main()
{
	int number_of_quarters{}, number_of_dimes{}, number_of_nickels{}, number_of_pennies{}, number_of_dollars{}, number_of_cents{}, total_cents{};

	std::cout << "Please enter your amount in the format of dollars and cents separated by a space	:" << std::endl;
	std::cin >> number_of_dollars >> number_of_cents;
	std::cout << number_of_dollars << " dollars and " << number_of_cents << " cents are:" << std::endl;

	total_cents = (number_of_dollars * DOLLAR_VALUE) + number_of_cents;
	number_of_quarters = total_cents / QUARTER_VALUE;
	total_cents %= QUARTER_VALUE;
	number_of_dimes = total_cents / DIME_VALUE;
	total_cents %= DIME_VALUE;
	number_of_nickels = total_cents / NICKEL_VALUE;
	total_cents %= NICKEL_VALUE;

	std::cout << number_of_quarters << " quarters, " << number_of_dimes << " dimes, " << number_of_nickels << " nickels and " << total_cents << " pennies";

	return 0;
}