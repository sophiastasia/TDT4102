#include "Animal.h"

Animal::Animal(string name, int age): name{name}, age{age}{
}

Animal::~Animal(){
}

string Animal::toString(){
    string animal {"Animal: "};
    animal += Animal::name + ", ";
    animal += to_string(Animal::age);
    animal += " years";
    return animal;
}
string Animal::toString(){
    string cat {"Cat: "};
    cat += Animal::name + ", ";
    cat += to_string(Animal::age);
    cat += " years";
    return cat;
}
string Dog::toString(){
    string dog {"Dog: "};
    dog += Animal::name + ", ";
    dog += to_string(Animal::age);
    dog += " years";
    return dog;
}