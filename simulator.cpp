
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
#include "simulator.hpp"

using namespace std;

//Constructor for simulator class that initializes the parameters for the queue simulation

simulator::simulator(int lambda, int numProcesses, int mu, int M) {
    this->lambda = lambda;
    this->numProcesses = numProcesses;
    this->mu = mu;
    this->M = M;
    

}

//simulation system that runs the actual queue simulation and alters public variables for main.cpp to access and use for outputting results to terminal

void simulator::simulateQueueSystem(int lambda, int numProcesses, int mu, int M) {

     srand(time(0));
    //priorty queue that will act as the scheduler to this system and fifo queue that acts as a "line" for events to wait for a server
        Pqueue priorityQueue;
        FifoQueue fifo;
    
        //time variable to keep track of current time of the simulation
        double time=0.0;

//variables to keep track of values needed for statistical analysis of the system after the simulation is complete
//some of these may be redundant but I kept them in for testing purposes and debugging certain processes

        int processesCompleted=0;
        int totalServersAvailable=M;
        int totalCustomersInSystem=0;
        double totalIdleTime=0.0;
        double totalTimeInSystem=0.0;
        double totalTimeWaited=0.0;
        int numOfJobsWaited=0;
        double generationTime=0.0;
        double totalBusyTime=0.0;
        double lastEventTime=0.0;

     //main event loop that runs until certain amount of jobs are complete

        while(processesCompleted <numProcesses){

            //this is an initial event generator that creates the arrival events 
            // triggers when priority queue has too few events in it
            // has a different time value so that it can generate properly spaced out arrivals without
            //the rest of the simulation being affected by the time changes

            if (priorityQueue.getSize() <=M+1){
                for (int i=priorityQueue.getSize(); i<200;i++){

                    Event newEvent;
                    newEvent.time=generateArrivalTime(generationTime);
                    newEvent.type=0;

                    newEvent.arrivalTime=newEvent.time;
                    priorityQueue.insert(newEvent);
                    generationTime=newEvent.time;

                }

            }
            //First option for priority queue processing which is that the event is an arrival and servers are available
            //event is processed immediately and given departure time and put back into PQ

            if (priorityQueue.peekTop().type==0 && totalServersAvailable>0){

                if (serversIdle==M){
                    totalIdleTime+= priorityQueue.peekTop().time - time;
                }
                //idle measurement is done by seeing if both servers are idle and then adding 
                //the time between the last event and the current event to the total idle time
               
               //last event time is updated to the next events time

                lastEventTime=priorityQueue.peekTop().time;

                //new event is processed and given a departure time and put back into the priority queue with type 1 to indicate it is a departure event 

                Event arrivalEvent = priorityQueue.getTop();

                time=arrivalEvent.time;
             
               //decrement servers available
            
                totalServersAvailable--;

             //set the amount of idle servers

                serversIdle=totalServersAvailable;

             //departure event is generated and totalTimeInSystem for event is determined by its arrival and dep date

                arrivalEvent.departureTime=generateDepartureTime(arrivalEvent.time);

                arrivalEvent.time=arrivalEvent.departureTime;

                totalTimeInSystem+= arrivalEvent.departureTime - arrivalEvent.arrivalTime;
             
                
                arrivalEvent.type=1;
             
                priorityQueue.insert(arrivalEvent);
                
                
               
            }
            //second option for priority queue when a departure reaches top 
            if (priorityQueue.peekTop().type==1){

                Event departureEvent= priorityQueue.getTop();
                totalServersAvailable++;
                processesCompleted++;
                time=departureEvent.time;
               //departure event is pulled out and data is updated for variables before event is completely gone

                serversIdle++;
                //inc servers idle since server just completed a job
                
                //check fifo queue to see if another job can be pulled out
                //if it the idle measurement is done again and then
                //the next event is processed and given a departure time 
                //and its total time in the queue and system are both calculated using
                //the departure time of the last event and the arrival/departure of the next event


                if (fifo.getSize()>0){

                    if (serversIdle==M){
                        totalIdleTime+= departureEvent.time - lastEventTime;
                    }

                    lastEventTime=departureEvent.time;

                    Event nextArrival=fifo.takeTop();
                    
                    nextArrival.time=departureEvent.time;
                    totalTimeWaited+= departureEvent.time -nextArrival.arrivalTime;
                    


                    nextArrival.time=generateDepartureTime(nextArrival.time);

                    nextArrival.type=1;

                    totalTimeInSystem+= departureEvent.time - nextArrival.arrivalTime;
                    
                    nextArrival.departureTime=nextArrival.time;

                    priorityQueue.insert(nextArrival);

                    totalServersAvailable--;

                    serversIdle--;

                }
               
                //total busy time is updated by the time between arrivals and departures and total customers in system is updated
                //by the amount of jobs in the system as of now to help with the rho calculation at the end
              
                totalBusyTime+=(departureEvent.time - departureEvent.arrivalTime);
                totalCustomersInSystem+=fifo.getSize()+priorityQueue.getSize();
            }
            //third option where no servers are available and the event is an arrival
            //meaning it must go into the queue

            if (priorityQueue.peekTop().type==0 && totalServersAvailable==0){

                Event arrivalEvent= priorityQueue.getTop();
                fifo.insert(arrivalEvent);
                time=arrivalEvent.time;
                numOfJobsWaited++;
                

              
            }
        }

        //after the simulation important statistics are calculated using data from the simulation
        double jobsWaited=numOfJobsWaited;
        double jobsCompleted=processesCompleted;
        percentIdleTime= (totalIdleTime / time) * 100.0;
        averageTimeInSystem= totalTimeInSystem/(numProcesses);
        avgTimeWaited= totalTimeWaited/numProcesses;
        chanceOfWaiting= (jobsWaited/jobsCompleted);
        rho= totalBusyTime/(M*time);
     


    }

//uses negative exponential distribution to generate arrival and dep times depending using a lambda or mu depending on whether it 
//is an arrival or dep event

double simulator::generateArrivalTime(double timeAlreadyPassed) {
         double time= timeAlreadyPassed;
        double avg=1.0/lambda;
        double arrivalTime = -avg * log(1.0 - (rand() / (RAND_MAX + 1.0)));
        return arrivalTime+time;
}
double simulator::generateDepartureTime(double timeAlreadyPassed) {
        double avg=1.0/mu;
        double timePassed= timeAlreadyPassed;
        double serviceInterval = -avg * log(1.0 - (rand() / (RAND_MAX + 1.0)));
        double departureTime=serviceInterval + timePassed;
        return departureTime;

}

using namespace std;
