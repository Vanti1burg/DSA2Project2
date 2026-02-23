#ifndef PQUEUE_HPP
#define PQUEUE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <random>
#include <sstream>

#include <fstream>
#include "Pqueue.hpp"
using namespace std;



//class header file for priority queue class 
//also stores the event struct that is used to create the events for simulation
struct Event {
    double time;
    double arrivalTime = -1; 
    double departureTime = -1;
    int type; 
    
};
class Pqueue {

    private:

        vector<Event> heapQueue;
        int size;
        int timePassed;

    public:

        Pqueue();

        //Function to insert an element into the min heap priority quueu

        void insert(Event newEvent);

        //Function to remove and return the first element from the Min heap priority queue

        Event getTop();
        Event peekTop();

        int getSize();
    

        

};

#endif



 