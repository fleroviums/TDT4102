#pragma once
#include "std_lib_facilities.h"

struct Food {
    string name;
    double price;
    string where;
    bool operator<(const Food& other){return price < other.price;}
};

void addPrice(map<string, set<Food>>& db, Food fp){
    db[fp.name].insert(fp);//funker det hvis varen ikke alt eksisterer? idk
}

void printAllPrices(const map<string, set<Food>>& db){
    for(auto item : db){
        cout << item.first << ":\n";
        for(Food f : item.second){
            cout << f.price << " " << f.where << endl;
        }
    }
}

void bestPrice(const map<string, set<Food>>& db, string name){
    if(db.find(name) == db.end()) cout << "No price for " << name << endl;
    else{
        set<Food> fs = db.at(name);
        auto best = *fs.begin();
        for(auto f : fs){
            if(f.price < best.price) best=f;
        }
        cout << "Best price for " << name << " is " << best.price << " at " << best.where;
    }
}
