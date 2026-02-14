#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Pqueue {
    private:

        vector<int> heapQueue;
        int size;

    public:

        Pqueue() {
            size = 0;
        }

        void insert(int value) {

            heapQueue.push_back(value);
            size++;
            int i = size - 1;
            while (i>0){

                int parent = (i-1)/2;

                if (heapQueue[i] > heapQueue[parent]){
                    swap(heapQueue[i], heapQueue[parent]);
                    i=parent;

                }
            }
        }
        
      int takeTop() {

            if (size == 0) {
                cout<<"Priority Queue is empty" <<endl;
                return -1;
            }

            int top = heapQueue[0];

            heapQueue[0] = heapQueue[size - 1];

            heapQueue.pop_back();

            size--;

            int i = 0;

            while (true) {

                int leftChild = 2 * i + 1;
                int rightChild = 2 * i + 2;
                int largest = i;

                if (leftChild < size && heapQueue[leftChild] > heapQueue[largest]) {

                    largest = leftChild;

                }
                if (rightChild < size && heapQueue[rightChild] > heapQueue[largest]) {

                    largest = rightChild;

                }

                if (largest != i) {

                    swap(heapQueue[i], heapQueue[largest]);

                    i = largest;

                } else {

                    break;

                }
            }
            return top;
        }


        int getSize() {

            return size;

        }


        

};

class FifoQueue {
    private:
        vector <int> fifoQueue;
    public:
      
        void insert(int value) {
            fifoQueue.push_back(value);

        }



        int takeTop() {
            if (fifoQueue.empty()) {
                cout<<"FIFO Queue is empty" <<endl;
                return -1;
            }
            int top = fifoQueue.front();
            fifoQueue.erase(fifoQueue.begin());
            return top;

        }
        int getSize() {
            return fifoQueue.size();
        }

};

int main () {

    cout<< "Hello World!" << endl;
    return 0;

}