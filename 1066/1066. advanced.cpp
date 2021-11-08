#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int value, height;
    Node* left;
    Node* right;
    Node(int value) : left(NULL), right(NULL), value(value), height(1){};
}*root;

int height(Node*x){
    if(x == NULL) return 0;
    return x->height;
}

void updateHeight(Node*x){
    x->height = max(height(x->left), height(x->right)) + 1;
}

int getBalanceFactor(Node* root){
    return height(root->left) - height(root->right);
}

// 左旋转（将不平衡的子树的右子结点作为新的根结点，原来的根节点作为新的左子树）
void L(Node*&root){
    Node* temp = root->right;// 暂存新的根结点为temp
    root->right = temp->left;// 将temp的左子树连接为root的右子树（因为temp为root的右子树，所以它的左子树比root大）
    temp->left = root;// 将root连接到temp的左子树上
    
    // 更新产生变化的两个子树的高度
    updateHeight(root);
    updateHeight(temp);
    
    root = temp;// 改变指针
}

// 右旋转（原理和代码与上面对称）
void R(Node*&root){
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node*&root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(value < root->value){
        insert(root->left, value);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1){// 左子树的高度差是1，说明插入结点为左子树的左子结点，右旋。
                R(root);
            }else{// 否则插入结点为左子树的右子结点，先左旋再右旋。
                L(root->left);
                R(root);
            }
        }
    }else{// 和上面对称，但是这个地方是负数
        insert(root->right, value);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->right) == -1){
                L(root);
            }else{
                R(root->right);
                L(root);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    root = NULL;
    for(int i = 0, v; i < N; i++){
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->value);
    return 0;
}

