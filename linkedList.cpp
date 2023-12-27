#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data): data(data) {};
};

class SinglyLinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length = 0;
    public:
        ~SinglyLinkedList() {
            while (head) //time = o(n) space = o(1)
            {
                Node *current = head->next;
                delete head;
                head = current;
            }
            
        };
        
        void print() { //time = o(n) space = o(1)
        Node *tempHead = head;
            while(tempHead != nullptr) {
                cout<<tempHead->data<< endl;
                tempHead = tempHead->next;
            }
        }

        void insertBack(int value) { // time = o(1) space = o(1)
            Node *newNode = new Node(value);
            if(!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
                tail->next = nullptr;
            }
            length++;
        }

        void insertFront(int value) { // time = o(1) space = o(1)
            Node *newNode = new Node(value);
            if(!head) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFront() { // time = o(1) space = o(1)
            if(head) {
                Node *current = head->next;
                delete head;
                head = current;
                if (!head) {
                    tail = nullptr;
                }
                length--;
            }
        }
        int getNthFromBack(int index) { // time = o(n) space = o(1)
            if(index < 0 || index > length) {
                return -1;
            }
            index = length - index - 1;
            Node *tempHead = head;
            for(int i = 0; i < index; i++) {
                tempHead = tempHead->next;
            }
            return tempHead->data;
        }
        int getNthFromFront(int index) { // time = o(n) space = o(1)
            if(index < 0 || index > length) {
                return -1;
            }
            Node *tempHead = head;
            while(index) {
                tempHead = tempHead->next;
                index--;
            }
            return tempHead->data;
        }
};

int main() {
    SinglyLinkedList mySinglyLinkedList;
    mySinglyLinkedList.insertBack(10);
    mySinglyLinkedList.insertBack(13);
    mySinglyLinkedList.insertBack(16);
    cout<<mySinglyLinkedList.getNthFromFront(100);
}