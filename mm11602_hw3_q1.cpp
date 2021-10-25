#include <iostream>

//Write	a	program	that	computes	how	much	a	customer	has	to	pay	after	purchasing	two
//items.The	price	is	calculated	according	to	the	following	rules :
//• Buy	one	get	one	half	off	promotion : the	lower	price	item	is	half	price.
//• If	the	customer	is	club	card	member, additional	10 % off.
//• Tax	is	added.
//Inputs	to	the	program	include :
//• Two	items’	prices
//• Have	club	card or not (User	enters	‘Y’ or ‘y’	for	“yes”;	‘N’ or ‘n’	for	“no”)
//• Tax	rate(User	enters	the	percentage	as	a	number;	for	example	they	enter	8.25	if	the	tax
//	rate	is	8.25 %)
//	Program	displays :
//• Base	price - the	price	before	the	discounts and taxes
//• Price	after	discounts - the	price	after	the	buy	one	get	one	half	off	promotion and the
//member’s	discount, if	applicable
//• Total	price	– the	amount	of	money	the	customer	has	to	pay(after	tax).
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	example :
//Enter	price	of	first	item : 10
//Enter	price	of	second	item : 20
//Does	customer	have	a	club	card ? (Y / N) : y
//Enter	tax	rate, e.g.	5.5	for	5.5 % tax : 8.25
//Base	price : 30.0
//Price	after	discounts : 22.5
//Total	price : 24.35625

int main()
{

	double item1{}, item2{}, tax_rate{}, base_price{}, price_after_discounts{}, total_price{};
	char club_card_member{};

	std::cout << "Enter price of first item: ";
	std::cin >> item1;
	std::cout << "Enter price of second item: ";
	std::cin >> item2;
	std::cout << "Does customer have a club card? (Y/N): ";
	std::cin >> club_card_member;
	std::cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	std::cin >> tax_rate;

	//Changing structure of tax rate to easily multiply in the future
	tax_rate /= 100;

	//Estabishing base price of the two items
	base_price = item1 + item2;

	//Finding out which item is lower in price and halving the lower priced item. Could use just else statement instead of else if but seems more readable this way.
	if (item1 <= item2) {
		item1 /= 2;
	}
	else if (item2 <= item1) {
		item2 /= 2;
	}

	//Establishing price of items with the lower priced item halved
	price_after_discounts = item1 + item2;

	//Finding out whether person is a club card member and taking ten percent off if yes
	if (club_card_member == 'y' || club_card_member == 'Y') {
		price_after_discounts *= .9;
	}

	//Calculating total price after all discounts
	total_price = (price_after_discounts * tax_rate) + price_after_discounts;

	std::cout << "Base price: " << base_price << std::endl;
	std::cout << "Price after discounts: " << price_after_discounts << std::endl;

	//Only placing this here because the example output has 5 numbers after the decimal, by default mine outputs 4 after the decimal
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(5);
	std::cout << "Total price: " << total_price << std::endl;

}