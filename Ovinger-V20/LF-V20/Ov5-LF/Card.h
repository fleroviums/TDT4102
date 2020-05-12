#pragma once
#include "std_lib_facilities.h"
enum class Rank{two=2,three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace};

enum class Suit{clubs,diamonds,hearts,spades};

/*To fordeler med å bruke symboler(enum class) framfor f.eks heltall og strenger i koden er:
    - kompilatoren vil ikke fange opp feil hvis man skriver feil, men man vil da få kode som ikke oppfører 
    seg som forventet, der det er veldig vanskelig å finne feilen
    - det øker lesbarheten av koden 
*/


const map<Rank, string> rankToStringMap{
	{Rank::two, "two"},
	{Rank::three, "three"},
	{ Rank::four, "four"},
	{ Rank::five, "five"},
	{ Rank::six, "six"},
	{ Rank::seven, "seven"},
	{ Rank::eight, "eight"},
	{ Rank::nine, "nine"},
	{Rank::ten, "ten"},
	{ Rank::jack, "jack"},
	{ Rank::queen, "queen"},
	{Rank::king, "King"},
	{Rank::ace, "ace"}};

const map<Suit, string>SuitToStringMap{ 
	{Suit::clubs, "clubs"}, 
	{ Suit::diamonds, "diamonds"},
	{ Suit::hearts, "hearts"},
	{ Suit::spades, "spades"}};

string rankToString(Rank r);
string suitToString(Suit s);

//Det er ikke krav i oppgaven aa bruke const, men vi har brukt dette i losningsforslag
// fordi det er god kode praksis. const-correctness som det heter laerer du mer om senere i faget.
class Card
{
public:
	Card(Suit suit, Rank rank) :s(suit), r(rank) {};
	Suit getSuit() const;
	Rank getRank() const;
	string toString() const;
	string toStringShort() const;
private:
	Suit s;
	Rank r;
};