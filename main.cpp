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

    int lambda1=0;
    int numProcesses1= 0;
    int mu1= 0;
    int M1= 0;
    int lambda2=0;
    int numProcesses2= 0;
    int mu2= 0;
    int M2= 0;

    ifstream inputFile("test1.txt");
    ifstream inputFile2("test2.txt");

    if(!inputFile.is_open()){
        cout<<"Error opening file!"<<endl;
        return 1;
    }

    inputFile >> lambda1 >> mu1 >> M1 >> numProcesses1;
    inputFile2 >> lambda2 >> mu2 >> M2 >> numProcesses2;
    inputFile.close();
    inputFile2.close();

     simulator sim(lambda1, numProcesses1, mu1, M1);
     simulator sim2(lambda2, numProcesses2, mu2, M2);
     cout<<"Test 1 Results: " <<endl;
     cout<<endl;
     sim.simulateQueueSystem(lambda1, numProcesses1, mu1, M1);
     cout<<endl;
     cout<<" VS. Projected Results for Test 1: " <<endl;
     cout<<endl;
     cout<<"Percent Idle Time : 0.5 or 50%"<<endl;
     cout<<"Average time in system of : 0.375"<<endl;
     cout<<"Average time waited of : 0.0417:"<<endl;

     cout << "-----------------------------" << endl;
     cout<<"Test 2 Results: " <<endl;
     cout<<endl;
     sim2.simulateQueueSystem(lambda2, numProcesses2, mu2, M2);
     cout<<endl;
     cout<<" VS. Projected Results for Test 2: " <<endl;
     cout<<endl;
     cout<<"Percent Idle Time : 0.43 or 43%"<<endl;
     cout<<"Average time in the system of 0.16725"<<endl;
     cout<<"Average time waited of : 0.000583"<<endl;
     
   
  
  
    return 0;
}
























