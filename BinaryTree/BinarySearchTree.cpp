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

        void clear(Node *root) { // O(n) time O(h) space
            if(!root)
                return;

            clear(root->left);
            clear(root->right);
            delete root;
        }

        void _insert(Node *current, int value) { // O(n) time O(h) space
            if(value > current->data) {

                if(current->right)
                    _insert(current->right, value);
                else
                    current->right = new Node(value);

            } else if(value < current->data) {

                if(current->left)
                    _insert(current->left, value);
                else
                    current->left = new Node(value);

            }
        }
    public:
        BinarySearchTree(int rootValue): root(new Node(rootValue)) {};
        ~BinarySearchTree() {
            clear(root);
        }

        void insert(int value) {
            if(!root) {
                root = new Node(value);
                return;
            }

            _insert(root, value);
        }
    };


int main() {
    BinarySearchTree myBST(50);
}