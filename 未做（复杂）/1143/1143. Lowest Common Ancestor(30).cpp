////////////////////////////////////
//29分
////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 10010;

struct node{
    int data;
    node* left;
    node* right;
    node():left(NULL),right(NULL){}
};
int M;
int N;
node* base;

int pre[MAX_N], in[MAX_N];

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR){ //先序序列长度小于等于0时，直接返回
        return NULL;
    }

    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numLeft = k - inL;

    root->left = create(preL+1, preL+numLeft, inL, k-1);
    root->right = create(preL+numLeft+1, preR, k+1, inR);

    return root;
}

vector<int> pathU;
vector<int> pathV;

vector<int> temp;
void dfs(node* root, int u, int v){
    temp.push_back(root->data);
    if(root->data == u){
        pathU = temp;
    }else if(root->data == v){
        pathV = temp;
    }

    if(root->left != NULL){
        dfs(root->left, u, v);
        temp.pop_back();
    }
    if(root->right != NULL){
        dfs(root->right, u, v);
        temp.pop_back();
    }
}

void findPath(int u, int v){
    dfs(base, u, v);
    temp.clear();

    if(pathU.empty() && pathV.empty()){
        printf("ERROR: %d and %d are not found.\n",u,v);
    }else if(pathU.empty() && !pathV.empty()){
        printf("ERROR: %d is not found.\n",u);
    }else if(!pathU.empty() && pathV.empty()){
        printf("ERROR: %d is not found.\n",v);
    }else{
        int ancestor;
        for(int i=0;i<pathU.size() && i<pathV.size();i++){
            if(pathU[i] == pathV[i]){
                ancestor = pathU[i];
            }
        }
        if(ancestor == u){
            printf("%d is an ancestor of %d.\n",u,v);
        }else if(ancestor == v){
            printf("%d is an ancestor of %d.\n",v,u);
        }else{
            printf("LCA of %d and %d is %d.\n",u, v, ancestor);
        }
    }

    pathU.clear();
    pathV.clear();
}

int main(){
    cin>>M>>N;

    for(int i=0;i<N;i++){
        cin>>pre[i];
        in[i] = pre[i];    
    }
    sort(in, in+N);

    base = create(0,N-1,0,N-1);

    int U,V;
    for(int i=0;i<M; i++){
        cin>>U>>V;
        findPath(U,V);
    }

    return 0;
}


/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99

LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/