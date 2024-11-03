#include <iostream>
using namespace std;

class BinarySearchTree {
    private:
        struct Node {

            int data {};
            Node* left {};
            Node* right {};
            Node(int data): data(data) {}

        };
        Node* root = {};

        void clear(Node *root) { // O(n) time O(1) space
            if(!root)
                return;

            clear(root->left);
            clear(root->right);
            delete root;
        }
    public:
        BinarySearchTree(int rootValue): root(new Node(rootValue)) {};
        ~BinarySearchTree() {
            clear(root);
        }
    };
