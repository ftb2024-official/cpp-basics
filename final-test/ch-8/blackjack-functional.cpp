#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

enum CardSuit {
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
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
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

struct Card {
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card) {
	switch(card.rank) {
		case RANK_2: cout << '2'; break;
		case RANK_3: cout << '3'; break;
		case RANK_4: cout << '4'; break;
		case RANK_5: cout << '5'; break;
		case RANK_6: cout << '6'; break;
		case RANK_7: cout << '7'; break;
		case RANK_8: cout << '8'; break;
		case RANK_9: cout << '9'; break;
		case RANK_10: cout << '10'; break;
		case RANK_JACK: cout << 'J'; break;
		case RANK_QUEEN: cout << 'Q'; break;
		case RANK_KING: cout << 'K'; break;
		case RANK_ACE: cout << 'A'; break;
	}

	switch(card.suit) {
		case SUIT_CLUB: cout << 'C'; break;
		case SUIT_DIAMOND: cout << 'D'; break;
		case SUIT_HEART: cout << 'H'; break;
		case SUIT_SPADE: cout << 'S'; break;
	}
}

void printDeck(const array<Card, 52> &deck) {
	for(const auto &card: deck) {
		printCard(card);
		cout << ' ';
	}

	cout << '\n';
}

void swapCard(Card &a, Card &b) {
	Card temp = a;
	a = b;
	b = temp;
}

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(array<Card, 52> &deck) {
	for(int index = 0; index < 52; ++index) {
		int swapIndex = getRandomNumber(0, 51);
		// меняем местами с нашей текущей картой
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
		case RANK_JACK: return 10;
		case RANK_QUEEN: return 10;
		case RANK_KING: return 10;
		case RANK_ACE: return 11;
	}

	return 0;
}

char getPlayerChoice() {
	cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do {
		cin >> choice;
	} while(choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(const array<Card, 52> &deck) {
	const Card *cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// дилер получает одну карту
	dealerTotal += getCardValue(*cardPtr++);
	cout << "The dealer is showing: " << dealerTotal << '\n';

	// игрок получает две карты
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	while(1) {
		cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if(choice == 's') break;

		playerTotal += getCardValue(*cardPtr++);

		// смотрим не проиграл ли игрок
		if(playerTotal > 21) return false;
	}

	// если игрок не проиграл (у него не больше 21 очка), тогда дилер получает до тех пор, пока у него в сумме будет не меньше 17 очков
	while(dealerTotal < 17) {
		dealerTotal += getCardValue(*cardPtr++);
		cout << "The dealer now has: " << dealerTotal << '\n';
	}

	if(dealerTotal > 21) return true;

	return (playerTotal > dealerTotal);
}

int main(int argc, const char *argv[]) {
	srand(static_cast<unsigned int>(time(0)));
	rand();

	array<Card, 52> deck;

	int card = 0;
	for(int suit = 0; suit < MAX_SUITS; ++suit)
	for(int rank = 0; rank < MAX_RANKS; ++rank) {
		deck[card].suit = static_cast<CardSuit>(suit);
		deck[card].rank = static_cast<CardRank>(rank);
		++card;
	}

	shuffleDeck(deck);

	if(playBlackjack(deck))
		cout << "You win!\n";
	else
		cout << "You lose!\n";
	
	return 0;
}