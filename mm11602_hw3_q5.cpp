#include <iostream>

//Write	a	program	that	prompts	for	weight(in	pounds) and height(in	inches)	of	a	person, and
//prints	the	weight	status	of	that	person.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Please	enter	weight(in	pounds) : 135
//Please	enter	height(in	inches) : 71
//The	weight	status	is : Normal
//Note : 1	pound	is	0.453592	kilograms and 1	inch	is	0.0254	meters.

int main()
{
	double weight{}, height{};

	std::cout << "Please enter weight (in pounds): ";
	std::cin >> weight;
	std::cout << "Please enter height (in inches): ";
	std::cin >> height;

	//converting the weight and height to kilos and meters, 
	weight *= 0.453592;
	height *= 0.0254;

	//calculating bmi with converted weight and height
	double bmi = weight / (height * height);

	//outputting based on bmi
	if (bmi < 18.5) {
		std::cout << "The weight status is: Underweight" << std::endl;
	}
	else if (bmi >= 18.5 && bmi < 25) {
		std::cout << "The weight status is: Normal" << std::endl;
	}
	else if (bmi >= 25 && bmi < 30) {
		std::cout << "The weight status is: Overweight" << std::endl;
	}
	else {
		std::cout << "The weight status is: Obese" << std::endl;
	}

}