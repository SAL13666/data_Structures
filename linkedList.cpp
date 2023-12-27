#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data): data(data) {};
    ~Node() {
        delete next;
        next = nullptr;
    }
};

class LinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length;
    public:
        void print() {
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                cout<<tempHead->data<<endl;
            }
        }
        void insertBack(int value) {
            Node *newNode = new Node(value);
            if(!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
                tail->next = nullptr;
            }
        }
};

int main() {
    LinkedList myLinkedList;
    myLinkedList.insertBack(10);
    myLinkedList.insertBack(13);
    myLinkedList.insertBack(16);
    myLinkedList.print();
}