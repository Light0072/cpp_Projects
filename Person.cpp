//
// Person.cpp
//

#include "Person.h"     // the header file related to this class
#include <cstring>      // used to pass in a parameter of type string
#include <cstdlib>
#include <string>       // allows for further access of built-in string functions.
#include <iostream>

using namespace std;
     
// The follwing function is the constructor for the class of Person.
// The constructor enables us to make an instance of the class.
// It takes in a name of type string, an arrival time of type double, and two integers.
// One integer for the source floor and another integer for the destination floor.
Person::Person(string n, double a, int s, int d){
    this->name = n;
    this->arrival = a;
    this->source = s;
    this->destination = d;
}

// The following function allows for the printing of an instance of class Person.
// The << operator is overloaded and told to show the following statement for the purpose of printing a Person.
ostream& operator<<(ostream& o, const Person& p){
    o << p.name << " arrived at " << p.arrival << ", at " << p.source << " and goes to " << p.destination << endl;
    return o;
}

