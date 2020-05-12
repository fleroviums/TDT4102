#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"



Blackjack::Blackjack(){
    pile.shuffle();
    for (int i=0;i<4;++i){ // Has to be changed to add more players evt
        if(i%2==0){
            playerDeck.push_back(pile.drawCard());
        }
        else{
            dealerDeck.push_back(pile.drawCard());
        }
    }
    //playBlackjack();
}
void Blackjack::viewDealerCard(){
    string hisCard = dealerDeck.front().toString();
    cout << "Dealer dramatically turns his card and revals " << hisCard << '\n'; // Only first round
}
void Blackjack::addCard(vector<Card>& thisDeck){
    thisDeck.push_back(pile.drawCard());
    //dealerDeck.push_back(pile.drawCard());
}

int Blackjack::handValue(vector<Card> thisDeck){ // Checks total hand value for player or dealer
    int handVal = 0;
    for (auto card : thisDeck){
        for (const auto& p : bjValues){
            if(card.getRank()==p.first && card.getRank() != Rank::ace){ //Skips all aces first loop
                handVal += p.second;
            }
        }
    }
    for (auto moreCards : thisDeck){ // Seperate loop, going back and finding all aces. Can be optimized as fuck
            if (moreCards.getRank() == Rank::ace){
                if (handVal+11>21){
                    handVal+=1;
                }
                else{
                    handVal+=11;
                }
            }
        }
    return handVal;
}

void Blackjack::printHand(vector<Card> thisDeck){
    for(Card ca : thisDeck){
        cout << ca.toString() << " (" << ca.toStringShort() << ")";
        cout << '\n';
    }
}

int Blackjack::waitUserInput(){
    cout << "Your cards are:\n";
    printHand(playerDeck);
    cout << "\n With a total value of " << to_string(handValue(playerDeck)) <<'\n';
    int usrChoice;
    cout << "What will you do?\n"
    << "1) Hit\n"
    << "2) Stand\n";
    cin >> usrChoice;
    return usrChoice;
}
bool Blackjack::trueBlackjack(vector<Card> thisDeck){
    bool hasAce = false;
    bool hasTen = false;
    for (auto card : thisDeck){
        if (card.getRank() == Rank::ace){
            hasAce = true;
            //Deck contains ace
        }
        if (card.getRank() == Rank::jack || card.getRank() == Rank::queen || card.getRank() == Rank::king || card.getRank() == Rank::ten){
            hasTen = true;
        }
    }
    if (hasAce && hasTen){
        return true;
    }
    else{return false;}
}
bool Blackjack::checkWin(){
    if(handValue(playerDeck) == 21 && handValue(dealerDeck) != 21){
        cout << "\nSpiller har verdi 21 på hånda\n";
        printHand(playerDeck);
        return true;
        }
    else if(handValue(dealerDeck) > 21 && handValue(playerDeck) <=21){
        cout << "\nDealer har over 21 kort på hånda, han hadde\n";
        printHand(dealerDeck);
        return true;
    }
    else if(trueBlackjack(playerDeck) && trueBlackjack(dealerDeck) != 1){ // 1==true i C++ håper jeg
        cout << "\nSpiller fikk blackjack med kort\n";
        printHand(playerDeck);
        return true;
    }
    else{
        return false;
    }
}
bool Blackjack::checkLose(){
    if(handValue(dealerDeck) == 21 && handValue(playerDeck) != 21){
        cout << "\nDealer har verdi 21 på hånda\n";
        printHand(dealerDeck);
        return true;
        }
    else if(handValue(playerDeck) > 21 && handValue(dealerDeck) <=21){
        cout << "\nSpiller har over 21 kort på hånda\n";
        printHand(playerDeck);
        return true;
    }
    else if(trueBlackjack(dealerDeck) && trueBlackjack(playerDeck) != 1){ // 1==true i C++ håper jeg
        cout << "\nDealer fikk blackjack\n";
        printHand(dealerDeck);
        return true;
    }
    else{
        return false;
    }
}
bool Blackjack::gameFinished(){
    if(checkWin() || checkLose()){return true;}
    else{return false;}
}


void Blackjack::playBlackjack(){
    //Blackjack(); // Init card deck and whatnot
    viewDealerCard(); //Prints only the first card to dealer
    int choice = 0;
    while(gameFinished()==0 && choice!=2){
        choice = waitUserInput(); // :)
        if(choice == 1){
            addCard(playerDeck);
        }
        else if(choice ==2){
                if(handValue(dealerDeck) < 17){
                    addCard(dealerDeck); //Adds card to dealer if less than 17
                }
                cout << "\nThe dealer reveals his cards to be:\n";
                printHand(dealerDeck);
        }
    }
    if(checkWin()){
        cout << "\nGratulerer, du vant!\n";
    }
    else{
        cout << "\nDessverre vant dealer denne runden\n";
    }

}

