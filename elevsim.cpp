//
// elevsim.cpp
// Project 3 <Albin Abraham & Nelson Corral>
//
#include "Person.h"         // used to include the person class
#include "Elevator.h"       // used to include the Elevator class
#include <cstring>          // used for string operations
#include <string>           // used for string operations
#include <cstdlib>
#include <vector>           // includes vector operations
#include <queue>            // includes queue operations
#include <chrono>           // used for the poisson distribution
#include <random>           // used to obtain random numbers that are the destination floors for each person
#include <iostream>

using namespace std;

int main(){
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    
    queue<Person> ques;                 // this vector is used to initialize each individual queue with in vector q.
    queue<Person> empty;                // empty vector used to reset vector ques.
    vector<queue <Person>> q;           // this vector holds the queue of persons for the elevator simulator.
    vector<int> nums;                   // this vector of nums is used to store the amount of times there has been an
                                        // an individual from each floor. It is used to keep track of each index of storage
    vector<vector<int>> storage;        // this vector stores the number of people there have been from each floor.
                                        // It helps with naming the persons.
        
    // ints nbr and rnd are used in the Poisson generator.
    // int floors holds the number of floors desired by the user.
    // dest is used to generate destination floors for each Person
    // sor is used to store the floor that a person may originate from.
    // verbose is used to check if user would like to run the program in verbose mode.
    // temp is used to set verbose mode. there is somewhat of an error checking process.
    // name is used to store the generated name of each person.
    int nbr, rnd, floors, dest, sor;
    double lambda, stepsize, pace;
    bool verbose;
    char temp, letter, number;
    string name;
    
    // Ask user the following to determine the method as to how the program should operate.
    cout << "Give a positive integer for the time interval : ";
    cin >> nbr;
    cout << "Give lambda parameter for the Poisson generator : ";
    cin >> lambda;
    cout << "Give number of floors : ";
    cin >> floors;
    cout << "Verbose  ?  (y/n)  ";
    cin >> temp;
    
    // set verbose mode
    if (temp == 'y') {verbose = true;}
    else {verbose = false;}
    
    // setup storage vector for keeping track of persons from each floor.
    for(int i = 0; i <= floors; i++){
        storage.push_back(nums);
    }
    
    poisson_distribution<int> distribution(lambda);

    // the follwoing for loop is used to generate a
    for(int i=0; i<nbr; ++i){
        rnd = distribution(generator);
        // if verbose is true then output will be provided.
        if (verbose == true) {cout << "at step " << i << " : " << rnd << endl;}
        
        // sets the vector of ques to be equal to the vector empty... empty has no elements
        // this is essentially used to reset the ques vector.
        ques = empty;
        
        // if the random number that is generated by the distribution is greater than 0...
        if(rnd > 0){
            stepsize = 1.0/(rnd+1);         // calculate a stepsize
            for(int k=0; k<rnd; k++){
                sor = k%floors;             // there is a chance that k can be greater than the number of max floors
                                            // so sor will be used to calculate the source floor for instances of the Persons class
                name = "";                  // name is used to generate a name for each instance of the Person class
                letter = sor + 'A';         // the first letter of the name corresponds to each relatvie floor... A=0, B=1...
                number = storage.at(sor).size() + '0';      // number is the ascii value for the corresponding amount of
                                                            // people that have been moved from that floor, prior to this instance 
                storage.at(sor).push_back(1);               // this command increases the count of persons from each floor
                name += letter;                             // Used to concatenate a new name for this instance of Person
                name += number;                             // Used to concatenate a new name for this instance of Person
                
                // the following while true loop is used to find a floor that is different
                // from the source floor and set that to be the desired destination
                while(true){
                    dest = rand() % floors;
                    if (dest != sor) {break;}
                }
                Person temp = Person(name, i+stepsize*(k+1), sor, dest);    // make the instance of Person
                ques.push(temp);                                            // this adds the new person into the queue
                if(verbose == true){cout << "-> " << temp;}             // if verbose == true then the instance is printed.
                
            } // end of for k loop ..  a complete queue is made at this point.
            
            q.push_back(ques);      // this adds the queue into the vector of queues q.
        } // end of if rnd > 0
    } // end of for i loop
    
    cout << "Give the pace of the Elevator : ";
    cin >> pace;
    
    // create an instance of the class Elevator and then pass in the pace and the generated vector of queues
    Elevator A = Elevator(pace,q);
    
    // command used to runn the elevator simulator
    A.run(verbose);
    return 0;
}