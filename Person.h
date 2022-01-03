//
// Person.h
//

#ifndef Person_hpp
#define Person_hpp

#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Person{
    public:
        string name;            // used to store the name of the person
        double arrival;         // used to store the time that the person arrived.
        int source;             // used to store the floor on which the person is waiting
        int destination;        // used to store the desired destination
    
        Person(string n, double a, int s, int d);           // constructor used to create instances of the class Person.
        friend ostream& operator<< (ostream& o, const Person& p); // used to print out information related to a person.
};

#endif /* Person_hpp */
