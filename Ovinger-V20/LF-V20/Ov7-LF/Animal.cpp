#include "Animal.h"
#include "Graph.h"

using namespace Graph_lib;
void Animal::toString() const{
    cout << "Animal: " << name << ", " << age<<'\n';
}

void Dog::toString() const{
    cout << "Dog: " << name << ", " << age<<'\n';
}

void Cat::toString() const{
    cout << "Cat: " << name << ", " << age<<'\n';
}

void testAnimal(){
    Vector_ref<Animal> animals;
    
    Cat tiger{"Tiger", 5};
    animals.push_back(tiger);
    Dog fido{"Fido", 3};
    animals.push_back(fido);
    Cat max{"Max", 7};
    animals.push_back(max);
    Dog buster{"Buster", 15};
    animals.push_back(buster);
    Cat kitty{"Kitty", 12};
    animals.push_back(kitty);
    Dog coco{"Coco",4};
    animals.push_back(coco);

    for(int i = 0; i < animals.size(); ++i){
        animals[i].toString();
    }
}