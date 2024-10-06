#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    int deep;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        deep = 1;
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

            if (value < node->data){
                node->left = insertRec(node->left, value);
            }
            else if(value > node->data){
                node->right = insertRec(node->right, value);
            }

            int leftDeep = (node->left != nullptr) ? node->left->deep : 1;
            int rightDeep = (node->right != nullptr) ? node->right->deep : 1;

            node->deep = max(leftDeep, rightDeep)+1;

            return node;
        }

        int nodeDistance(TreeNode* node){
            int g = node->deep, d = 1;
            if(node->left != nullptr and node->right != nullptr){
                d = node->left->deep + node->right->deep + 1;
                if(g < d){
                    g = d;
                }
            }
            if(node->left != nullptr){
                d = nodeDistance(node->left);
                if(g < d){
                    g = d;
                }
            }
            if(node->right != nullptr){
                d = nodeDistance(node->right);
                if(g < d){
                    g = d;
                }
            }
            return g;
        }

    public:
        TreeNode* root;    
        BinarySearchTree(){
            root = nullptr;
        }

        void insert(int value){
            root = insertRec(root, value);
        }
        
        void distance(){
            cout << nodeDistance(root);
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
    bst.distance();
}