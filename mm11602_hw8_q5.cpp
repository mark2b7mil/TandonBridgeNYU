#include <iostream>
#include <string>

void printFormattedName(std::string fName, std::string mName, std::string lName);

int main()
{
	std::string firstName, middleName, lastName;

	std::cout << "Please enter your name is the format: first name, middle name, last name. Each name separated by a space please." << std::endl;
	std::cin >> firstName >> middleName >> lastName;
	printFormattedName(firstName, middleName, lastName);

}

//function takes string name inputs and arranges in correct order and only prints first letter of middle name followed by period
void printFormattedName(std::string fName, std::string mName, std::string lName) {
	std::string firstName = fName, middleName = mName, lastName = lName;
	std::cout << lastName << ", " << firstName << " " << middleName[0] << "." << std::endl;
}