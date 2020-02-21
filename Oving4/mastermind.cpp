#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"

constexpr int _SIZE = 4;
constexpr int letters = 6; // constexpr er bedre enn cosnt
constexpr int maxAttempts = 20; // syntes det var vanskelig så gir meg mange forsøk

int checkCharactersAndPosition(string code, string guess){
    int correct = 0;
    for (unsigned long long i=0;i<_SIZE;++i){
        if (guess[i]==code[i]){
            correct+=1;
        }
    }
    return correct;
}
int checkCharacters(string code, string guess){
    int correct = 0;
    for (unsigned int i=0;i<_SIZE;++i){
        for (unsigned int j=0;j<_SIZE;++j){
            if (code[j] == guess[i]){
                correct += 1;
                break;
            }
        }
    }
    return correct; 
}


void playMastermind(){
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    cout << "M A S T E R M I N D\n";
    string code = randomizeString(_SIZE, 'A', 'A' + (letters-1));
    string guess {""};
    int attempt = 0;
    int visWrap = 0;
    do{
        guess = mwin.getInput(_SIZE, 'A', 'A'+(letters-1));
        //guess = readInputToString(_SIZE, 'A', 'A'+(letters-1));
        addGuess(mwin, guess, _SIZE, guess[0], attempt, visWrap);
        addFeedback(mwin, checkCharactersAndPosition(code, guess), checkCharacters(code, guess), _SIZE, attempt, visWrap);

        cout << "\nRiktig på riktig plass: " << checkCharactersAndPosition(code, guess);
        cout << "\nRiktige bokstaver.....: " << checkCharacters(code, guess) << '\n';
        attempt += 1; // Denne kjøres selv om man gjetter 100% riktig første gang, derfor initieres attempt=0
        cout << "Du har " << maxAttempts-attempt << " forsøk igjen\n";
        cout << code;
    }
    while(guess != code && attempt <= maxAttempts);
    if(attempt<=maxAttempts){
            cout << "\nGratulerer, du gjettet riktig kode!\n";
    }
    else{
        cout <<"\nAii, der gikk du dessverre tom for forsøk.. Men du er like verdifull uansett!\n";
        mwin.redraw();
    }
}