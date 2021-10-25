#include <iostream>

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool determineLeapYear(int year);

const int WEEK_DAYS = 7;
const int MONTHS_IN_YEAR = 12;

int main()
{
	int year{}, startDay{};

	std::cout << "To print a yearly calendar please enter a year (e.g. 2021), followed by a space and a starting day from 1-7 (e.g. Monday = 1, Tuesday = 2,.... Sunday = 7)" << std::endl;
	std::cin >> year >> startDay;
	printYearCalender(year, startDay);

}
//prints a month and returns the next day for use in yearly calendar print
int printMonthCalender(int numOfDays, int startingDay) {
	int dayCounter = numOfDays;
	int dayStart = startingDay;

	std::cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << std::endl;

	//spacing for start day of the month
	for (int i{ 1 }; i <= dayStart - 1; i++) {
		std::cout << "\t";
	}

	//outputting day numbers
	for (int k{ 1 }; k <= dayCounter; k++) {

		std::cout << k << "\t";
		dayStart++;

		//making sure daystart variable doesnt go above days of the week
		if (dayStart > WEEK_DAYS) {
			std::cout << std::endl;
			dayStart = 1;
		}
	}
	std::cout << std::endl;

	return dayStart;
}

//determining whether input year is leap year
bool determineLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else
		return false;
}

//looping through all months of the year and using printMonthCalendar function to print each month
void printYearCalender(int year, int startingDay) {
	//using newStartDay to keep track of the last day of each month and start printing numbers in correct place for next month
	int newStartDay{};
	int numOfDays{};
	for (int month{ 1 }; month <= MONTHS_IN_YEAR; month++) {
		std::cout << std::endl;
		switch (month) {
		case 1:
			std::cout << "January " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, startingDay);
			break;
		case 2:
			std::cout << "February " << year << std::endl;
			if (determineLeapYear(year)) {
				numOfDays = 29;
			}
			else {
				numOfDays = 28;
			}
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 3:
			std::cout << "March " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 4:
			std::cout << "April " << year << std::endl;
			numOfDays = 30;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 5:
			std::cout << "May " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 6:
			std::cout << "June " << year << std::endl;
			numOfDays = 30;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 7:
			std::cout << "July " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 8:
			std::cout << "August " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 9:
			std::cout << "September " << year << std::endl;
			numOfDays = 30;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 10:
			std::cout << "October " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 11:
			std::cout << "November " << year << std::endl;
			numOfDays = 30;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		case 12:
			std::cout << "December " << year << std::endl;
			numOfDays = 31;
			newStartDay = printMonthCalender(numOfDays, newStartDay);
			break;
		}
	}
}