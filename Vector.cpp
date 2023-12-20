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
            for(int i = 0; i < size; i++) {
                newVector[i] = myVector[i];
            }
            swap(myVector, newVector);
            delete[] newVector;
            newVector = nullptr;
        }
    public:
        Vector(int size_ = 0) {
            size = size_;
            myVector = new int[size];
            capacity = size;
            for(int i = 0; i < size; i++) {
            myVector[i] = i;
            }
        };
        ~Vector() {
            delete[] myVector;
            myVector = nullptr;
        };
        void print() {
            for(int i = 0; i < size; i++) {
                cout<< myVector[i]<<endl;
            }
        }
        void pushBack(int value) {
            if(size == capacity) {
                resizeVector();
            }
            myVector[size] = value;
            size++;
        }
        int getCapacity() {
            return capacity;
        }
        void insert(int value, int index) {
            if(size == capacity) {
                resizeVector();
            }
            for(int i = size - 1; i >= index; i--) {
                myVector[i + 1] = myVector[i];
            }
            myVector[index] = value;
            size++;
        }
        void rightRotate() {
            int lastValue = myVector[size - 1];
            size--;
            insert(lastValue, 0);
        }
};


int main() {
    Vector myVector(5); 
    myVector.rightRotate();
    myVector.print();
}