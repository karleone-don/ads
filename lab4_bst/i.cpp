#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
    int data;
    int multiplicity;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        multiplicity = 1;
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
            else{
                node->multiplicity++;
            }

            return node;
        }

        TreeNode* SearchRec(TreeNode* node, int value){
            if(node == nullptr){
                return nullptr;
            }
            if(node->data == value){
                return node;
            }
            if(node->data < value){
                return SearchRec(node->right, value);
            }
            else{
                return SearchRec(node->left, value);
            }
        }

        int CountRec(TreeNode* node, int value){
            node = SearchRec(node, value);
            if(node == nullptr){
                return 0;
            }
            return node->multiplicity;
        }

        TreeNode* DeleteRec(TreeNode* root, int value){
            TreeNode* node = SearchRec(root, value);
            node->multiplicity--;
            return root;
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
            cout << CountRec(root, value) << endl;
        }

        void delet(int value){
            root = DeleteRec(root, value);
        }
};

int main(){
    int a, b;
    string s;
    cin >> a;
    BinarySearchTree bst;
    for(int i = 0; i < a; i++){
        cin >> s >> b;
        if(s == "insert"){
            bst.insert(b);
        }
        else if(s == "cnt"){
            bst.search(b);
        }
        else if(s == "delete"){
            bst.delet(b);
        }
    }
}