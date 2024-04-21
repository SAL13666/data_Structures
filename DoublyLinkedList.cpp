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
};


int main(void) {
    DoublyLinkedList myLinkedList;
    myLinkedList.insertEnd(10);
    myLinkedList.insertEnd(20);
    myLinkedList.insertEnd(30);
    myLinkedList.insertEnd(40);
    myLinkedList.print();

}