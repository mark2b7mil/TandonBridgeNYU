#include <iostream>

double eApprox(int n);

int main()
{
	std::cout.precision(30);

	for (int n = 1; n <= 15; n++) {
		std::cout << "n = " << n << '\t' << eApprox(n) << std::endl;
	}

	return 0;
}

//calculating e by keeping the previous denominator in variable tempDenom, this keeps run time as linear (n)
double eApprox(int n) {
	double e(1);
	for (double i(1), tempDenom(1); i < static_cast<double>(n)+1; tempDenom *= i, i++) {
		e += 1/(tempDenom*i);
	}
	return e;
}
