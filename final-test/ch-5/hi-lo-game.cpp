#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << endl;

	int guessNumber = 1;
	int secret = getRandomNumber(1, 100);

	while(guessNumber < 8) {
		cout << "Guess #" << guessNumber << ": ";
		int userGuess;
		cin >> userGuess;

		if(userGuess > secret) {
			cout << "Your guess is HIGH" << endl;
		} else if(userGuess < secret) {
			cout << "Your guess is LOW" << endl;
		} else {
			cout << "Correct! You win!" << endl;
		}

		++guessNumber;
	}
	
	return 0;
}
