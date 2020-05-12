#pragma once
#include "std_lib_facilities.h"
//#include "CardDeck.h"
#include "Card.h"

class CardDeck{
    private:
        vector<Card> cards;
    public:
        CardDeck();
        void print();
        void swap(int i, int j);
        void printShort();
        void shuffle();
        Card drawCard();
};


class Blackjack{
    private:
        vector<Card> playerDeck;
        vector<Card> dealerDeck;

    public:
        CardDeck pile = CardDeck();
        Blackjack();
        void viewDealerCard();
        void printHand(vector<Card> thisDeck);
        void addCard(vector<Card>& thisDeck);
        int handValue(vector<Card> thisDeck);
        int waitUserInput();
        bool checkWin();
        bool checkLose();
        bool trueBlackjack(vector<Card> thisDeck);
        bool gameFinished();
        void playBlackjack();
};

const map<Rank, int> bjValues{
    {Rank::two, 2},
    {Rank::three, 3},
    {Rank::four, 4},
    {Rank::five, 5},
    {Rank::six, 6},
    {Rank::seven, 7},
    {Rank::eight, 8},
    {Rank::nine, 9},
    {Rank::ten, 10},
    {Rank::jack, 10},
    {Rank::queen, 10},
    {Rank::king, 10},
    {Rank::ace, 1}
};
