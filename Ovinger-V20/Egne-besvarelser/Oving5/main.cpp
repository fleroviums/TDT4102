#include "std_lib_facilities.h"
#include "Card.h"
//#include "CardDeck.h"
#include "Blackjack.h"

/*
THEORY
1E	Koden blir mer lesbar, i tillegg kan man enklere sammenlikne hvilken verdi av to kort som er høyest. 
3C	Funksjonen bør være i public sånn at den kan endre på vektoren?
*/

void enumTests(){
	cout << "suitToString: " << suitToString(Suit::diamonds) << '\n';
	cout << "rankToString: " << rankToString(Rank::four) << '\n';
}
void CardClassTest(){
	Card testCard = Card(Suit::diamonds, Rank::five);
	Suit testSuit = testCard.getSuit();
	Rank testRank = testCard.getRank();
	cout << "getSuit (med suitToString): " << suitToString(testSuit) << '\n';
	cout << "getRank (med rankToString): " << rankToString(testRank) << '\n';

	string testString = testCard.toString();
	string testStringShort = testCard.toStringShort();
	cout << "testString: " << testString << '\n' << "Kort versjon: " << testStringShort << '\n';
}
void cardDeckTest(){
	CardDeck myDeck = CardDeck();
	myDeck.print();
	myDeck.swap(0,1);
	cout << "NÅ PRINTER VI ETTER Å HA BYTTA DE TO FØRSTE KORTENE\n";
	myDeck.printShort();
	myDeck.shuffle();
	cout << "\nPrint etter shuffle:\n";
	myDeck.printShort();
	cout << "\n Det siste kortet var\n";
	Card sisteKort = myDeck.drawCard();
	cout << sisteKort.toString();
	cout << "\n og se! Den er fjerna fra bunka:\n";
	myDeck.printShort();
}
void blackjacktest(){
	Blackjack bjObj = Blackjack();
	bjObj.playBlackjack();
	keep_window_open();
}

int main()
{
	// Begin setup
	setlocale(LC_ALL, "no_NB.UTF-8");
	srand(static_cast<unsigned int>(time(nullptr)));
	int i=-1;
	// End setup

	while (i!=0){
		cout << "\nØving 5 - Hovedmeny \n"
		<< "0) Avslutt\n"
		<< "1) Enumerasjoner\n"
		<< "2) Kortklasse\n"
		<< "3) Kortstokk-klasse\n"
		<< "4) Blackjack\n";
		cin >> i;

		switch(i){
		case 0: break;
		case 1: enumTests();
				break;
		case 2: CardClassTest();
				break;
		case 3: cardDeckTest();
				break;
		case 4: blackjacktest();
				break;
		default: cout << "Ugyldig valg\n";
				break;
		}
	}

	keep_window_open();
}

