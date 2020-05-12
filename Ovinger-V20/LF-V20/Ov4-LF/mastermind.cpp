#include "mastermind.h"
#include "masterVisual.h"
#include "utilities.h"
#include <cassert> // For assert()



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

void playMastermind()
{
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr char startLetter = 'A';
	constexpr int maxTries = 6;
	/*Vi bruker constexpr og ikke const her fordi vi vet verdien til variablene før vi kjører koden.
    constexpr er konstanter der verdien blir bestemt i kompileringstid, og const er konstanter der 
    verdien blir bestemt i kjøretid. Du kan lese mer om const og constexpr i kapittel 4.3.1 i læreboka
    */

	
	bool playAgain = false;
	do {
		MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
		string code = randomizeString(size, startLetter, startLetter + letters - 1);
		string guess;
		int round = 0;
		cout << "*** Mastermind ***\n";
		//cout<<code<<'\n';
	
		cout << "Colors: a = red, b = green, c = yellow, d = blue, e = lilac, f = cyan\n\n";
		// Viser CODE. addGuess brukes til å vise den hemmelige koden med parameter round = 0
		
		addGuess(mwin, code, size,startLetter, round);
		hideCode(mwin,size);
		
	
		while (guess != code && round != maxTries) {
			cout << "What's your guess? (" << size << " chars) \n";
			guess=mwin.getInput(size, startLetter, startLetter + letters - 1);
			cout<<"Your guess: "<<guess<<'\n';
			
			++round;

			int correct = checkCharactersAndPosition(code, guess);
			int correctChars = checkCharacters(code, guess);

			addGuess(mwin, guess,size, startLetter, round);
			addFeedback(mwin, correct, correctChars, size,round);
			if (correct == size) {
				break;
			}

			cout << "Correct characters: " << correctChars
				 << "\nCorrect positions: " << correct << "\nYou have " << maxTries - round
				 << " tries left.\n";
		}
		mwin.redraw();
		if (guess == code) {
			cout << "Congratulations, you cracked the code!\n";
		} else {
			cout << "You didn't manage to crack the code...\n";
		}
		playAgain = yn_question("Do you want to play again?");
	} while (playAgain);
	
}

int checkCharactersAndPosition(string code, string guess)
// precondition: code.length() >= guess.length()
// Her bruker vi kommentaren over for å eksplisitt uttrykke preconditionen
// og vi bruker assert() til å sjekke preconditioen.
//Generelt er det ikke anbefalt å ha kommentarer som sier akkurat det samme som koden, så denne 
//kommentaren er diskutabel

{
	assert(code.length() >= guess.length());
	int count = 0;
	for (unsigned int i = 0; i < code.length(); ++i) {
		if (code[i] == guess[i]) {
			++count;
		}
	}
	return count;
}

int checkCharacters(string code, string guess)
// precondition: code.length() >= guess.length()
{
	assert(code.length() >= guess.length());
	set<char> guessSet;
	for (char ch : guess) {
		guessSet.insert(ch);
	}

	int count = 0;
	for (char ch : guessSet) {
		int guessCount = countChar(guess, ch);
		int codeCount = countChar(code, ch);
		count += min(guessCount, codeCount);
	}

	return count;
}

//------------------------------------------------------------------------------
