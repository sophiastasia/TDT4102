#pragma once
#include "std_lib_facilities.h"

class Animal{
    protected:
        string name;
        int age;
    public:
        Animal(string name, int age);
        virtual ~Animal(); 
        virtual string toString();
};

class Cat : public Animal {
    public:
        using Animal::Animal;
        string toString();
};

class Dog : public Animal {
    public:
        using Animal::Animal;
        string toString();
};