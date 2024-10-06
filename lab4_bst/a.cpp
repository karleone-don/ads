#include <iostream>
#include <string>

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

public:
    TreeNode* root;
    BinarySearchTree(){
        root = nullptr;
    }
    void insert(int value){
        root = insertRec(root, value);
    }
};

bool binSearch(TreeNode* root, string s){
    TreeNode* node = root;
    for(char i : s){
        if(i == 'L'){
            node = node->left;
        }
        else{
            node = node->right;
        }
        if(node == nullptr){
            return false;
        }
    }
    return true;
}

int main(){
    int a, b, c;
    cin >> a >> b;
    BinarySearchTree bst;
    string S;
    for(int i = 0; i < a; i++){
        cin >> c;
        bst.insert(c);
    }
    for(int j = 0; j < b; j++){
        cin >> S;
        if(binSearch(bst.root, S)){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
}