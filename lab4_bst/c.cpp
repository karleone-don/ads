#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
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

    TreeNode* searchRec(TreeNode* node, int value){
        if(node == nullptr){
            return nullptr;
        }
        if(node->data == value){
            return node;
        }
        if(value < node->data){
            return searchRec(node->left, value);
        }
        else{
            return searchRec(node->right, value);
        }
    }

    void inOrderRec(TreeNode* node){
        if(node != nullptr){
            cout << node->data << " ";
            inOrderRec(node->left);
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

    TreeNode* search(int value){
        return searchRec(root, value);
    }

    void inOrder(TreeNode* node){
        inOrderRec(node);
        cout << endl;
    }
};

int main(){
    int a, b;
    cin >> a;
    BinarySearchTree bst;
    for(int i = 0; i < a; i++){
        cin >> b;
        bst.insert(b);
    }
    cin >> b;
    bst.inOrder(bst.search(b));
}