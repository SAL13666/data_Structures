#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node *next {};
    Node *prev {};

    Node(int data) : data(data) {};
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {};

        ~DoublyLinkedList() { //O(n) time O(1) space
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

        void insertEnd(int value) { //O(1) time O(1) space
            Node * newNode = new Node(value);
            newNode->prev = tail;
            if(!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void insertFront(int value) { //O(1) time O(1) space
            Node * newNode = new Node(value);
            newNode->next = head;
            if(!head) {
                head = tail = newNode;
            } else {
                head->prev = newNode;
                head = newNode;
            }
        }

        void insertSorted(int value) { //O(n) time O(1) space
            if(value <= head->data) {
                insertFront(value);
            } else if(value >= tail->data) {
                insertEnd(value);
            } else {
                for(Node * tempHead = head->next; tempHead != nullptr; tempHead = tempHead->next) {
                    if(value <= tempHead->data) {
                        Node *newNode = new Node(value);
                        newNode->prev = tempHead->prev;
                        tempHead->prev->next = newNode;
                        newNode->next = tempHead;
                        tempHead->prev = newNode;
                    }
                }
            }
        }

    void deleteFront() { //O(1) time O(1) space
        if(!head) {
            return;
        }
        if(head->next == nullptr) {
            head = tail = nullptr;
        }
        Node *newHead = head->next;
        delete head;
        newHead->prev = nullptr;
        head = newHead;
    }

    void deleteEnd() { //O(1) time O(1) space
        if(!head) {
            return;
        }
        if(head->next == nullptr) {
            delete head;
            head = tail = nullptr;
        }
        Node *newTail = tail->prev;
        delete tail;
        newTail->next = nullptr;
        tail = newTail;
    }
};


int main(void) {
    DoublyLinkedList myLinkedList;
    myLinkedList.insertEnd(10);
    myLinkedList.insertEnd(20);
    myLinkedList.insertEnd(30);
    myLinkedList.insertEnd(40);
    myLinkedList.insertSorted(15);
    myLinkedList.insertSorted(95);
    myLinkedList.insertSorted(-10);
    myLinkedList.insertFront(0);
    myLinkedList.deleteFront();
    myLinkedList.deleteFront();
    myLinkedList.print();

}