#include <iostream>
using namespace std;

struct Node {
    int data = NULL;
    int index = NULL;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data, int index) : data(data), index(index) {}; 
};

class ArrayLinkedList {
    private:
        Node *head;
        Node *tail;
        int length = 0;
    public:
        ArrayLinkedList(int length) : head(nullptr), tail(nullptr), length(length) {};

        ~ArrayLinkedList() { //O(n) time O(1) space
            while(head != nullptr) {
                Node *tempHead = head;
                head = head->next;
                delete tempHead;
            }
        };

        

};


int main(void) {

}