//
//  Elevator.h
//

#ifndef Elevator_hpp
#define Elevator_hpp

#include "Person.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Elevator {
    private:
        int state;      // stores the current level of the Elevator
        double pace;    // stores the set pace of the Elevator. This value is the length of
                        // time the elevator takes to move up or down by one floor.
        double elapsed; // The Elevator has to keep track of the time that has elapsed...
        
    public:
        vector<queue <Person>> arrivals;    // stores a queue of class persons to represent the waitline on each floor.
    
        vector<double> waits;               // used to store a list of the wait times for each person
                                            // that has used the elevator
     
        Elevator(double p, vector<queue <Person>> q);       // Constructor for the class of Elevator
    
        void run(bool verbose);             // this method of within the class of Elevator is the program used to
                                            // build a simulation with the stored Persons in the arrivals vector.
    
};

#endif /* Elevator_hpp */
