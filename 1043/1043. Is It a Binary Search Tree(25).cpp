#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1010;

int N;
struct node{
    int data;
    node* lchild;
    node* rchild;
    node():lchild(NULL),rchild(NULL){}
};
node* base;
int pre[MAX_N],in[MAX_N],pody[MAX_N];

bool flag;

node* create(int preL, int preR, int inL, int inR, int op){
    if(flag == 0 || preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];

    int k;
    for(k=inL; k<=inR; k++){
        if(pre[preL] == in[k]){
            break;
        }
    }

    if(k > inR){
        flag = 0;
        return NULL;
    }

    if(op == 0){
        int numLeft = k - inL;
        root->lchild = create(preL+1, preL+numLeft, inL, k-1, op);
        root->rchild = create(preL+numLeft+1, preR, k+1, inR, op);
    }else{
        int numLeft = inR - k;
        //create的也是镜像树（左子树大，右子树小）
        root->lchild = create(preL+1, preL+numLeft, k+1, inR, op);
        root->rchild = create(preL+numLeft+1, preR, inL, k-1, op);
    }

    return root;
}

//左右根
void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d",root->data);
    if(root != base){
        printf(" ");
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&pre[i]);

    memcpy(in,pre,sizeof(pre));
    sort(in,in+N);

    //正常的前序
    flag = 1;
    base = create(0,N-1,0,N-1,0);
    if(flag == 1){
        printf("YES\n");
        postOrder(base);
        return 0;
    }
    //如果不是正常的前序，试试镜像的前序
    flag = 1;
    base = create(0,N-1,0,N-1,1);
    if(flag == 1){
        printf("YES\n");
        postOrder(base);
        return 0;
    }
    //都不行
    printf("NO");
    return 0;
}

/*
7
8 6 5 7 10 8 11

YES
5 7 6 8 11 10 8


7
8 10 11 8 6 7 5

YES
11 8 10 7 5 6 8


7
8 6 8 5 10 9 11

NO
*/