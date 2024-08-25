#include <iostream>
using namespace std;

class BinaryTree {
    private:
        struct Node {

            int data {};
            Node* left {};
            Node* right {};
            Node(int data): data(data) {}

        };

        Node* root {};

    public:
        BinaryTree(int rootValue): root(new Node(rootValue)) {};
};



int main() {

}