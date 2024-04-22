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

        void deleteNodeWithKey(int value) { //O(n) time O(1) space
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

        void deleteAllNodesWithKey(int value) { //O(n) time O(1) space
            if(!head) {
                return;
            }

            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                if(tempHead->data == value) {
                    if(!head->next) {
                        delete head;
                        head = tail = nullptr;
                        return;
                    }

                    if(tempHead->prev) {
                        if(!tempHead->next) {
                            tempHead->prev->next = nullptr;
                            tail = tempHead->prev;
                            delete tempHead;
                            tempHead = tail;
                        } else {
                            tempHead = deleteAndLink(tempHead);
                        }
                    } else {
                        Node *next = tempHead->next;
                        delete tempHead;
                        next->prev = nullptr;
                        tempHead = head = next;
                    }
                }
            }
        }

        void deleteEvenPositions() { //O(n) time O(1) space
            if(!head || !head->next) {
                return;
            }

            int counter = 1;

            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                if(counter % 2 == 0) {
                    if(!tempHead->next) {
                        tempHead->prev->next = nullptr;
                        tail = tempHead->prev;
                        delete tempHead;
                        tempHead = tail;
                        return;
                    }
                    tempHead = deleteAndLink(tempHead);
                }
                counter++;
            }
        }

        void deleteOddPositions() { //O(n) time O(1) space
            insertFront(0);
            deleteEvenPositions();
            deleteFront();
        }

        bool isPalindrome() { //O(n) time O(1) space
            for(Node *tempHead = head, *tempTail = tail; tempHead != tempTail; tempHead = tempHead->next, tempTail = tempTail->prev) {
                if(tempHead->data != tempTail->data) {
                    return false;
                }
            }

            return true;
        }

        int findMiddle() { //O(n) time O(1) space
            Node *tempHead = head, *tempTail = tail;
            while(tempHead != tempTail && tempHead->next != tempTail) {
                tempHead = tempHead->next;
                tempTail = tempTail->prev;
            }
            return tempTail->data;
        }

        int findMiddleWithoutUsingPrev() { //O(n) time O(1) space
            Node *slowHead = head, *fastHead = head;
            while(fastHead && fastHead->next) {
                slowHead = slowHead->next;
                fastHead = fastHead->next->next;
            }
            return slowHead->data;
        }
};


int main(void) {
    DoublyLinkedList myLinkedList;
    myLinkedList.insertFront(0);
    myLinkedList.insertEnd(1);
    myLinkedList.insertEnd(2);
    myLinkedList.insertEnd(3);
    myLinkedList.insertEnd(4);
    myLinkedList.insertEnd(5);
    myLinkedList.insertEnd(6);

    myLinkedList.print();

    cout<<endl<<myLinkedList.findMiddleWithoutUsingPrev()<<endl;
}