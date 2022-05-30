#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

enum CardSuit {
	TREFY,
	BUBNY,
	CHERVY,
	PIKI,
	MAX_SUITS
};

enum CardRank {
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KOROL,
	RANK_TUZ,
	MAX_RANKS
};

struct Card {
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card) {
	switch(card.rank) {
		case RANK_2: cout << "2 "; break;
		case RANK_3: cout << "3 "; break;
		case RANK_4: cout << "4 "; break;
		case RANK_5: cout << "5 "; break;
		case RANK_6: cout << "6 "; break;
		case RANK_7: cout << "7 "; break;
		case RANK_8: cout << "8 "; break;
		case RANK_9: cout << "9 "; break;
		case RANK_10: cout << "10 "; break;
		case RANK_VALET: cout << "V "; break;
		case RANK_DAMA: cout << "D "; break;
		case RANK_KOROL: cout << "K "; break;
		case RANK_TUZ: cout << "T "; break;
	}

	switch(card.suit) {
		case PIKI: cout << "PIKI"; break;
		case BUBNY: cout << "BUBNY"; break;
		case TREFY: cout << "TREFY"; break;
		case CHERVY: cout << "CHERVY"; break;
	}
}

void printDeck(const array<Card, 52> &deck) {
	int index = 1;

	for(const auto &card: deck) {
		cout << index << ": ";
		printCard(card);
		cout << "\n";
		++index;
	}
}

void swapCard(Card &card1, Card &card2) {
	Card temp_card;

	temp_card = card1;
	card1 = card2;
	card2 = temp_card;
}

int getRandomCard(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(array<Card, 52> &deck) {
	for(int index = 0; index < 52; ++index) {
		int swapIndex = getRandomCard(0, 51);
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(const Card &card) {
	switch(card.rank) {
		case RANK_2: return 2;
		case RANK_3: return 3;
		case RANK_4: return 4;
		case RANK_5: return 5;
		case RANK_6: return 6;
		case RANK_7: return 7;
		case RANK_8: return 8;
		case RANK_9: return 9;
		case RANK_10: return 10;
		case RANK_VALET: return 10;
		case RANK_DAMA: return 10;
		case RANK_KOROL: return 10;
		case RANK_TUZ: return 11;
	}

	return 0;
}

char getPlayerChoice() {
	cout << "(h) to hit, (s) to stand: ";
	char choice;
	do {
		cin >> choice;
	} while(choice != 'h' && choice != 's');

	return choice;
}

bool playBlackJack(const array<Card, 52> &deck) {
	// настраиваем стартовый режим игры
	const Card *cardPtr = &deck[0];

	int playerScore = 0;
	int dealerScore = 0;

	// дилер получает одну карту
	dealerScore += getCardValue(*cardPtr++);
	cout << "The dealer is showing: " << dealerScore << endl;

	// игрок получает две карты
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);

	while(true) {
		cout << "You have: " << playerScore << endl;

		// смотрим не больше ли 21 очка у игрока
		if(playerScore > 21)
			return false;

		char choice = getPlayerChoice();

		if(choice == 's')
			break;

		playerScore += getCardValue(*cardPtr++);
	}

	// если игрок не проиграл и у него не больше 21 очка, то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17 очков
	while(dealerScore < 17) {
		dealerScore += getCardValue(*cardPtr++);
		cout << "The dealer now has " << dealerScore << endl;
	}

	// если у дилера больше 21 очка, то игрок победил
	if(dealerScore > 21)
		return true;

	return (playerScore > dealerScore);
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	array<Card, 52> deck;

	int card = 0;

	for(int suit = 0; suit < MAX_SUITS; ++suit) {
		for(int rank = 0; rank < MAX_RANKS; ++rank) {
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			++card;
		}
	}

	shuffleDeck(deck);

	if(playBlackJack(deck))
		cout << "You win!\n";
	else
		cout << "You lost!\n";

	// printDeck(deck);
	// cout << "\n";
	// 
	// printDeck(deck);

	return 0;
}