#include "CardDeck.h"

CardDeck::CardDeck() {
	for (const auto r : rankToStringMap) {
		for (const auto s : SuitToStringMap) {
			Card c(s.first, r.first);
			cards.push_back(c);
		}
	}
}

void CardDeck::swap(int i, int j) {
	Card temp = cards[i];
	cards[i] = cards[j];
	cards[j] = temp;
}

void CardDeck::print() const{
	for (auto c : cards) {
		cout << c.toString() << '\n';
	}
}

void CardDeck::printShort() const{
	for (auto c : cards) {
		cout << c.toStringShort() << '\n';
	}
}

void CardDeck::shuffle() {
	for (unsigned int i = 0; i < cards.size(); i++) {
		swap(i, rand() % cards.size());
	}
}

Card CardDeck::drawCard() {
	if(cards.size()>0){
		Card c = cards.back();
		cards.pop_back();
		return c;
	}
	error("There are no more cards in the deck.\n");
}


//Denne funksjonen er ikke en del av oppgaveteksten. 
//Den er laget for å gjore implementasjoen av Blackjack enklere.
int CardDeck::cardsLeft() const{
	return cards.size();
}