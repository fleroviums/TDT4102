#include "std_lib_facilities.h"
#include "Card.h"
#include "Blackjack.h"
//#include "CardDeck.h"


string suitToString(Suit suit){
    for (const auto& p : suitMap){
        if(suit == p.first){
            return p.second;
        }
    }
    return "Error"; //Hopefully never happens
}

string rankToString(Rank rank){
    for (const auto& p : rankMap){
        if(rank == p.first){
            return p.second;
        }
    }
    return "Error";
}

Suit Card::getSuit(){
    return s;
}
Rank Card::getRank(){
    return r; //Disse to kunne jeg definert i .h like gjerne?
}

string Card::toString(){
    string returnStr = rankToString(r);
    returnStr += " of ";
    returnStr += suitToString(s);
    return returnStr; // Finnes det en mer snedig måte å gjøre dette?
}

string Card::toStringShort(){
    char suitChar = suitToString(s)[0];
    int rankVal = static_cast<int>(getRank()); //If rank "two"->2
    string rankString = to_string(rankVal);
    return suitChar + rankString;
}