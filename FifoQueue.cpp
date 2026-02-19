#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>
#include "FifoQueue.hpp"
using namespace std;

FifoQueue::FifoQueue() {

   
}

void FifoQueue::insert(double value) {
    fifoQueue.push_back(value);
}

double FifoQueue::takeTop() {
    if (fifoQueue.empty()) {
        cout<<"FIFO Queue is empty" <<endl;
        return -1;
    }
    double top = fifoQueue.front();
    fifoQueue.erase(fifoQueue.begin());
    return top;

}

int FifoQueue::getSize() {
    return fifoQueue.size();
}