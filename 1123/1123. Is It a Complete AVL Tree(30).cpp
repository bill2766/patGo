#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    int height;
    node* lchild;
    node* rchild;
};

node* newNode(int data){
    node* Node = new node;
    Node->data = data;
    Node->height = 1;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

int getHeight(node* root){
    if(root == NULL) return 0;
    return root->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int data){
    if(root == NULL){
        root = newNode(data);
        return;
    }

    if(data < root->data){
        insert(root->lchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){
                L(root);
            }else if(getBalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

node* create(int datas[], int n){
    node* root = NULL;
    for(int i=0; i<n; i++){
        insert(root, datas[i]);
    }
    return root;
}

void layerOrder(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* nowNode = q.front();
        q.pop();
        printf("%d",nowNode->data);
        if(nowNode->lchild != NULL) q.push(nowNode->lchild);
        if(nowNode->rchild != NULL) q.push(nowNode->rchild);
        if(!q.empty()){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

int maxIndex;
void dfs(node* root, int index){
    if(root == NULL){
        return;
    }
    if(index > maxIndex){
        maxIndex = index;
    }
    dfs(root->lchild, index*2);
    dfs(root->rchild, index*2+1);
}

int main(){
    int n;
    cin>>n;
    int datas[n];
    for(int i=0; i<n; i++){
        cin>>datas[i];
    }
    node* base = create(datas, n);

    layerOrder(base);

    maxIndex = -1;
    dfs(base, 1);

    if(maxIndex == n){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}

/*
5
88 70 61 63 65

70 63 88 61 65
YES


8
88 70 61 96 120 90 65 68

88 65 96 61 70 90 120 68
NO
*/