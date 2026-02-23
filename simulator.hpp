#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
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


//This is the class header file for the simulator class
//not much is needed to know about this file except for the public variables that are used to store
//statistical values

using namespace std;

class simulator {
    public:

        simulator(int lambda, int numProcesses, int mu, int M);

        void simulateQueueSystem( int lambda, int numProcesses, int mu, int M);
        double generateArrivalTime(double timeAlreadyPassed);
        double generateDepartureTime(double timeAlreadyPassed);
        double avgTimeWaited=0.0;
        double percentIdleTime=0.0;
        double averageTimeInSystem=0.0;
        double chanceOfWaiting=0.0;
        double rho=0.0;
    private:
        int lambda =0;
        int numProcesses= 0;
        int mu= 0;
        int M= 0;
         double totalIdleTime = 0.0;
        double lastEventTime = 0.0;
        double totalTimeInSystem=0.0;
        int totalServers = 2;
        int serversIdle = totalServers;
        double totalTimeWaited=0;
       

};


#endif 