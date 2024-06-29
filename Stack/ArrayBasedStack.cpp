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

string reverseSubwords(string text) { // O(n) time O(n) space
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

int reverseNumber(int number) { // O(n) time O(n) space
    if(number == 0) {
        return -1;
    }

    string tempNumber = to_string(number);
    int newNumber = 0;
    Stack myStack(to_string(number).length());
    int tens = 1;

    for(int i = 0; i < tempNumber.length(); i++) {
        myStack.push(number % 10);
        number /= 10;
    }

    while(!myStack.isEmpty()) {
        newNumber = tens * myStack.peek() + newNumber;
        tens *= 10;
        myStack.pop();
    }

    return newNumber;
}


int main(void) {
    Stack myStack(1);
    myStack.push(10);
    myStack.push(20);
    myStack.print();
    cout<<reverseNumber(123);
    // string reversedSubword = reverseSubwords("abc d efg xy");
    // cout<<reversedSubword;
    // cout<<myStack.peek();
}