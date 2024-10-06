#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class  BinarySearchTree
{
private:
    TreeNode* insertRec(TreeNode* node, int value){
        if(node == nullptr){
            return new TreeNode(value);
        }
        if(value < node->data){
            node->left = insertRec(node->left, value);
        }
        else if(value > node->data){
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    bool searchRec(TreeNode* node, int value){
        if(node == nullptr){
            return false;
        }
        if(node->data == value){
            return true;
        }
        if (value < node->data){
            return searchRec(node->left, value);
        }
        else{
            return searchRec(node->right, value);
        }
    }

    void inOrderRec(TreeNode* node){
        if(node != nullptr){
            inOrderRec(node->left);
            cout << node->data << " ";
            inOrderRec(node->right);
        }
    }
public:
    TreeNode* root;
    BinarySearchTree(){
        root = nullptr;
    };

    void insert(int value){
        root = insertRec(root, value);
    }

    bool search(int value){
        return searchRec(root, value);
    } 

    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.inOrder();

    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (bst.search(100) ? "Found" : "Not found") << endl;
    cout << bst.root->right->right->data;
}