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
};


int main(void) {

}