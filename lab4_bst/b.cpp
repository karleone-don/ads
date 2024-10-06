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
            return node;
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

    int inOrderRec(TreeNode* node){
        int c = 0;
        if(node != nullptr){
            c = inOrderRec(node->left)+1;
            c += inOrderRec(node-> right)+1;
        }
        return c;
    }

public:
    TreeNode* root;
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int value){
        root = insertRec(root, value);
    }

    void search(int value){
        TreeNode* node = searchRec(root, value);
        cout << inOrderRec(node) / 2;
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
    bst.search(b);
}