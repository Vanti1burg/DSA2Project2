
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


simulator::simulator(int lambda, int numProcesses, int mu, int M) {
    this->lambda = lambda;
    this->numProcesses = numProcesses;
    this->mu = mu;
    this->M = M;
    

}
void simulator::simulateQueueSystem(int lambda, int numProcesses, int mu, int M) {

     srand(time(0));

        Pqueue priorityQueue;
        FifoQueue fifo;
        double time=0.0;
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
     
        while(processesCompleted <numProcesses){

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
            
            if (priorityQueue.peekTop().type==0 && totalServersAvailable>0){

                if (serversIdle==M){
                    totalIdleTime+= priorityQueue.peekTop().time - time;
                }

               
               
                lastEventTime=priorityQueue.peekTop().time;
                Event arrivalEvent = priorityQueue.getTop();
                time=arrivalEvent.time;
             
                totalTimeWaited+=0;
            
                totalServersAvailable--;
                serversIdle=totalServersAvailable;
                arrivalEvent.departureTime=generateDepartureTime(arrivalEvent.time);
                arrivalEvent.time=arrivalEvent.departureTime;
                totalTimeInSystem+= arrivalEvent.departureTime - arrivalEvent.arrivalTime;
             
                
                arrivalEvent.type=1;
             
                priorityQueue.insert(arrivalEvent);
                
                
               
            }
            if (priorityQueue.peekTop().type==1){

                Event departureEvent= priorityQueue.getTop();
                totalServersAvailable++;
                processesCompleted++;
                time=departureEvent.time;
               
                serversIdle++;

                
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
               
              
                totalBusyTime+=(departureEvent.time - departureEvent.arrivalTime);
                totalCustomersInSystem+=fifo.getSize()+priorityQueue.getSize();
            }
            
            if (priorityQueue.peekTop().type==0 && totalServersAvailable==0){

                Event arrivalEvent= priorityQueue.getTop();
                fifo.insert(arrivalEvent);
                time=arrivalEvent.time;
                numOfJobsWaited++;
                

              
            }
        }
        double jobsWaited=numOfJobsWaited;
        double jobsCompleted=processesCompleted;
        std::cout<<"Percent Idle Time : " << (totalIdleTime / time) * 100.0 << "%" <<endl;
        std::cout<<"Average time in system: "<< totalTimeInSystem/(numProcesses)<<endl;
        std::cout<<"Average time waited: "<< totalTimeWaited/numProcesses<<endl;
        std::cout<<"Percentage of jobs that had to wait: "<< (jobsWaited/jobsCompleted)<<"%"<<endl;
        std::cout<<"Server Utilization (rho): " << totalBusyTime/(M*time) <<endl;
       
        


    }

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
