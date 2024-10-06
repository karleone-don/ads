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
        int triangleSum(TreeNode* node, int count){
            if(node->left != nullptr){
                count = triangleSum(node->left, count);
            }
            if(node->right != nullptr){
                count = triangleSum(node->right, count);
            }
            if(node->right != nullptr and node->left != nullptr){
                count++;
            }
            return count;
        }
    public:
        TreeNode* root;
        BinarySearchTree(){
            root = nullptr;
        }
        void insert(int value){
            root = insertRec(root, value);
        }
        void triangles(){
            cout << triangleSum(root, 0);
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
    bst.triangles();
}