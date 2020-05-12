#pragma once
#include "Card.h"
//Det er ikke krav i oppgaven aa bruke const, men vi har brukt dette i losningsforslag
// fordi det er god kode praksis. const-correctness som det heter laerer du mer om senere i faget.

class CardDeck
{
public:
	CardDeck();
	void print() const;
	void printShort() const;
	Card drawCard();
    void shuffle();
	int cardsLeft() const;
private:
	vector<Card> cards;
	void swap(int a, int b);
	
};