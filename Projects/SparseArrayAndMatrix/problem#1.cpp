#include <iostream>
using namespace std;

struct Node {
    int data = 0;
    int index = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data, int index) : data(data), index(index) {}; 
};

class ArrayLinkedList {
    private:
        Node *head;
        Node *tail;
        int length = 0;

    public:
        ArrayLinkedList(int length) : head(nullptr), tail(nullptr), length(length) {};

        ~ArrayLinkedList() { //O(n) time O(1) space
            while(head != nullptr) {
                Node *tempHead = head;
                head = head->next;
                delete tempHead;
            }
        };

        void print() { //O(n) time O(1) space
            Node *tempHead = head;
            while (tempHead != nullptr) {
                cout<< tempHead->data <<endl;
                tempHead = tempHead->next;
            }
        }

        void setValue(int value, int index) { //O(n) time O(1) space
            if(index > length || index < 0) {
                return;
            }

                if(!head) {
                    Node *newNode = new Node(value, index);
                    head = tail = newNode;
                    return;
                }

            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                if(tempHead->index == index) {
                    tempHead->data = value;
                    return;
                }

                if(tempHead->index > index) {
                    if(tempHead == head) {
                        Node *newNode = new Node(value, index);
                        newNode->next = tempHead;
                        tempHead->prev = newNode;
                        head = newNode;
                    } else {
                        Node *newNode = new Node(value, index);
                        newNode->next = tempHead;
                        newNode->prev = tempHead->prev;
                        newNode->prev->next = newNode;
                        tempHead->prev = newNode;
                    }
                    return;
                } else if (!tempHead->next) {
                    Node *newNode = new Node(value, index);
                    tempHead->next = newNode;
                    newNode->prev = tempHead;
                    tail = newNode;
                    return;
                }
            }
        }

};


int main(void) {
    ArrayLinkedList myArray(1000);
    myArray.setValue(2, 2);
    myArray.setValue(1, 1);
    myArray.setValue(100, 100);
    myArray.setValue(50, 50);
    myArray.setValue(1000, 1000);
    myArray.print();
}