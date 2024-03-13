#include <iostream>
#include <cmath>
using namespace std;
template <class T>
class Vector {
    private:
        T *data = nullptr;
        int size = 0;
        int capacity = 1;

        void resizeVector() { //O(n) time O(capacity) space
            capacity = ceil(size * 2);
            T *newVector = new T[capacity] {0};
            for(int i = 0; i < size; i++) {
                newVector[i] = data[i];
            }
            swap(newVector, data);
            delete[] newVector;
        }

    public:
        Vector() : Vector(1) {}

        Vector(int _size) : size(_size), data(new T[size]) { //O(n) time O(n) space
            for(int i = 0; i < size; i++) {
                data[i] = 0;
            }
        };

        ~Vector() {
            delete[] data;
            data = nullptr;
        }

        void printVector() { //O(n) time O(1) space
            for(int i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout<<"\n";
        }

        int getValueUsingIndex(int index) { //O(1) time O(1) space
            if(index >= size || index < 0) {
                return -1;
            }
            return data[index];
        }

        int setValueUsingIndex(int index, T value) { //O(1) time O(1) space
            if(index >= size || index < 0) {
                return -1;
            }

            data[index] = value;
            return 1;
        }

        int find(T value) {
            for(int i = 0; i < size; i++) { //O(n) time O(1) space
                if(value == data[i])
                    return i;
            }
            return -1;
        }

        void pushBack(T value) { //O(n) time O(capacity) space
            if(size >= capacity) {
                resizeVector();
            }

            data[size] = value;
            size++;
        }

        int insertValue(int index, T value) { //O(n) time O(capacity) space
            if(index < 0 || index > size) {
                return -1;
            }

            if(size >= capacity) {
                resizeVector();
            }

            for(int i = size - 1; i >= index; i--) {
                data[i + 1] = data[i];
            }

            data[index] = value;
            size++;
            return 1;
        }

        void rotateRight() { //O(n) time O(capacity) space
            int value = data[size - 1];
            insertValue(0, value);
            size--;
        }

        void rotateLeft() { //O(n) time O(1) space
            int value = data[0];
            for(int i = 0; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            data[size - 1] = value;
        }

        void rotateRightWithSteps(int steps) { //O(n) time O(n) space
            steps %= size;
            for(int i = 0; i < steps; i++) {
                rotateRight();
            }
        }

        T deleteUsingPosition(int index) { //O(n) time O(1) space
            T value = data[index];

            for(int i = index + 1; i < size; i++) {
                data[i - 1] = data[i];
            }

            size--; 
            return value; 
        }
};


int main() {
    Vector<int> myVector(5); 
}