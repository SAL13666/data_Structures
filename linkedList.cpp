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
        Node *getHead() {
            return head;
        }
        int getLength() {
            return length;
        }
        bool isSameOne(SinglyLinkedList &listTwo) { // time = o(n) space = o(1)
            //using length
            
            int listTwoLength = listTwo.getLength();
            Node *listOneHead = head, *listTwoHead = listTwo.getHead();
            if(listTwoLength != length) {
                return false;
            }
            while(listOneHead && listTwoHead) {
                if(listOneHead->data != listTwoHead->data) {
                    return false;
                }
                listOneHead = listOneHead->next, listTwoHead = listTwoHead->next;
            }
            return true;
        }
        bool isSameTwo(SinglyLinkedList &listTwo) { // time = o(n) space = o(1)
            //Without using length
            
            Node *listOneHead = head, *listTwoHead = listTwo.getHead();
            while(listOneHead && listTwoHead) {
                if(listOneHead->data != listTwoHead->data) {
                    return false;
                }
                listOneHead = listOneHead->next, listTwoHead = listTwoHead->next;
            }
            if(listOneHead != nullptr || listTwoHead != nullptr) {
                return false;
            }
            return true;
        }
};

int main() {
    SinglyLinkedList mySinglyLinkedList;
    SinglyLinkedList mySinglyLinkedListTwo;
    mySinglyLinkedList.insertBack(10);
    mySinglyLinkedList.insertBack(13);
    mySinglyLinkedList.insertBack(16);
    mySinglyLinkedListTwo.insertBack(10);
    mySinglyLinkedListTwo.insertBack(13);
    mySinglyLinkedListTwo.insertBack(15);
    cout<<mySinglyLinkedList.isSameTwo(mySinglyLinkedListTwo);
}