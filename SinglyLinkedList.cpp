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
        Node *firstNode = head;
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
            for(tempHead = head; tempHead; tempHead = tempHead->next) {
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

        void deleteEvenPositions() { //O(n) time O(1) space
            if (!head || head == tail) {
                return;
            }
            Node* prev = head;
            Node* tempHead = head->next;
            Node* next = nullptr;

            while (tempHead) {
                next = tempHead->next;
                delete tempHead;
                prev->next = next;
                if (!next) {
                    tail = prev;
                    return;
                }
                tempHead = next->next;
                prev = next;
            }
        }

        void insert(int value) { //O(n) time O(1) space
            Node* tempHead = head;
            Node* prev {};
            Node *newNode = new Node(value);

            if(!head) {
                insertFront(value);
                return;
            }

            while(tempHead != nullptr) {
                if(tempHead->data > value) {
                    newNode->next = tempHead;
                    if(!prev) {
                        head = newNode;
                        return;
                    }

                    prev->next = newNode;
                    return;
                }

                prev = tempHead;
                tempHead = tempHead->next;
                if(tempHead == nullptr) {
                    newNode->next = tempHead;
                    prev->next = newNode;
                    tail = newNode;
                }
            }
        }

        void swapHeadAndTail() { //O(n) time O(1) space
            if (!head || head == tail) {
                return;
            }

            Node* tempNode = head;
            Node* prev = nullptr;
            Node* current = head;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            prev->next = head;
            current->next = head->next;
            head->next = nullptr;
            head = current;
            tail = tempNode;
        }

        void leftRotate() { //O(n) time O(1) space
            if (!head || head == tail) {
                return;
            }

            Node* tempNode = head;
            Node* prev = nullptr;
            while (tempNode->next != nullptr) {
                prev = tempNode;
                tempNode = tempNode->next;
            }

            tempNode->next = head;
            head = tempNode;
            prev->next = nullptr;
            tail = prev;
        }

        void removeDuplicates() { //O(n^2) time O(1) space
            if (!head || head == tail) {
                return;
            }

            for(Node* tempNode = head; tempNode != nullptr; tempNode = tempNode->next) {
                for(Node* tempNode2 = tempNode->next, *prev = tempNode ; tempNode2 != nullptr; tempNode2 = tempNode2->next) {
                    if(tempNode->data == tempNode2->data) {
                        prev->next = tempNode2->next;

                        if (tempNode2 == tail) {
                            tail = prev;
                        }

                        delete tempNode2;
                        tempNode2 = prev;
                    } else {
                        prev = tempNode2;
                    }
                }
            }
        }

        void removeLastOccurance(int value) {  //O(n) time O(1) space
            if (!head) {
                return;
            }

            Node *deleteNext = nullptr;
            bool isFound = false;

            for(Node *tempHead = head, *prev = nullptr; tempHead; prev = tempHead , tempHead = tempHead->next) {
                if(tempHead->data == value) {
                    deleteNext = prev;
                    isFound = true;
                }
            }

            if(isFound) {
                if(deleteNext) {
                    Node *next = deleteNext->next->next;
                    if(tail == deleteNext->next) {
                        tail = deleteNext;
                    }
                    delete deleteNext->next;
                    deleteNext->next = next;
                } else {
                    Node *newHead = head->next;
                    delete head;
                    head = newHead;
                }
            }
        }

        void moveToBack(int key) { //O(n) time O(1) space
            int length = 0;
            for(Node *tempHead = head; tempHead; tempHead = tempHead->next) {
                length++;
            }

            for(Node *tempHead = head, *prev = nullptr; length; length--) {
                if(tempHead->data == key) {
                    if(prev) {
                        prev->next = tempHead->next;
                        tail->next = tempHead;
                        tempHead->next = nullptr;
                        tail = tempHead;
                        tempHead = prev;
                    } else {
                        head = head->next;
                        tail->next = tempHead;
                        tail = tempHead;
                        tail->next = nullptr;
                        tempHead = head;
                        prev = nullptr;
                        continue;
                    }
                }
                prev = tempHead , tempHead = tempHead->next;
            }

        }

        void arrangeEvenAndOddPositions() { // 1 2 3
            if(!head || head == tail) {
                return;
            }

            int index = 1;
            Node *oldTail = tail;
            for(Node *tempHead = head, *prev = nullptr; tempHead; prev = tempHead, tempHead = tempHead->next, index++) {
                if(*&tempHead == *&oldTail) { // NOTE(1) there are a difference between *& and & only be careful while using pointers
                    return;
                }
                if(index % 2 == 0) {
                    prev->next = tempHead->next;
                    tempHead->next = nullptr;
                    tail->next = tempHead;
                    tail = tempHead;
                    tempHead = prev;
                }
            }
        }

};

int main(void) {
    SinglyLinkedList myLinkedList;
    // myLinkedList.insertEnd(10);
    // myLinkedList.insertEnd(20);
    // myLinkedList.insertEnd(30);
    // myLinkedList.insertEnd(40);
    // myLinkedList.insertEnd(50);
    // myLinkedList.deleteUsingKey(10);
    // myLinkedList.deleteUsingKey(50);
    // myLinkedList.swapPairs();
    myLinkedList.insertEnd(11);
    myLinkedList.insertEnd(33);
    myLinkedList.insertEnd(55);
    myLinkedList.insertEnd(4);
    myLinkedList.insertEnd(50);
    myLinkedList.insertEnd(17);
    myLinkedList.insertEnd(8);
    // myLinkedList.insert(0);
    // myLinkedList.insert(-1);
    // myLinkedList.insert(100);
    // myLinkedList.insert(530);
    // myLinkedList.insert(10);
    myLinkedList.print();
    cout<<endl<< "----------------------------------------------------"<<endl;
    // myLinkedList.leftRotate();
    // myLinkedList.removeLastOccurance(1);
    // myLinkedList.removeLastOccurance(7);
    // myLinkedList.removeLastOccurance(5);
    myLinkedList.arrangeEvenAndOddPositions();
    myLinkedList.print();
    return 0;
}
