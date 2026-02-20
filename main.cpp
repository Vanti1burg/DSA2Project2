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
        double time= timeAlreadyPassed;
        double avg=1.0/lambda;
        double arrivalTime = -avg * log(1.0 - (rand() / (RAND_MAX + 1.0)));
        return arrivalTime+time;

    }
    double generateDepartureTime(double timeAlreadyPassed, double arrivalTime) {
        srand(time(0));
        double avg=1.0/mu;
        double timePassed= timeAlreadyPassed;
        double serviceInterval = -avg * log(1.0 - (rand() / (RAND_MAX + 1.0)));
        double departureTime=serviceInterval + timePassed;
        return departureTime;

    }

    

int main () {

    /*double totalTime=0;
    int totalServersAvailable=2;
    int processesCompleted=0;
    cout<< "Hello World!" << endl;

    FifoQueue fifo;
    Pqueue priorityQueue;
 
    double time=0;

    while(processesCompleted!=numProcesses) {


       if (priorityQueue.getSize() <M+1){
        for (int i=priorityQueue.getSize(); i<200; i++){
            double arrivalTime=generateArrivalTime(time);
            priorityQueue.insert(arrivalTime);
            time=time+arrivalTime;
        }

    }
    
*/

    FifoQueue fifo;
    fifo.insert(Event{1.0, 0});
    fifo.insert(Event{3.0, 0});

    Pqueue priorityQueue;
    priorityQueue.insert(Event{2.0, 0});
    priorityQueue.insert(Event{1.0, 0});
    cout<<"priority queue 1st element: "<<priorityQueue.peekTop().time<<endl;
    cout<<"fifo queue 1st element: "<<fifo.peekTop().time<<endl;
  
    return 0;

}
    


