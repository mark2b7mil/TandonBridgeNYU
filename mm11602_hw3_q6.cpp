#include <iostream>
#include <string>

//Question	6:
//Write	a	program	that	computes	the	cost	of	a	long - distance	call.The	cost	of	 the	call	is
//determined	according	to	the	following	rate	schedule :
//• Any	call	started	between	8 : 00	A.M. and 6 : 00	P.M., Monday	through	Friday, is	billed	at	a
//rate	of	$0.40	per	minute.
//• Any	call	starting	before	8 : 00	A.M. or after	6 : 00	P.M., Monday	through	Friday, is	charged
//at	a	rate	of	$0.25	per	minute.
//• Any	call	started	on	a	Saturday or Sunday	is	charged	at	a	rate	of	$0.15	per	minute.
//The	input	will	consist	of	the	day	of	the	week, the	time	the	call	started, and the	length	of	the
//call	in	minutes.
//The	output	will	be	the	cost	of	the	call.
//Notes :
//	1. The	time	is	to	be	input	in	24 - hour	notation, so	the	time	1 : 30	P.M.is	input	as	 13 : 30
//	2. The	day	of	the	week	will	be	read	as	one	of	the	following	two	character	string : Mo		Tu
//	We		Th		Fr		Sa		Su
//	3. The	number	of	minutes	will	be	input	as	a	positive	integer.

const double WEEKEND_RATE{ 0.15 };
const double WEEKDAY_PEAK_HOURS{ 0.40 };
const double WEEKDAY_OFF_PEAK{ 0.25 };

int main()
{
	int hours{}, minutes{}, length_of_call{};
	std::string day_of_week{};
	char temp{};
	double cost_of_call{};

	std::cout << "What day of the week was the call made (please write either Mo, Tu, We, Th, Fr, Sa, Su): ";
	std::cin >> day_of_week;
	std::cout << "What time did the call start (please input in 24-hour notation e.g. 1:30 PM is input as 13:30): ";
	std::cin >> hours >> temp >> minutes;
	std::cout << "How long was the call (in minutes): ";
	std::cin >> length_of_call;

	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);

	//I'm first grouping the weekend and weekday options with the next if else statement. First group is for the weekend
	if (day_of_week == "Sa" || day_of_week == "sa" || day_of_week == "su" || day_of_week == "Su") {
		cost_of_call = (double)(length_of_call * WEEKEND_RATE);
		std::cout << "The cost of the call was $" << cost_of_call << std::endl;
	}
	else {
		//For the weekday if the call happens between 8 am and 6 pm (18:00) the cost of call is .40 per minute. I'm using a less than 18 because the moment the hour turns to 18 it's after 6 pm
		if (hours >= 8 && hours < 18) {
			cost_of_call = (double)(length_of_call * WEEKDAY_PEAK_HOURS);
			std::cout << "The cost of the call was $" << cost_of_call << std::endl;
		}
		//This else statement accounts for all times outside of 8 am to 6 pm on the weekdays
		else {
			cost_of_call = (double)(length_of_call * WEEKDAY_OFF_PEAK);
			std::cout << "The cost of the call was $" << cost_of_call << std::endl;
		}
	}

}