#include "Blackjack.h"

bool yn_question(string q)
//Returnere true når inputen fra brukeren er 'y', ellers false
{
	char yn;
	cout << q << " (y/n) ";
	cin >> yn;
	cin.ignore(256, '\n'); // Flere gyldige input blir ignorert
	if (yn == 'y')
		return true;
	return false;
	// return yn == 'y';
}

void Blackjack::roundInit(){
    if(deck.cardsLeft()<16){
        deck = CardDeck{};
        deck.shuffle();
    }
    playerHandSum = 0;
    dealerHandSum = 0;
    dealerHand.clear();
    playerHand.clear();
    playerDraw();
    playerDraw();
    dealerDraw();
    dealerDraw();

}
bool Blackjack::isAce(Card c) const{
    return c.getRank() == Rank::ace;
}


int Blackjack::getPlayerCardValue(Card c) const{
    if (isAce(c)){
        cout << "You got an ace, should we value it as 1 or 11?\n";
        int input;
        cin >> input;
        while (!(input == 1 || input == 11)){
            cout << "That is not a valid response, please enter 1 or 11.\n"  ;
            cin >> input;
        }
        return input;
    }
    return blackjackValues.at(c.getRank());
}

int Blackjack::getDealerCardValue(Card c) const{
    if (isAce(c)){
        if (dealerHandSum+11 <= 21){
            return 11;
        }
        return 1;
    }
    return blackjackValues.at(c.getRank());
}


void Blackjack::playerDraw(){
    playerHand.push_back(deck.drawCard());
    cout << "You got: " << playerHand[playerHand.size()-1].toString()<<'\n';
    playerHandSum += getPlayerCardValue(playerHand[playerHand.size()-1]);
}

void Blackjack::dealerDraw(){
    dealerHand.push_back(deck.drawCard());
    dealerHandSum += getDealerCardValue(dealerHand[dealerHand.size()-1]);
}

void Blackjack::playGame(){
    cout << "******* LET'S PLAY BLACKJACK! *********\n";
    deck.shuffle();
    bool win = true;
    do{
    roundInit();

    cout << "Player hand is currently: " << playerHandSum <<'\n';
    cout << "The dealer's open card is: " << dealerHand.at(0).toString()<<'\n';

    while (playerHandSum < 21 && yn_question("Do you want another card?")) {
        cout << "Player draws a card\n";
        playerDraw();
        cout << "Player hand is currently: " << playerHandSum <<'\n';
    }

    while (dealerHandSum < 17) {
        cout << "Dealer draws a card.\n";
        dealerDraw();
    }   

    cout << "**************************************\n";
    cout << "Player's cards: ";
    for(auto& c : playerHand){
        cout <<c.toString()<< ", "; 
    }
    cout <<'\n';
    cout << "Player's hand: " << playerHandSum << '\n';
    
    cout << "Dealer's cards: ";
        for(auto& c : dealerHand){
            cout <<c.toString()<< ", "; 
        }
    cout <<'\n';
    cout << "Dealer's hand: " << dealerHandSum <<'\n';
    
    if (playerHandSum > 21) {
        cout << "Player burst.\n";
        win = false;
    } else if (dealerHandSum > 21) {
        cout << "Dealer burst.\n";
        win = true;
    } else if (dealerHandSum == 21 && dealerHand.size() == 2) {
        cout << "Dealer got blackjack!\n";
        win = false;
    }else if (playerHandSum == 21 && playerHand.size() == 2) {
        cout << "Player got blackjack!\n";
        win = true;
    }  else if (dealerHandSum <= 21 && dealerHandSum > playerHandSum) {
        cout << "Dealer beat the player.\n";
        win = false;
    } else if (playerHandSum <= 21 && playerHandSum > dealerHandSum) {
        cout << "Player beat the dealer.\n";
        win = true;
    } else {
        cout << "Game was a draw.\n";
        win = false;
    }

    if (win) {
        cout << "You won! Congratulations!\n";
    } else {
        cout << "You lost!\n";
    }
    }while(yn_question("Do you want to play again?\n"));

}
