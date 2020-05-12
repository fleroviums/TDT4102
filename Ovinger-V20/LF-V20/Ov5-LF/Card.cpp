#include "Card.h"

string rankToString(Rank r){
	return rankToStringMap.at(r);
}
string suitToString(Suit s){
	return SuitToStringMap.at(s);
}


Suit Card::getSuit() const{
	return s;
}
Rank Card::getRank() const{
	return r;
}

string Card::toString() const{
	return  rankToString(r)+ " of " +suitToString(s);
}

string Card::toStringShort() const{
	return suitToString(s).at(0) + to_string(static_cast<int>(r));
}