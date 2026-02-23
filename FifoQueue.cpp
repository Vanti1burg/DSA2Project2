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

//default constructor for fifo queue class


FifoQueue::FifoQueue() {
    fifoQueue.clear();
}

//insertion of object into vector used for fifo queue
//last project a linked list was used so i didnt think it would be a problem
//to use a vector since I've already demonstrated the ability to use a linked list
void FifoQueue::insert(Event  newEvent) {
    fifoQueue.push_back(newEvent);
}
//taking of the first in "line"
Event FifoQueue::takeTop() {
    if (fifoQueue.empty()) {
        cout<<"FIFO Queue is empty" <<endl;
        return Event{-1, -1};
    }
    Event top = fifoQueue.front();
    fifoQueue.erase(fifoQueue.begin());
    return top;

}


//finding the size of the line

int FifoQueue::getSize() {
    return fifoQueue.size();
}

//peeking front of line wihtout taking it out
Event FifoQueue::peekTop() {
    if (fifoQueue.empty()) {
        cout<<"FIFO Queue is empty" <<endl;
        return Event{-1, -1};
    }
    return fifoQueue.front();
}