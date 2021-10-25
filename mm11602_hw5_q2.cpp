#include <iostream>
#include <cstdlib>
#include <ctime>

//Implement	a	number	guessing	game.The	program	should	randomly	choose	an	integer
//between	1 and 100	(inclusive), and have	the	user	try	to	guess	that	number.
//Implementations	guidelines :
//1. The	user	can	guess	at	most	5	times.
//2. Before	each	guess	the	program	announces :
//• An	updated	guessing - range, taking	in	to	account	previous	guessesand responses.
//• The	number	of	guesses	that	the	user	has	left.
//3. If	the	user	guessed	correctly, the	program	should	announce	that, and also	tell	how	many
//guesses	the	user	used.
//4. If	the	user	guessed	wrong, and there	are	still	guesses	left, the	program	should	tell	the
//user	if	the	number(it chose)	is	bigger or smaller	than	the	number	that	the	user	guessed.
//5. If	the	user	didn’t	guess	the	number	in	all	of	the	5	tries, the	program	should	reveal	the
//number	it	chose.
//6. Follow	the	execution	examples	below	for	the	exact	format.
//Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	two
//examples :
//Execution	example	1 :
//	I	thought	of	a	number	between	1 and 100!Try	to	guess	it.
//	Range : [1, 100] , Number	of	guesses	left : 5
//	Your	guess : 15
//	Wrong!My	number	is	bigger.
//	Range : [16, 100] , Number	of	guesses	left : 4
//	Your	guess : 34
//	Wrong!My	number	is	smaller.
//	Range : [16, 33] , Number	of	guesses	left : 3
//	Your	guess : 23
//	Congrats!You	guessed	my	number	in	3	guesses.
//	Execution	example	2 :
//	I	thought	of	a	number	between	1 and 100!Try	to	guess	it.
//	Range : [1, 100] , Number	of	guesses	left : 5
//	Your	guess : 15
//	Wrong!My	number	is	bigger.
//	Range : [16, 100] , Number	of	guesses	left : 4
//	Your	guess : 50
//	Wrong!My	number	is	smaller.
//	Range : [16, 49] , Number	of	guesses	left : 3
//	Your	guess : 3
//	Wrong!My	number	is	bigger.
//	Range : [16, 49] , Number	of	guesses	left : 2
//	Your	guess : 34
//	Wrong!My	number	is	smaller.
//	Range : [16, 33] , Number	of	guesses	left : 1
//	Your	guess : 20
//	Out	of	guesses!My	number	is	25

int main()
{
	int randomNum, numberOfGuesses{ 5 }, guessIncrement{ 1 }, guess{}, smallerRange{ 1 }, largerRange{ 100 };
	srand(time(0));
	randomNum = (rand() % 100) + 1;

	std::cout << "I thought of a number between 1 and 100! Try to guess it." << std::endl;

	//with every loop we are taking guesses until we guess the number or run out of guesses
	//using a do while loop here because we want to run the contents of the loop at least once, normal while loop could have worked as well
	do {
		std::cout << "Range: [" << smallerRange << ", " << largerRange << "], Number of guesses left: " << numberOfGuesses << std::endl;
		std::cout << "Your guess: ";
		std::cin >> guess;

		//comparing our guess against the random number and adjusting the smaller or larger range accordingly
		if (guess < randomNum && numberOfGuesses > 1) {
			std::cout << "Wrong! My number is bigger." << std::endl;
			smallerRange = guess + 1;
		}
		else if (guess > randomNum && numberOfGuesses > 1) {
			std::cout << "Wrong! My number is smaller." << std::endl;
			largerRange = guess - 1;
		}
		//if the number is guessed we break out of the loop
		else if (guess == randomNum) {
			std::cout << "Congrats! You guessed my number in " << guessIncrement << " guesses." << std::endl;
			break;
		}

		//we take away a guess with every loop and increment the guess counter
		numberOfGuesses -= 1;
		guessIncrement += 1;

		if (numberOfGuesses == 0) {
			std::cout << "Out of guesses! My number is " << randomNum << std::endl;
		}

		std::cout << std::endl;

	} while (numberOfGuesses > 0);

}