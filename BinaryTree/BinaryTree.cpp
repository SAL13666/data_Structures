#include <iostream>
#include <vector>
#include <stack>
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

        Node* getNodeUsingPath(vector<char> path) { // O(n) time O(h) space
            Node* current = root;

            for(auto i: path) {
                if(i == 'L') {

                    if(current->left) {
                        current = current->left;
                    } else {
                        current->left = new Node(-1);
                        current = current->left;
                    }

                } else if(i == 'R') {

                    if(current->right) {
                        current = current->right;
                    } else {
                        current->right = new Node(-1);
                        current = current->right;
                    }

                } else {
                    cout <<"wrong direction format "<< i << endl;
                }
            }
            return current;
        }

        void clear(Node *root) { // O(n) time O(h) space
            if(!root)
                return;

            clear(root->left);
            clear(root->right);
            delete root;
        }

        void print(Node *node) const { // O(n) time O(h) space
            if(!node)
                return;

            cout<<node->data<<" ";
            print(node->left);
            print(node->right);
        }

        int findMax(Node *node) { // O(n) time O(h) space
            if(!node) {
                return INT_MIN;
            }
            
            int current = node->data;
            int firstMax = findMax(node->right);
            int secondMax = findMax(node->left);

            return max(current, max(firstMax,secondMax));
        }

        int findHeight(Node *node) {// O(n) time O(h) space
            if(!node) {
                return 0;
            }

            int rightHeight = findHeight(node->right);
            int leftHeight = findHeight(node->left);

             
            return max(leftHeight, rightHeight) + 1;
        }

       int getTotalNodesNumber(Node *node) { //O(n) time O(h) space
            if(!node) {
                return 0;
            }

            int rightNodesCount = getTotalNodesNumber(node->right);
            int leftNodesCount = getTotalNodesNumber(node->left);
            return rightNodesCount + leftNodesCount + 1;
        }

        int getTotalLeafNodes(Node *node) { //O(n) time O(h) space
            if(!node)
                return 0;

            if(!node->left && !node->right)
                return 1;

            int rightLeafNodesCount = getTotalLeafNodes(node->right);
            int leftLeafNodesCount = getTotalLeafNodes(node->left);

            return rightLeafNodesCount + leftLeafNodesCount; 
        }

        bool containsNode(Node *node, int value) { //O(n) time O(h) space
            if(!node)
                return false;

            if(value == node->data)
                return true;

            bool rightTree = containsNode(node->right, value);
            bool leftTree = containsNode(node->left, value);

            return rightTree || leftTree;
        }

        bool isPerfect(Node *node, int height = -1) { //O(n) time O(h) space
            if(height == -1)
                height = findHeight();

            if(!node->left && node->right || node->left && !node->right)
                return false;

            if(!node->left && !node->right) 
                return height == 0;

            return isPerfect(node->left, height - 1) && isPerfect(node->right, height - 1);

        }

        int diameter(Node* current, int& result) { //O(n) time O(h) space
            if(!current)
                return 0;

            int left = diameter(current->left, result);
            int right = diameter(current->right, result);

            result = max(result, left + right);

            return max(left, right) + 1;
        }
    public:
        BinaryTree(int rootValue): root(new Node(rootValue)) {};

        ~BinaryTree() {
            clear(root);
        }

        void clear() { 
            clear(root);
            root = nullptr;
        }

        void print() const {
            print(root);
            cout<< endl;
        }

        bool add(int value, vector<char> path) {

            //there is a bug where if the user adds another charcter besides R or L the program will crash

            Node* current = nullptr;

            if(path.empty()) {
                root->data = value;
                return false;
            }

            current = getNodeUsingPath(path);

            current->data = value;
            return true;
        }

        int findMax() {
            return findMax(root);
        }

        int findHeight() {
            return findHeight(root) -1;
        }

        int getTotalNodesNumber() {
            return getTotalNodesNumber(root);
        }

        int getTotalLeafNodes() {
            return getTotalLeafNodes(root);
        }

        bool containsNode(int value) {
            return containsNode(root, value);
        }

        bool isPerfect() {
            return isPerfect(root);
        }

        void DFSPrint() { //O(n) time O(n) space

            if(!root)
                return;

            stack<Node*>myTreeStack;
            myTreeStack.push(root);

            while(!myTreeStack.empty()) {
                Node* current = myTreeStack.top();
                myTreeStack.pop();

                cout<<current->data <<" ";
                if(current->right)
                    myTreeStack.push(current->right);
                if(current->left)
                    myTreeStack.push(current->left);
            }
        }

        int treeDiameter() {
            int result = 0;
            diameter(root, result);
            return result;
        }
};




int main() {
    BinaryTree myBinaryTree = BinaryTree(1);
    myBinaryTree.add(2, {'L'});
    myBinaryTree.add(3, {'R'});
    myBinaryTree.add(4, {'L', 'L'});
    myBinaryTree.add(5, {'L', 'R'});
    myBinaryTree.add(6, {'R', 'L'});
    myBinaryTree.add(7, {'R', 'R'});
    myBinaryTree.print();
}