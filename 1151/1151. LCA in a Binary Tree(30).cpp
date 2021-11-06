#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 100010;

int M, N;
struct node{
    int data;
    node* left;
    node* right;
};
node* base;
map<int, bool> hasNode;

int pre[MAX_N], in[MAX_N];

node* create(int preL, int preR, int inL, int inR){
    if(preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<inR;k++){
        if(pre[preL] == in[k]){
            break;
        }
    }
    int numLeft = k - inL;

    root->left = create(preL+1, preL+numLeft,inL, k-1);
    root->right = create(preL+numLeft+1,preR, k+1, inR);

    return root;
}

int ancestor;
int dfs(node* root, int u, int v){
    if(root == NULL) return 0;
    int cnt = 0;
    //左右子树有u或v的情况
    cnt = dfs(root->left,u,v) + dfs(root->right,u,v);
    //自己是u或v的情况
    if(root->data == u){
        cnt++;
    }
    if(root->data == v){
        cnt++;
    }
    //只要cnt == 2，说明左子树（包括自己） and 右子树（包括自己）有2个点分别是u和v
    //一个在左子树（包括自己），另一个在右子树（包括自己）。找到了就是答案
    if(ancestor == -1 && cnt == 2){
        ancestor = root->data;
    }
    return cnt;
}

int main(){
    scanf("%d %d",&M, &N);
    for(int i=0;i<N;i++){
        scanf("%d",&in[i]);
        hasNode[in[i]] = true;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&pre[i]);
    }

    base = create(0,N-1,0,N-1);

    int u, v;
    int res;
    for(int i=0;i<M;i++){
        scanf("%d %d",&u, &v);

        if(hasNode[u] == false && hasNode[v] == false){
            printf("ERROR: %d and %d are not found.\n",u,v);
        }else if(hasNode[u] == true && hasNode[v] == false){
            printf("ERROR: %d is not found.\n",v);
        }else if(hasNode[u] == false && hasNode[v] == true){
            printf("ERROR: %d is not found.\n",u);
        }else{
            ancestor = -1;
            dfs(base, u, v);
            
            if(ancestor == u){
                printf("%d is an ancestor of %d.\n",u,v);
            }else if(ancestor == v){
                printf("%d is an ancestor of %d.\n",v,u);
            }else{
                printf("LCA of %d and %d is %d.\n",u, v, ancestor);
            }

        }
    }

    return 0;
}

/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99

LCA of 2 and 6 is 3.
8 is an ancestor of 1.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/