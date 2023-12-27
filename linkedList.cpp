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

class SinglyLinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length;
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
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                cout<<tempHead->data<<endl;
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
        }
};

int main() {
    SinglyLinkedList mySinglyLinkedList;
    mySinglyLinkedList.insertBack(10);
    mySinglyLinkedList.insertBack(13);
    mySinglyLinkedList.insertBack(16);
    mySinglyLinkedList.print();
}