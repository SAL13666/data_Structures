#include <iostream>
#include <cmath>
using namespace std;

class Vector {
    private:
        int *myVector = nullptr;
        int size = 1;
        int capacity = 1;
        void resizeVector() {
            capacity = ceil(size * 2);
            int *newVector = nullptr;
            newVector = new int[capacity];
            swap(myVector, newVector);
        }
    public:
        Vector(int size_) {
            size = size_;
            myVector = new int[size];
            capacity = size;
            for(int i = 0; i < size; i++) {
                myVector[i] = 0;
            }
        };
        ~Vector() {
            delete[] myVector;
        };
        void print() {
            for(int i = 0; i < size; i++) {
                cout<< myVector[i]<<endl;
            }
        }
        void pushBack(int value) {
            if(size == capacity) {

            }
        }
};


int main() {
    Vector myVector(5);
    myVector.print();
}