#include "std_lib_facilities.h"
//#include "CardDeck.h"
#include "Card.h"
#include "Blackjack.h"

CardDeck::CardDeck(){
    for(auto s : suitMap){
        for(auto r : rankMap){
            cards.push_back(Card(s.first, r.first));
        }
    }
}

void CardDeck::swap(int i, int j){
    Card tmpCard = cards[i];
    cards[i] = cards[j];
    cards[j] = tmpCard;
}
void CardDeck::print(){
    for (auto card : cards){
        //string strtest = card.toString();
        cout <<  card.toString() << '\n';
    }
}
void CardDeck::printShort(){
    for (auto card : cards){
        cout << card.toStringShort() << '\n';
    }
}

void CardDeck::shuffle(){
    for (int i=0;i<52;++i){
        int rNum = rand()%52;
        swap(i,rNum);
    }
}
Card CardDeck::drawCard(){
    Card lastOne = cards.back();
    cards.pop_back(); //Removes last card from deck
    return lastOne;
}