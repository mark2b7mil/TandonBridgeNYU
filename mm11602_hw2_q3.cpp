#include <iostream>

//Suppose	Johnand Bill	worked for	some	timeand we	want	to	calculate	the	total	time	both	of
//them	worked.Write	a	program	that	reads	number	of	days, hours, minutes	each	of	them
//worked, and prints	the	total	time	both	of	them	worked	together	as	days, hours, minutes.
//Hint: Try	to	adapt	the	elementary	method	for	addition	of	numbers	to	this	use.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	the	number	of	days	John	has	worked : 2
//Please	enter	the	number	of	hours	John	has	worked : 12
//Please	enter	the	number	of	minutes	John	has	worked : 15
//Please	enter	the	number	of	days	Bill	has	worked : 3
//Please	enter	the	number	of	hours	Bill	has	worked : 15
//Please	enter	the	number	of	minutes	Bill	has	worked : 20
//The	total	time	both	of	them	worked	together	is : 6	days, 3	hours and 35 minutes.

const int MINUTES_IN_DAY{ 1440 };
const int MINUTES_IN_HOUR{ 60 };

int main()
{
	int number_of_days{}, number_of_hours{}, number_of_minutes{}, total_minutes{}, total_days{}, total_hours{};

	std::cout << "Please enter the number of days John has worked: ";
	std::cin >> number_of_days;
	std::cout << "Please enter the number of hours John has worked: ";
	std::cin >> number_of_hours;
	std::cout << "Please enter the number of minutes John has worked: ";
	std::cin >> number_of_minutes;
	total_minutes = MINUTES_IN_DAY * number_of_days + MINUTES_IN_HOUR * number_of_hours + number_of_minutes;
	std::cout << "Please enter the number of days Bill has worked: ";
	std::cin >> number_of_days;
	std::cout << "Please enter the number of hours Bill has worked: ";
	std::cin >> number_of_hours;
	std::cout << "Please enter the number of minutes Bill has worked: ";
	std::cin >> number_of_minutes;

	total_minutes += MINUTES_IN_DAY * number_of_days + MINUTES_IN_HOUR * number_of_hours + number_of_minutes;
	total_days = total_minutes / MINUTES_IN_DAY;
	total_minutes %= MINUTES_IN_DAY;
	total_hours = total_minutes / MINUTES_IN_HOUR;
	total_minutes %= MINUTES_IN_HOUR;

	std::cout << "The total time both of them worked together is: " << total_days << " days, " << total_hours << " hours and " << total_minutes << " minutes." << std::endl;

}