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



int main() {

    //Define Variables to pass into simulator constructor and simulateQUeueSystem Function

    int lambda1=0;
    int numProcesses1= 0;
    int mu1= 0;
    int M1= 0;
    int lambda2=0;
    int numProcesses2= 0;
    int mu2= 0;
    int M2= 0;

//open both txt files to draw out simulation values for both test cases

    ifstream inputFile("test1.txt");
    ifstream inputFile2("test2.txt");

    //checking if files opened correctly

    if(!inputFile.is_open()){
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    if (!inputFile2.is_open()){
        cout<<"Error opening file!"<<endl;
        return 1;
    }

    //drawing out the parameters for both test cases and storing them into needed variables

    inputFile >> lambda1 >> mu1 >> M1 >> numProcesses1;
    inputFile2 >> lambda2 >> mu2 >> M2 >> numProcesses2;
    inputFile.close();
    inputFile2.close();

//above is the closing of txt files after needed variables were acquired and below
//is the creation of two simulator class objects that will be used to run the simulateQueueSystem
//and get the appropriate statistical values for both test cases

     simulator sim(lambda1, numProcesses1, mu1, M1);
     simulator sim2(lambda2, numProcesses2, mu2, M2);
     sim.simulateQueueSystem(lambda1, numProcesses1, mu1, M1);
     sim2.simulateQueueSystem(lambda2, numProcesses2, mu2, M2);


//it is a bit messy but this is the output to the terminal of the results
//the calculated values were found through work done OUTSIDE of the code with statistical formulas
//provided by the professor 

    cout<<"Test 1 Results: " <<endl;
    cout<<endl;
    
    cout<<"Po: "<<sim.percentIdleTime/100<<" Percent Idle Time Versus Calculated Value : "<<".5" <<endl;
    cout<<"W: "<<sim.averageTimeInSystem<<" Average time in system Versus Calculated Value : "<<"0.375"<<endl;
    cout<<"Wq: "<<sim.avgTimeWaited<<" Average time waited Versus Calculated Value : 0.0417"<<endl;
    cout<<sim.chanceOfWaiting<<" Percentage of jobs that had to wait versus Calculated Value: 16.67"<<endl;
    cout<<sim.rho<<" Server Utilization (rho) Versus Calculated Value : 0.33 "<<endl;



    cout << "-----------------------------" << endl;





    cout<<"Test 2 Results: " <<endl;
    cout<<endl;

    cout<<"Po: "<<sim2.percentIdleTime/100<<" Percent Idle Time Versus Calculated Value : "<<".43" <<endl;
    cout<<"W: "<<sim2.averageTimeInSystem<<" Average time in system Versus Calculated Value : "<<"0.16725"<<endl;
    cout<<"Wq: "<<sim2.avgTimeWaited<<" Average time waited Versus Calculated Value : 0.000583"<<endl;
    cout<<sim2.chanceOfWaiting<<" Percentage of jobs that had to wait versus Calculated Value: 0.011"<<endl;
    cout<<sim2.rho<<" Server Utilization (rho) Versus Calculated Value : 0.208 "<<endl;
  
    return 0;
    
}
























