#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* base;

int n;
vector<int> pre,in,post;

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];

    int k = inL;
    for(; k<=inR; k++){
        if(pre[preL] == in[k]) break;
    }
    int numLeft = k - inL;

    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);

    return root;
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    if(root != base) printf(" ");
}

int main(){
    scanf("%d",&n);

    string instructor;
    int val;
    stack<int> sstack;
    for(int i=0;i<2 * n;i++){
        cin>>instructor;
        if(instructor == "Push"){
            cin>>val;
            pre.push_back(val);
            sstack.push(val);
        }else{
            in.push_back(sstack.top());
            sstack.pop();
        }
    }

    base = create(0, n-1, 0, n-1);

    postOrder(base);

    return 0;
}

/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

3 4 2 6 5 1
*/