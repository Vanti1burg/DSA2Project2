

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

void Pqueue::insert(double value) {
    heapQueue.push_back(value);
    size++;

    int currentIndex = size - 1;

    while (currentIndex > 0) {

        int parentIndex = (currentIndex - 1) / 2;

        if (heapQueue[currentIndex] < heapQueue[parentIndex]) {

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

double Pqueue:: getTop() {

            if (size == 0) {

                cout<<"Priority Queue is empty" <<endl;

                return -1;

            }

            double top = heapQueue[0];

            heapQueue[0] = heapQueue[size - 1];

            heapQueue.pop_back();

            size--;

            int currentIndex = 0;



            while (true) {


                int leftChildIndex = 2 * currentIndex + 1;
                int rightChildIndex = 2 * currentIndex + 2;
                int smallestIndex = currentIndex;

                if (leftChildIndex < size && heapQueue[leftChildIndex] < heapQueue[smallestIndex]) {

                    smallestIndex = leftChildIndex;

                }

                if (rightChildIndex < size && heapQueue[rightChildIndex] < heapQueue[smallestIndex]) {

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