// Assignment 3 - Open Assignment

//Please add your code in this file. If you need to include more files, add them in the same folder as this file.

#include "Graph.h"
#include "Window.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
using namespace Graph_lib;



Vector_ref<Point> input_to_points(string coords){
    //first part is pretty much the same as do_command on mini_dak
	Vector_ref<Point> points;
    vector<int> values;
	string currPt ="";
	for(int i=0; i<coords.size(); ++i){
		while(coords[i]!=','){ //get value of point
            if(isalnum(coords[i])){currPt.push_back(coords[i]);} //ignoring whitespace
		}
    }
    try{
        values.push_back(stoi(currPt));
    }
    catch(...){
        error("Unable to cast input " + currPt +" to int");
    }
    currPt = ""; //Reset string for next command

    //loop above gives us list of ints, lets check if even
    if(values.size()%2!=0){throw "Invalid input, need even number of points to draw lines, receieved" +  to_string(values.size());}

    for(int i=0;i<values.size(); i+=2){ //we know last index will be odd (even size), so this cannot run out of range hopefully
		Point tmpPt = Point({values[i], values[i+1]});
        points.push_back(tmpPt);
    }
    return points;
}

void plot(Vector_ref<Point> points){
    int maxX = 0; int maxY = 0;
    for(auto p : points){
        if(p->x>maxX) maxX = p->x;
        if(p->y>maxY) maxY = p->y;
    }
    const Point tl{100,100};
	const string win_label{"2D Plotter"};
	Simple_window win{tl, maxX, maxY, win_label};


    for(int i=0;i<points.size()-1;++i){
        Line drawThis = Line(points[i], points[i+1]);
        drawThis.set_color(Color::red);
        drawThis.set_style(Line_style::solid);
        win.attach(drawThis);
    }
    win.wait_for_button();
}


void fileInput(){
    cout << "rakk ikke hehe\n";
}

void keyboardInput(){
    cout << "Enter coordinates to plot. Use delimeter comma (,) and press enter when done";
    string coords ="";
    cin >> coords;
    Vector_ref plotPoints = input_to_points(coords);
    plot(plotPoints);
}


int main(){
    int choice =-1;
    while(choice!=0){
        cout << "\n~Plotting~\n"
        << "1) Plot from file input\n"
        << "2) Plot from keyboard inputs\n"
        << "0) Exit\n";
        cin >> choice;
        switch(choice){
        case 0: break;
        case 1: fileInput();
                break;
        case 2: keyboardInput();
                break;
        default: cout << "Not a valid choice\n";
                break;
        }
	}
	keep_window_open();
}
