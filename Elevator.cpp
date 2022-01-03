//
//  Elevator.cpp
//  Albin Abraham & Nelson Corral
//

#include "Elevator.h"
#include "Person.h"
#include <vector>
#include <queue>
#include <cmath>
//double Elevator::pace = 0.1;

Elevator::Elevator(double p, vector<queue <Person>> q){
    this-> arrivals = q;
    this-> pace = p;
}

void Elevator::run(bool verbose){
    double p = this->pace;          // used to shorthand/abbreviate pace
    double elaptime = 0;            // total elapsed time
    double movetoper = 0;           // time that the elevator moves to the next person
    double waittime = 0;            // wait time to get onto elevator
    double twtime = 0;              // total waiting time
    double travtime = 0;            // travel time to destination floor.
    int epos = 0;                   // used to keep track of elevators location.
    
    
    if (verbose == true){                                   // prints output if verbose is true
        cout << "Starting the simulation ..." << endl;
    }
    
    // setup for initial case...
    Person tempp = this->arrivals[0].front();
    elaptime = tempp.arrival;
    
    // this for loop actually allows for the simulation to run.
    for(int i = 0; i < this->arrivals.size(); i++){
        while(this->arrivals[i].empty() != true){       // while the queue is not empty
            Person tempp = this->arrivals[i].front();   // temp person to make operations quicker
            movetoper = abs(epos - tempp.source)*p;
            elaptime += movetoper;
            if (verbose == true){                               // output only if verbose == true
                cout << "->  " << this->arrivals[i].front();
                cout << "\televator moves from " << epos << " to " << tempp.source << " in time " << movetoper << ", elapsed time : " << elaptime << endl;
                
                epos = tempp.source;                            // update elevator position
                
                waittime = elaptime - tempp.arrival;            // calculate wait time.
                if (waittime < 0) {waittime = 0;}               // if the person arrived before the elevator arrived at
                                                                // that floor wait time is zero.
                
                cout << "\t" << tempp.name << " waited " << waittime << endl;
                this->waits.push_back(waittime);
                travtime = abs(epos - tempp.destination)*p;         // update values
                elaptime += travtime;                               // update time elapsed
                
                cout << "\televator moves from " << epos << " to " << tempp.destination << " in time " << travtime << ", elapsed time : " << elaptime << endl;

            } // end of if verbose == true
            
            epos = tempp.destination;   // update elevator position.
            this->arrivals[i].pop();    // remove the person from the queue within the vector
        } // end of while loop
        
    } // end of for loop
    
    // sum up the total time waited
    for(int i = 0; i < this -> waits.size(); i++){
        twtime += waits[i];
    }
    
    // Display the waiting time and the average.
    cout << "Total waiting time : " << twtime << endl;
    cout << "Average waiting time : " << twtime/this->waits.size() << endl;
}

