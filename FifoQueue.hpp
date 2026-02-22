#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP


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


 



class FifoQueue {
    private:
        vector <Event> fifoQueue;
    public:
        void insert(Event newEvent);
        FifoQueue();
        Event takeTop();
        Event peekTop();
        int getSize();
};



#endif
