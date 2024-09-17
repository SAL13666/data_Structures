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

        void clear(Node *root) { // O(n) time O(1) space
            if(!root)
                return;

            clear(root->left);
            clear(root->right);
            delete root;
        }

        void print(Node *node) const { // O(n) time O(1) space
            if(!node)
                return;

            cout<<node->data<<" ";
            print(node->left);
            print(node->right);
        }

    public:
        BinaryTree(int rootValue): root(new Node(rootValue)) {};

        ~BinaryTree() {
            clear(root);
        }

        void clear() { // O(n) time O(1) space
            clear(root);
            root = nullptr;
        }

        void print() const { // O(n) time O(1) space
            print(root);
            cout<< endl;
        }
};




int main() {

}