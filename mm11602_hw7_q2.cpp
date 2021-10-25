#include <iostream>
#include <cmath>

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
	int input{}, outCountDivs{}, outSumDivs{};

	std::cout << "Please enter a positive integer greater than or equal to 2: ";
	std::cin >> input;

	std::cout << "All perfect numbers between 2 and " << input << ":" << std::endl;
	for (int i{ 2 }; i <= input; i++) {
		if (isPerfect(i)) {
			std::cout << i << std::endl;
		}
	}
	std::cout << std::endl;
	//using analyze divisors function to print amicable numbers
	std::cout << "All pairs of amicable numbers between 2 and " << input << ":" << std::endl;
	for (int i{ 2 }; i <= input; i++) {
		analyzeDividors(i, outCountDivs, outSumDivs);
		if (outSumDivs < input && i < outSumDivs && i != outSumDivs) {
			int tempOutCount{}, tempOutSum{};
			analyzeDividors(outSumDivs, tempOutCount, tempOutSum);
			if (i == tempOutSum) {
				std::cout << "[" << i << ", " << outSumDivs << "]" << std::endl;
			}
		}
	}
}

//sqrt runtime for dividors function, returning by reference
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	int tempOutSum{}, tempOutCount{};
	int funcNum = sqrt(num);
	for (int i{ 1 }; i <= funcNum; i++) {
		if (num % i == 0) {
			tempOutSum += i;
			tempOutCount++;
			if (i > 1 && num/i != i) {
				tempOutSum += num / i;
				tempOutCount++;
			}
		}
	}
	outSumDivs = tempOutSum;
	outCountDivs = tempOutCount;
}

//calling analyzeDividors to compare sum of divs to original num
bool isPerfect(int num) {
	int outCount{}, outSum{};
	analyzeDividors(num, outCount, outSum);
	if (outSum == num) {
		return true;
	}
	else {
		return false;
	}
}