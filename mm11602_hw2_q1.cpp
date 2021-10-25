#include <iostream>

//Write	a	program	that	asks the	user	to	enter	a	number	of	quarters, dimes, nickelsand
//penniesand then	outputs	the	monetary	value	of	the	coins	in	the	format	of	dollarsand
//remaining	cents.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	number of	coins :
//#	of	quarters : 13
//#	of	dimes : 4
//#	of	nickels : 11
//#	of	pennies : 17
//The total	is	4 dollars and 37 cents

const int QUARTER_VALUE{ 25 };
const int DIME_VALUE{ 10 };
const int NICKEL_VALUE{ 5 };
const int DOLLAR_VALUE{ 100 };

int main()
{
	int number_of_quarters{}, number_of_dimes{}, number_of_nickels{}, number_of_pennies{}, number_of_dollars{}, number_of_cents{}, total_cents{};

	std::cout << "Please enter number of coins:" << std::endl;
	std::cout << "# of quarters: ";
	std::cin >> number_of_quarters;
	std::cout << "# of dimes: ";
	std::cin >> number_of_dimes;
	std::cout << "# of nickels: ";
	std::cin >> number_of_nickels;
	std::cout << "# of pennies: ";
	std::cin >> number_of_pennies;

	total_cents = (number_of_quarters * QUARTER_VALUE) + (number_of_dimes * DIME_VALUE) + (number_of_nickels * NICKEL_VALUE) + number_of_pennies;

	number_of_dollars = total_cents / DOLLAR_VALUE;
	number_of_cents = total_cents % DOLLAR_VALUE;

	std::cout << "The total is " << number_of_dollars << " dollars and " << number_of_cents << " cents" << std::endl;

}