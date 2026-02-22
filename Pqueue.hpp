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

        //Function to insert an element into the Min heap priority quueu

        void insert(Event newEvent);

        //Function to remove and return the minimum element from the Min heap priority queue
        Event getTop();
        Event peekTop();

        int getSize();
    

        

};

#endif



 