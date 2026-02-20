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

void FifoQueue::insert(Event  newEvent) {
    fifoQueue.push_back(newEvent);
}

Event FifoQueue::takeTop() {
    if (fifoQueue.empty()) {
        cout<<"FIFO Queue is empty" <<endl;
        return Event{-1, -1};
    }
    Event top = fifoQueue.front();
    fifoQueue.erase(fifoQueue.begin());
    return top;

}

int FifoQueue::getSize() {
    return fifoQueue.size();
}

Event FifoQueue::peekTop() {
    if (fifoQueue.empty()) {
        cout<<"FIFO Queue is empty" <<endl;
        return Event{-1, -1};
    }
    return fifoQueue.front();
}