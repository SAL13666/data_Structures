#include <iostream>
#include <cmath>
using namespace std;
struct Node {
    int data {};
    Node *next {};
    Node(int data) : data(data) {}; 
};

class SinglyLinkedList {
    private:
        Node *head {};
        Node *tail {};
    public:
        SinglyLinkedList() : head(nullptr), tail(nullptr) {};
        ~SinglyLinkedList() { //O(n) time O(1) space
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

        void insertEnd (int value) { //O(1) time O(1) space
            Node *newNode = new Node(value);
            newNode->next = nullptr;
            if(!head) {
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        Node* getNth(int nth) {//O(n) time O(1) space
            Node *tempHead = head;
            for(int i = 1; i < nth; i++, tempHead = tempHead->next) {
                if(tempHead->next == nullptr) {
                    return nullptr;
                }
            }
            return tempHead;
        }

        Node* getNthFromBack(int nth) {//O(n) time O(1) space
            Node *tempHead = head;
            int nodesCount = 0;
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                nodesCount++;
            }
            tempHead = head;

            if(nodesCount - nth - 1 < 0) {
                return nullptr;
            }

            for(int i = 0; i < nodesCount - nth - 1; i++) {
                if(tempHead->next == nullptr) {
                    return nullptr;
                }
                tempHead = tempHead->next;
            }
            return tempHead;
        }

        int findUsingValue(int value) { //O(n) time O(1) space
            int index = 0;
            Node *prev = nullptr;
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                if(tempHead->data == value) {
                    if(!prev) {
                        return index;
                    }
                    swap(prev->data, tempHead->data);
                    return index - 1;
                }
                index++;
                prev = tempHead;
            }
            return -1;
        }

        void insertFront (int value) { //O(1) time O(1) space
            Node *newNode = new Node(value);
            if(!head) {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        void deleteFront () { //O(1) time O(1) space
            Node *next = head->next;
            delete head;
            head = next;
        }

        int isSame (Node *headTwo) { //O(n) time O(1) space
            Node *tempHead = head;
            while(tempHead) {
                if(tempHead->next == nullptr && headTwo->next != nullptr) {
                    return -1;
                }

                if(headTwo->data != tempHead->data) {
                    return -1;
                }

                tempHead = tempHead->next;
                headTwo = headTwo->next;
            }

            return 1;
        }

        void deleteBack () { //O(n) time O(1) space
        if(!head) {
            return;
        }

        if (!head->next) {
            delete head;
            head = tail = nullptr;
            return;
        }

            Node *prev {};
            for(Node *tempHead = head; tempHead != nullptr; tempHead = tempHead->next) {
                if(tempHead->next == nullptr) {
                    break;
                }
                prev = tempHead;
            }

            delete tail;
            prev->next = nullptr;
            tail = prev;
        }

        void deleteUsingNth(int nth) { //O(n) time O(1) space
            if(nth <= 0 || head == nullptr) {
                return;
            }
            Node *prev {};
            Node *tempHead = head;
            for(int i = 1; i < nth; i++) {
                prev = tempHead;
                tempHead = tempHead->next;
                if(tempHead == nullptr) {
                    return;
                }
            }

            if(!prev) {
                prev = head;
                head = head->next;
                if (!head) {
                    tail = nullptr;
                }
                delete prev;
                return;
            }

            if(tempHead->next == nullptr) {
                prev->next = nullptr;
                delete tail;
                tail = prev;
                return;
            }

            prev->next = tempHead->next;
            delete tempHead;
        }

        void deleteUsingKey(int key) { //O(n) time O(1) space
            Node *tempHead = head;
            Node *prev {};
                if(!head) {
                    return;
                }

            while(tempHead != nullptr) {

                if(tempHead->data == key) {

                    if(head == tail) {
                        delete head;
                        head = tail = nullptr;
                        return;
                    }

                    if(!prev) {
                        prev = tempHead->next;
                        delete tempHead;
                        head = prev;
                        return;
                    };

                    prev->next = tempHead->next;
                    delete tempHead;
                    return;
                }
                prev = tempHead;
                tempHead = tempHead->next;
            }
        }

        void swapPairs() { //O(n) time O(1) space
            Node *tempHead = head;
            while(tempHead) {
                if(!tempHead->next) {
                    return;
                }
                swap(tempHead->data, tempHead->next->data);
                tempHead = tempHead->next->next;
            }
        }

        void reverseListNodes() { //O(n) time O(1) space
            Node *tempHead = head;
            Node *newHead {};
            Node *next = tempHead->next;

            while(tempHead) {
                if(!newHead) {
                    newHead = tempHead;
                    newHead->next = nullptr;
                    tail = newHead;
                    tempHead = next;
                    continue;
                }
                next = tempHead->next;
                tempHead->next = newHead;
                newHead = tempHead;
                tempHead = next;
            }
            head = newHead;
        }
};

int main(void) {
    SinglyLinkedList myLinkedList;
    myLinkedList.insertEnd(10);
    myLinkedList.insertEnd(20);
    myLinkedList.insertEnd(30);
    myLinkedList.insertEnd(40);
    myLinkedList.insertEnd(50);
    myLinkedList.print();
    cout<<endl<< "----------------------------------------------------"<<endl;
    // myLinkedList.deleteUsingKey(10);
    // myLinkedList.deleteUsingKey(50);
    // myLinkedList.swapPairs();
    myLinkedList.reverseListNodes();
    myLinkedList.print();
    return 0;
}
