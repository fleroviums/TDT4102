#include "masterVisual.h"

void addGuess(MastermindWindow& mwin,const string code,const int size, const char startLetter, const int round){
	int xPos = padX;
	const int yPos = 3*padY+2*padY*round;
	for(int i =0; i<size; i++){
		mwin.vr.push_back(new Rectangle{Point{xPos,yPos},padX,padY});
		mwin.vr[mwin.vr.size()-1].set_fill_color(Color{code[i]-startLetter+1});
		mwin.attach(mwin.vr[mwin.vr.size()-1]);
		xPos += 2*padX;
	}
}

void addFeedback(MastermindWindow &mwin,const int correctPosition, const int correctCharacter, const int size,
 const int round){
	int xPos = 9*padX+radCircle;
	const int yPos = 3.5*padY+2*padY*round;
	for(int i = 0; i < size; i++){
		mwin.vc.push_back(new Circle{Point{xPos,yPos},radCircle});
		
		if (i < correctPosition) {
			mwin.vc[mwin.vc.size() - 1].set_fill_color(Color::black);
		} else if (i < (correctPosition + max(0, correctCharacter - correctPosition))) {
			mwin.vc[mwin.vc.size() - 1].set_fill_color(Color::white);
		}
		
		mwin.attach(mwin.vc[mwin.vc.size() - 1]);
		xPos += 2*radCircle;
	}
}

void hideCode(MastermindWindow &mwin,const int size){
	mwin.vr.push_back(new Rectangle{Point{padX,3*padY},winW-size*padX,padY});
	mwin.vr[mwin.vr.size()-1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size()-1]);
}

MastermindWindow::MastermindWindow(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
    button_pressed{false},
	guessBtn{upperLeftCornerBtn,btnW,btnH,"Add",cb_guess},
    guess{upperLeftCornerInBox,inBoxW,inBoxH,"Guess"}
    {
        attach(guess);
        attach(guessBtn);
};

 string MastermindWindow::wait_for_guess(){
		while (!button_pressed)
			Fl::wait();
		button_pressed = false;
		Fl::redraw();
        string newGuess =guess.get_string();
        guess.clear_value();
        return newGuess;
}


string MastermindWindow::getInput(unsigned int n, char lower, char upper){
	bool validInput = false;
	string guess;
	while(!validInput){
		guess.clear();
		string input = wait_for_guess();
		if(input.size() == n){
			for(unsigned int i = 0; i < n; i++){
				char ch = input[i];
				if(isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch)){
					guess += toupper(ch);
				} 
				else 
				break;
			}
		}
		if(guess.size() == n) validInput=true;
		else cout<<"Invalid input guess again\n";
	}
	return guess;
}
