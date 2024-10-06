#include <iostream>
#include <vector>

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
        else{
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    int findDepth(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left_depth, right_depth;
        if(node->left != nullptr){
            left_depth = findDepth(node->left);
        }
        else left_depth = 0;
        if(node->right != nullptr){
            right_depth = findDepth(node->right);
        }
        else right_depth = 0;

        int max = left_depth > right_depth ? left_depth : right_depth;
        return max+1;
    }

    vector<int> findValue(TreeNode* node, int i, vector<int> vec){
        if(node == nullptr){
            return vec;
        }

        vec[i] += node->data;
        vec = findValue(node->left, i+1, vec);
        vec = findValue(node->right, i+1, vec);

        return vec;
    }

    public:
        TreeNode* root;
        vector<int> m;
        BinarySearchTree(){
            root = nullptr;
        }

        void insert(int value){
            root =  insertRec(root, value);
        }

        int depth(){
            return findDepth(root);
        }
        void make_arr(int size){
            for(int i = 0; i < size; i++){
                m.push_back(0);
            }
            m = findValue(root, 0, m);
            for(int i = 0; i < size; i++){
                cout << m[i] << ' ';
            }
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
    b = bst.depth();
    cout << b << endl;
    bst.make_arr(b);
}