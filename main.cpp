#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>
#include "Pqueue.hpp"
#include "FifoQueue.hpp"
using namespace std;

    int lambda =5;
    int numProcesses= 1000;
    int mu= 3;
    int M= 2;
    

    double generateArrivalTime(double timeAlreadyPassed) {
        srand(time(0));
        double avg=1.0/lambda;
        double arrivalTime = -avg * log(1.0 - (rand() / (RAND_MAX + 1.0)));
        return arrivalTime;
    }

int main () {

    double totalTime=0;
    cout<< "Hello World!" << endl;

    FifoQueue fifo;
    Pqueue priorityQueue;
 
    double time=0;

    for (int i=0; i<200;i++){
        double arrivalTime = generateArrivalTime(time);
        time += arrivalTime;
        fifo.insert(time);
    }
    for (int i=0; i<200;i++){
        cout<< "Process " << i+1 << " arrival time: " << fifo.takeTop() << endl;
    }

}