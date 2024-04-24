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

        void linkNode(Node *firstNode, Node *secondNode) {
            if(secondNode == head) {
                firstNode->next = secondNode;
                secondNode->prev = firstNode;
                head = secondNode;

                return;
            } else {
                secondNode->prev->next = firstNode;
                firstNode->prev = secondNode->prev;
                firstNode->next = secondNode;
                secondNode->prev = firstNode;
            }
        }

    public:
        ArrayLinkedList(int length) : head(nullptr), tail(nullptr), length(length) {};

        ~ArrayLinkedList() { //O(n) time O(1) space
            while(head != nullptr) {
                Node *tempHead = head;
                head = head->next;
                delete tempHead;
            }
        };

        void printWithoutZero() { //O(n) time O(1) space
            Node *tempHead = head;
            while (tempHead != nullptr) {
                cout<< tempHead->data <<endl;
                tempHead = tempHead->next;
            }
        }

        void print() { //O(n) time O(1) space
            Node *tempHead = head;
            int counter = 1;
            while (tempHead != nullptr) {
                if(counter == tempHead->index) {
                    cout<< tempHead->data <<endl;
                    tempHead = tempHead->next;
                } else  {
                    cout<<0<<endl;
                }
                counter++;
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

        int getValue(int index) { //O(n) time O(1) space
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                if(tempHead->index == index) {
                    return tempHead->data;
                }
            }

            return -1;
        }

        void add(ArrayLinkedList secondArray) {
            for(Node *firstHead = head, *secondHead = secondArray.head; secondHead; secondHead = secondHead->next) {
                if(firstHead) {
                    if(firstHead->index == secondHead->index) {
                        firstHead->data += secondHead->data;
                        firstHead = firstHead->next;
                    } else {
                        Node *newNode = new Node(secondHead->data, secondHead->index);
                        if(firstHead->next) {
                            linkNode(newNode, firstHead);
                        }
                    }
                } else {
                    Node *newNode = new Node(secondHead->data, secondHead->index);
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
            }
        }

};


int main(void) {
    ArrayLinkedList myArray(2);
    ArrayLinkedList my2ndArray(5);
    myArray.setValue(2, 2);
    myArray.setValue(1, 1);
    my2ndArray.setValue(5, 1);
    my2ndArray.setValue(5, 2);
    my2ndArray.setValue(10, 3);
    myArray.add(my2ndArray);

    myArray.printWithoutZero();

    cout<<endl<<myArray.getValue(7)<<endl;
}