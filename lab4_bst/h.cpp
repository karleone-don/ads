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
        TreeNode* insertRec(TreeNode* node, int& value){
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

        void SumRec(TreeNode* node, int& sum){
            if(node == nullptr){
                return;
            }

            SumRec(node->right, sum);

            sum += node->data;
            node->data = sum;

            SumRec(node->left, sum);

        }

        void inOrderRec(TreeNode* node){
            if(node != nullptr){
                inOrderRec(node->right);
                cout << node->data << " ";
                inOrderRec(node->left);
            }
        }

    public:
        TreeNode* root;
        BinarySearchTree(){
            root = nullptr;
        }

        void insert(int value){
            root = insertRec(root, value);
        }

        void sum(){
            int sum = 0;
            SumRec(root, sum);
            inOrderRec(root);
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
    bst.sum();
}