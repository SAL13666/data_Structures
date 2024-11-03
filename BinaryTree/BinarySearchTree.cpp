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

        bool _search(Node *current, int value) { // O(n) time O(h) space

            if(!current)
                return false;

            if(current->data == value)
                return true;
            
            if(value > current->data)
                return _search(current->right, value);
            else
                return _search(current->left, value);
        }
    
        void _print(Node *node) const { // O(n) time O(h) space
            if(!node)
                return;

            _print(node->left);
            cout<<node->data<<" ";
            _print(node->right);
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

        bool search(int value) {
            return _search(root, value);
        }

        void print() {
            _print(root);
        }
    };


int main() {
    BinarySearchTree myBST(50);
    myBST.insert(50);
    myBST.insert(20);
    myBST.insert(15);
    myBST.insert(35);
    myBST.insert(70);
    myBST.insert(60);
    myBST.insert(73);
    cout<< myBST.search(73)<<endl;
    myBST.print();
}