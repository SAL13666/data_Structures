#include <iostream>
using namespace std;

class Stack {
    private:
        int size {};
        int top {};
        int *arr {};

        void resizeStack() { // O(n) time O(n) space
            size = size * 2;
            int *newArr = new int[size];
            for(int i = 0; i <= top; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }


    public:
        ~Stack() { // O(1) time O(1) space
            delete[] arr;
            arr = nullptr;
        }

        Stack(int size) : size(size), top(-1) { // O(1) time O(n) space
            arr = new int[size];
        }

        void print() { // O(n) time O(1) space
            for(int i = 0; i <= top; i++) {
                cout<<endl<<arr[i]<<endl;
            }
        }

        void push(int value) { // O(1) time O(1) space
            if(top == size - 1) {
                resizeStack();
            }

            arr[++top] = value;
        }

        int pop() { // O(1) time O(1) space
            //we can use here two approches either we lazy delete or we make a new array that doesnt have the element

            return arr[top--];
        }

        int peek() { // O(1) time O(1) space
            return arr[top];
        }
};


int main(void) {
    Stack myStack(1);
    myStack.push(10);
    myStack.push(20);
    myStack.print();
    cout<<myStack.peek();
}