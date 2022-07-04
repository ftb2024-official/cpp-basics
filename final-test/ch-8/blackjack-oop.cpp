#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

class Card {
public:
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
private:
	CardRank m_rank;
	CardSuit m_suit;
public:
	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS): m_suit{suit}, m_rank{rank} {}

	void printCard() const {
		switch(m_rank) {
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

		switch(m_suit) {
			case SUIT_CLUB: cout << 'C'; break;
			case SUIT_DIAMOND: cout << 'D'; break;
			case SUIT_HEART: cout << 'H'; break;
			case SUIT_SPADE: cout << 'S'; break;
		}
	}

	int getCardValue() const {
		switch(m_rank) {
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
};

class Deck {
private:
	array<Card, 52> m_deck;
	int m_cardIndex = 0;

	static void swapCard(Card &a, Card &b) {
		Card temp = a;
		a = b;
		b = temp;
	}

	static int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
public:
	Deck() {
		int card = 0;
		for(int suit = 0; suit < Card::MAX_SUITS; ++suit)
		for(int rank = 0; rank < Card::MAX_RANKS; ++rank) {
			m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
			++card;
		}
	}

	void printDeck() const {
		for(const auto &card: m_deck) {
			card.printCard();
			cout << ' ';
		}

		cout << '\n';
	}

	void shuffleDeck() {
		for(int index = 0; index < 52; ++index) {
			int swapIndex = getRandomNumber(0, 51);
			// меняем местами с нашей текущей картой
			swapCard(m_deck[index], m_deck[swapIndex]);
		}

		m_cardIndex = 0;
	}

	const Card& dealCard() {
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}
};

char getPlayerChoice() {
	char choice;
	do {
		cout << "(h) to hit, or (s) to stand: ";
		cin >> choice;
	} while(choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(Deck &deck) {
	int playerTotal = 0;
	int dealerTotal = 0;

	dealerTotal += deck.dealCard().getCardValue();
	cout << "The dealer is showing: " << dealerTotal << '\n';

	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	while(1) {
		cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if(choice == 's') break;

		playerTotal += deck.dealCard().getCardValue();

		if(playerTotal > 21) return false;
	}

	while(dealerTotal < 17) {
		dealerTotal += deck.dealCard().getCardValue();
		cout << "The dealer now has: " << dealerTotal << '\n';
	}

	if(dealerTotal > 21) return true;

	return (playerTotal > dealerTotal);
}

int main(int argc, const char *argv[]) {
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Deck deck;

	deck.shuffleDeck();

	if(playBlackjack(deck))
		cout << "You win!\n";
	else
		cout << "You lose!\n";
	
	return 0;
}