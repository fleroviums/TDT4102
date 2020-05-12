#pragma once
#include "CardDeck.h"

const map<Rank,int> blackjackValues{
	{Rank::two, 2},
	{Rank::three, 3},
	{ Rank::four, 4},
	{ Rank::five, 5},
	{ Rank::six, 6},
	{ Rank::seven, 7},
	{ Rank::eight, 8},
	{ Rank::nine, 9},
	{Rank::ten, 10},
	{ Rank::jack, 10},
	{ Rank::queen, 10},
	{Rank::king, 10},
	{Rank::ace,11}};

//Det er ikke krav i oppgaven aa bruke const, men vi har brukt dette i losningsforslag
// fordi det er god kode praksis. const-correctness som det heter laerer du mer om senere i faget.

class Blackjack{
private:
    CardDeck deck;
    int playerHandSum;
    int dealerHandSum;

    void roundInit();
    bool isAce(Card c) const;
    int getPlayerCardValue(Card c) const;
    int getDealerCardValue(Card c) const;
    void playerDraw();
    void dealerDraw();
    
    vector<Card> dealerHand;
    vector <Card> playerHand;
public:
    void playGame();
};

