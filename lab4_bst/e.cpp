#include <iostream>
#include <queue>

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

class BinaryTree{
private:
    TreeNode* insertRec(TreeNode* node, int value, bool side){  
        if(side == 0){
            node->left = new TreeNode(value);
        }
        else{
            node->right = new TreeNode(value);
        }
        return root;
    }

    TreeNode* searchDFS(TreeNode* node, int value) {
        if (node == nullptr) return nullptr;
        if (node->data == value) return node;

        TreeNode* leftResult = searchDFS(node->left, value);
        if (leftResult != nullptr) return leftResult;

        return searchDFS(node->right, value);
    }

    int getMaxWidth(TreeNode* node) {
        if (node == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(node);

        int maxWidth = 0;

        while (!q.empty()) {
            int levelWidth = q.size(); // Количество узлов на текущем уровне
            maxWidth = max(maxWidth, levelWidth); // Обновляем максимальную ширину

            for (int i = 0; i < levelWidth; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
        }

        return maxWidth;
    }

public:
    TreeNode* root = new TreeNode(1);

    void insert(int parent, int value, bool side){
        TreeNode* node = searchDFS(root, parent);
        root = insertRec(node, value, side);
    }

    void bfs(){
        cout << getMaxWidth(root);
    }

};

int main(){
    int a, b, c;
    bool d;
    cin >> a;
    BinaryTree bt;
    for(int i = 0; i < a-1; i++){
        cin >> b >> c >> d;
        bt.insert(b, c, d);
    }
    bt.bfs();
}