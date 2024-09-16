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

        void print(Node *node) { // O(n) time O(1) space
            if(!node)
                return;

            cout<<node->data<<" ";
            print(node->left);
            print(node->right);
        }
};




int main() {

}