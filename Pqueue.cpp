

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


//insertion for priority queue, automatically sorts the heap after insertion to mantain min heap status

void Pqueue::insert(Event newEvent) {
    heapQueue.push_back(newEvent);
    size++;

    int currentIndex = size - 1;
    //checking the time value of the current event with its parent and swapping if child is smaller than parent
    while (currentIndex > 0) {

        int parentIndex = (currentIndex - 1) / 2;

        if (heapQueue[currentIndex].time < heapQueue[parentIndex].time) {

            swap(heapQueue[currentIndex], heapQueue[parentIndex]);

            currentIndex = parentIndex;

        } else {

            break;

        }
    }
}

Pqueue::Pqueue() {
    size = 0;
}
//removal of top element of min heap then sorting the heap to maintain min heap status
Event Pqueue:: getTop() {

            if (size == 0) {

                cout<<"Priority Queue is empty" <<endl;

                return Event{-1, -1};

            }

            Event top = heapQueue[0];

            heapQueue[0] = heapQueue[size - 1];

            heapQueue.pop_back();

            size--;

            int currentIndex = 0;



            while (true) {

             //child and smallest index are determined, not the right child is 2*index+2 due to the way the heap is stored in a vector

                int leftChildIndex = 2 * currentIndex + 1;
                int rightChildIndex = 2 * currentIndex + 2;
                int smallestIndex = currentIndex;
            //smallest index is determined by comparing the current index with children and swapping if necessary until 
            //smallest index is the current index meaning the min heap has been restored

                if (leftChildIndex < size && heapQueue[leftChildIndex].time < heapQueue[smallestIndex].time) {

                    smallestIndex = leftChildIndex;

                }

                if (rightChildIndex < size && heapQueue[rightChildIndex].time < heapQueue[smallestIndex].time) {

                    smallestIndex = rightChildIndex;

                }

                if (smallestIndex != currentIndex) {

                    swap(heapQueue[currentIndex], heapQueue[smallestIndex]);

                    currentIndex = smallestIndex;

                } 
                else {

                    break;
                }



            }

            return top;
        }


int Pqueue::getSize() {

            return size;

        }
//peeking top element of min heap without taking it
Event Pqueue::peekTop() {
    if (size == 0) {
        cout<<"Priority Queue is empty" <<endl;
        return Event{-1, -1};
    }
    return heapQueue[0];
}        