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

using namespace std;





struct Node {
    int arrivalTime;
    int burstTime;
    string name;
};



class FifoQueue {
    private:
        vector <double> fifoQueue;
    public:
      
        void insert(double value);

        FifoQueue();

        double takeTop();
        int getSize();
};



#endif
