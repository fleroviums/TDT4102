#include "Vehicle.h"

void Vehicle::draw(){
    // Update steering from user input ______
    std::pair<double,double> sVals = steer();
    status.update(sVals.first, sVals.second);
    // ______________________________________

    // Block of conditionals check for border________________________________________
    if(status.x >screenWidth-vehicleRadius){status.x = screenWidth-vehicleRadius;}//_
    else if(status.x < vehicleRadius){status.x=vehicleRadius;}//_____________________
    if(status.y > screenHeight-vehicleRadius){status.y = screenHeight-vehicleRadius;}
    else if(status.y < vehicleRadius){status.y = vehicleRadius;}//___________________
    // ______________________________________________________________________________

    // Draw current goal tile __________________________________________________________________________________
    fl_color(208); //Pink/Purple _______________________________________________________________________________
    fl_line_style(FL_SOLID); //_________________________________________________________________________________
    std::pair<double, double> currentGoal = track.getGoals()[goalIndex]; //_____________________________________
    fl_pie(currentGoal.first-goalRadius, currentGoal.second-goalRadius, goalRadius*2-1, goalRadius*2-1, 0, 360);
    //__________________________________________________________________________________________________________
    
    //Check goal collision _____________________________________________________________________________________
    if(circleCollision(status.x-currentGoal.first, status.y-currentGoal.second, vehicleRadius+goalRadius)){
        if(goalIndex == track.getGoals().size()-1){ goalIndex = 0;} //If last goal => Loop
        else{goalIndex++;}
    } // _______________________________________________________________________________________________________
    
    // Draw vehicle
    drawBody();
}

std::pair<double,double> PlayerVehicle::steer() const{
    std::pair<double,double> out{0,0};
    if(Fl::event_key('W')){out.first ++;} //Drive forward
    if(Fl::event_key('S')){out.first --;} //Drive backwards
    if(Fl::event_key('A')){out.second --;} //Turn left
    if(Fl::event_key('D')){out.second ++;} //Turn right
    return out;
}


void PlayerVehicle::drawBody() const{
    fl_color(FL_RED);
    fl_line_style(FL_SOLID);
    fl_circle(status.x, status.y, vehicleRadius); //main circle
    fl_circle(status.x+vehicleRadius*cos(status.angle), status.y+vehicleRadius*sin(status.angle), noseRadius);


}

bool circleCollision(double delX, double delY, double sumR){
    return sumR*sumR > delX*delX+delY*delY; //true if collision
}

void Vehicle::obsCollision(){
    // Might as well check collision for all obstacles on track.
    // Tried first calculating closest obstacle, but runtime would die from that
    int closestObs = 0;
    for(auto it = track.getObstacles().begin(); it!=track.getObstacles().end(); ++it){
        if circleCollision(status.x-std::get<0>(*it), status.y-std::get<1>(*it),vehicleRadius+) //it - vec.begin();
    }

}