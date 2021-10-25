#include <iostream>

//Write	a	program	that :
//• Asks	the	user	for	their	name.
//• Asks	the	user	to	input	their	graduation	year.
//• Asks	the	user	to	input	the	current	year.
//Assume	the	student	is	in	a	four - year	undergraduate	program.Display	the	current	status	the
//student	is	in.Possible	status	include : not in	college	yet, freshman, sophomore, junior, senior,
//graduated.
//Note : If	graduation	year	equals	to	current	year, status	is	‘Graduated’;	if	graduation	year	is
//four	years	after	current	year, status	is	‘Freshman’, etc.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	your	name : Jessica
//Please	enter	your	graduation	year : 2019
//Please	enter	current	year : 2015
//Jessica, you	are	a	Freshman

int main()
{
	std::string name{}, status{};
	int graduation_year{}, current_year{};

	std::cout << "Please enter your name: ";
	std::cin >> name;
	std::cout << "Please enter your graduation year: ";
	std::cin >> graduation_year;
	std::cout << "Please enter current year: ";
	std::cin >> current_year;

	//Using if else if else statement to establish the status of the person and then assigning a status to be printed at the end.
	if (current_year >= graduation_year) {
		status = "Graduated";
	}
	else if (current_year + 1 == graduation_year) {
		status = "a Senior";
	}
	else if (current_year + 2 == graduation_year) {
		status = "a Junior";
	}
	else if (current_year + 3 == graduation_year) {
		status = "a Sophomore";
	}
	else if (current_year + 4 == graduation_year) {
		status = "a Freshman";
	}
	else {
		status = "not in college yet";
	}

	std::cout << name << ", you are " << status << std::endl;
}