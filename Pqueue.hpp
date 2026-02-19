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


class Pqueue {

    private:

        vector<double> heapQueue;
        int size;

    public:

        Pqueue();

        //Function to insert an element into the Min heap priority quueu

        void insert(double value);

        //Function to remove and return the minimum element from the Min heap priority queue
        double getTop();

        int getSize();
    

        

};

#endif



 