#include <cstdio>
#include <iostream>
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
    if(root == NULL){
        return 0;
    }else{
        return root->height;
    }
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
            if(getBalanceFactor(root->lchild) == 1){ //LL
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){ //LR
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, data);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){ //RR
                L(root);
            }else if(getBalanceFactor(root->rchild) == 1){ //RL
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

int main(){
    int n;
    cin>>n;
    int datas[n];
    for(int i=0;i<n;i++){
        cin>>datas[i];
    }
    node* base = create(datas, n);

    cout<<base->data;

    return 0;
}

/*
5
88 70 61 96 120

70


7
88 70 61 96 120 90 65

88
*/