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

        bool isEmpty() { // O(1) time O(1) space
            if(top == -1) {
                return true;
            }

            return false;
        }

        int pop() { // O(1) time O(1) space
            //we can use here two approches either we lazy delete or we make a new array that doesnt have the element

            return arr[top--];
        }

        int peek() { // O(1) time O(1) space

            if(isEmpty()) {
                return -1;
            }

            return arr[top];
        }

};

string reverseSubwords(string text) { // O(1) time O(1) 
    string newText = "";
    Stack tempStack(text.length());

    for(int i = 0; i < text.length(); i++) {
        int charcterAsciiCode = text.at(i); 

        if(charcterAsciiCode != 32) {
            tempStack.push(charcterAsciiCode);
        } else {
            while(!tempStack.isEmpty()) {
                newText+= (char)tempStack.peek();
                tempStack.pop();
            }

            newText+= " ";
        }

    }

    while(!tempStack.isEmpty()) {
        newText+= (char)tempStack.peek();
        tempStack.pop();
    }

    return newText;
}


int main(void) {
    Stack myStack(1);
    myStack.push(10);
    myStack.push(20);
    myStack.print();
    string reversedSubword = reverseSubwords("abc d efg xy");
    cout<<reversedSubword;
    cout<<myStack.peek();
}