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
            delete head;
            head = tail = nullptr;
            return;
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
            return;
        }
        Node *newTail = tail->prev;
        delete tail;
        newTail->next = nullptr;
        tail = newTail;
    }

    Node* deleteAndLink(Node *node) { //O(1) time O(1) space
        Node* current = node->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return current;
    }

    void deleteNodeWithKey(int value) { //O(n) time O(1) space  // has bug
        if(!head) {
            return;
        }
        if(head->data == value) {
            deleteFront();
        } else if (tail->data == value) {
            deleteEnd();
        } else {
            for(Node * tempHead = head->next; tempHead != nullptr; tempHead = tempHead->next) {
                if(value == tempHead->data) {
                    tempHead = deleteAndLink(tempHead);
                }
            }
        }
    }
};


int main(void) {
    DoublyLinkedList myLinkedList;
    myLinkedList.insertFront(0);
    myLinkedList.deleteNodeWithKey(0);
    myLinkedList.insertEnd(1);
    myLinkedList.insertEnd(2);
    myLinkedList.insertEnd(3);
    myLinkedList.print();

}