#include "task3.h"

void BikeStation::setBikes(unsigned int num){bikes = num;}
unsigned int BikeStation::getBikes(){return bikes;}

string BikeStation::status(){
    return to_string(bikes) + " out of " + to_string(capacity);
}
string BikeStation::status_ss(){
    stringstream ss;
    ss << bikes << " out of " << capacity;
    return ss.str();
}
map<string, int> simulateOneDay(vector<BikeStation*> stations){
    map<string, int> fails;
    for(int i=0;i<ridesPerDay;++i){
        int stF = rand() % (stations.size());
        int stT = stF; while(stT==stF){stT = rand()%stations.size();}
        if(stations[stF]->getBikes() == 0){
            fails[stations[stF]->getName()] ++;
        }
        else if(stations[stT]->getCapacity() == stations[stT]->getBikes()){
            fails[stations[stF]->getName()] ++;
        }
    }
    return fails;
}

void printStats(map<string, int> failedTrips){
    cout << "Unsuccessful rides:\n";
    for(auto p : failedTrips){
        cout << p.second << " bike trips refused at " << p.first << endl;
    }
}