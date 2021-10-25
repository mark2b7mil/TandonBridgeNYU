#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Money { 
private:
	long AllCents;

public:
	Money() : AllCents{0} {}; // Value is $0.00

	Money(long dollars) {  // Value is dollars * 100
		this->AllCents = dollars * 100; 
	}

	Money(long dollars, int cents) { // Value is dollars * 100 + cents.
		if(dollars * cents < 0) {
        	cout << "Illegal values for dollars and cents.\n";
        	exit(1); // I dislike this but it just makes it easier to exit out of the program.
    	}
		this->AllCents = dollars * 100 + static_cast<long>(cents);
	}

	Money operator+(const Money& rhs) { // Adding two together.
		Money temp;
		temp.AllCents = this->AllCents + rhs.AllCents;
		return temp;
	}

	Money operator-(const Money& rhs) { // Subtracting two from each other.
		Money temp;
		temp.AllCents = this->AllCents - rhs.AllCents;
		return temp;
	}

	Money operator-() { // Overload the negation.
		Money temp;
		temp.AllCents = -(this->AllCents);
		return temp;
	}

	Money operator+=(const Money& rhs) { 
		this->AllCents += rhs.AllCents;
		return *this;
	}

	bool operator==(const Money& rhs) { 
		return (this->AllCents == rhs.AllCents);
	}

	bool operator<(const Money& rhs) { 
		return (this->AllCents < rhs.AllCents);
	}

	friend istream& operator>>(istream& is, Money& target); 
	friend ostream& operator<<(ostream& os, const Money& target);
};

class Cheque {
private:
	int ID;
	bool Cashed;
	Money Amount;

public:
	Cheque() : ID {0}, Cashed {false} {};

	int GetID() const;
	bool GetCashed() const;
	Money GetAmount() const;

	void SetID(const int& id);
	void SetCashed(const bool& cashed);
	void SetAmount(const Money& amount); 

	bool operator<(const Cheque& rhs) {
		return (this->ID < rhs.ID);
	}

	friend istream& operator>>(istream& is, Cheque& target);
	friend ostream& operator<<(ostream& os, const Cheque& target);
};

int to_digit(char c);

int main(int argc, char const *argv[]) {
	int count = 0;

	Money curr_balance, old_balance; 
	
	vector<Cheque> cheques;

	Money total_deposits, total_cheques_cashed, new_balance, curr_deposit;
	Cheque curr_cheque;

	cout << "Welcome to the Bank!\nPlease enter your current bank balance ($##.##): ";
	cin >> curr_balance;
	cout << "Please enter your old bank balance ($##.##): ";
	cin >> old_balance;
	cout << "Please enter how many deposits you have (#): ";
	cin >> count;
	cout << "Please enter deposits, one per line ($##.##): " << endl;

	while(count) {
		cin >> curr_deposit;
		total_deposits += curr_deposit;
		count -= 1;
	}

	cout << "Please enter how many cheques you have for processing (#): ";
	cin >> count;
	cout << "Please enter cheques, one per line.\nFormat is (# $##.## #).\nWhere first number is id, second is amount, third is a Y/N if cashed or not." << endl;

	while(count) {
		cin >> curr_cheque;
		cheques.push_back(curr_cheque);
		if(curr_cheque.GetCashed()) {
			total_cheques_cashed += curr_cheque.GetAmount();
		}
		count -= 1;
	}

	new_balance = old_balance + total_deposits - total_cheques_cashed;

	cout << endl << "Total value of cheques cashed: " << total_cheques_cashed << endl;
	cout << "Total value of all deposits made: " << total_deposits << endl << endl;
	cout << "New balance should be: " << new_balance << endl;
	cout << "Difference from bank balance is: " << curr_balance - new_balance << endl << endl;

	std::sort(cheques.begin(), cheques.end());

	cout << "List of all cashed cheques:\n\nID\tAmount\tStatus" << endl;
	for(int i = 0; i < cheques.size(); i++) {
		if(cheques[i].GetCashed()) {
			cout << cheques[i] << endl;
		}
	}

	cout << endl << "List of all non-cashed cheques:\n\nID\tAmount\tStatus" << endl;
	for(int i = 0; i < cheques.size(); i++) {
		if(!cheques[i].GetCashed()) {
			cout << cheques[i] << endl;
		}
	}

	return 0;
}

istream& operator>>(istream& is, Money& target) {
	char first_char, decimal, digit_one, digit_two;
	long dollars;
	int cents; 
	bool negative = false;

	is >> first_char; // Check to see if we deal with negatives or not.
	if(first_char == '-') {
		negative = true;
		is >> first_char;
	}

	is >> dollars >> decimal >> digit_one >> digit_two;

	if(first_char != '$' || decimal != '.' || !isdigit(digit_one) || !isdigit(digit_two)) {
		cout << "Illegal form of currency input!" << endl;
		exit(1);
	}

	cents = to_digit(digit_one) * 10 + to_digit(digit_two);
	target.AllCents = dollars * 100 + cents;

	if(negative) {
		target.AllCents = -target.AllCents;
	}

	return is;
}

ostream& operator<<(ostream& os, const Money& target) {
	long absolute_cents, dollars, cents;
	absolute_cents = labs(target.AllCents);
	dollars = absolute_cents / 100;
	cents = absolute_cents % 100;

	if(target.AllCents < 0) {
		os << "-"; 
	}

	os << "$" << dollars << ".";

	if(cents < 10) {
		os << "0";
	}

	os << cents;
	return os;
}

int to_digit(char c) {
	return (static_cast<int>(c) - static_cast<int>('0'));
}

int Cheque::GetID() const {
	return this->ID;
}

bool Cheque::GetCashed() const {
	return this->Cashed;
}

Money Cheque::GetAmount() const {
	return this->Amount;
}

void Cheque::SetID(const int& id) {
	this->ID = id;
}

void Cheque::SetCashed(const bool& cashed) {
	this->Cashed = cashed;
}

void Cheque::SetAmount(const Money& amount) {
	this->Amount = amount;
} 

istream& operator>>(istream& is, Cheque& target) {
	char cashed_status;
	is >> target.ID >> target.Amount >> cashed_status;
	if(cashed_status == 'Y' || cashed_status == 'y') {
		target.SetCashed(true);
	} else if(cashed_status == 'N' || cashed_status == 'n') {
		target.SetCashed(false);
	} else {
		cout << "Invalid check!" << endl;
		exit(1);
	}
	return is;
}

ostream& operator<<(ostream& os, const Cheque& target) {
	os << target.ID << "\t" << target.Amount << "\t";
	if(target.Cashed) {
		os << "Cashed";
	} else {
		os << "Not Cashed";
	}
	return os;
}