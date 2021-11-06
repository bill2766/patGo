#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#define MAX_N 10005
using namespace std;
struct Node{
    Node*left, *right;
    int value, height;
    Node(int value, int height) : value(value), left(NULL), right(NULL),height(height){};
}*root;
int pre[MAX_N], in[MAX_N];
int N, k = 0;
// 递归建树
Node* build(int inStart, int inEnd, int height){
    if(inStart >= inEnd) return NULL;
    int root = pre[k++], i = inStart;
    Node* x = new Node(root, height);
    while(i < inEnd && in[i] != root) i++;
    x->left = build(inStart, i, height + 1);
    x->right = build(i + 1, inEnd, height + 1);
    return x;
}
// 封装了一下，供最外层使用
Node* build(int inStart, int inEnd){
    return build(NULL, inStart, inEnd, 0);
}

int LCA = -1;
// flag1，flag2分别表示是否查找到了u, v
int search(Node*x, int u, int v, bool& flag1, bool& flag2){
    if(x == NULL) return 0;
    // cnt为找到的结点个数
    int cnt = search(x->left, u, v, flag1, flag2) + search(x->right, u, v, flag1, flag2);
    if(x->value == u){
        flag1 = true;
        cnt++;
    }
    if(x->value == v){
        flag2 = true;
        cnt++;
    }
    if(LCA == - 1 && cnt == 2){// 找到了两个结点，那么找到两个结点的最底层就是LCA，上层则不会再赋值（因为赋值一次后LCA就不是-1了）
        LCA = x->value;
    }
    return cnt;
}
int main() {
    int M;
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &pre[i]);
    }
    root = build( 0, N);
    
    
    bool flag1, flag2;
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        // 不要忘记初始化
        LCA = -1;
        flag1 = false;
        flag2 = false;
        
        // 递归搜索
        search(root, u, v, flag1, flag2);
        if(!flag1 && !flag2){
            printf("ERROR: %d and %d are not found.\n", u, v);
            continue;
        }else if(!flag1){
            printf("ERROR: %d is not found.\n", u);
            continue;
        }else if(!flag2){
            printf("ERROR: %d is not found.\n", v);
            continue;
        }
        
        if(LCA == u){
            printf("%d is an ancestor of %d.\n", u, v);
        }else if(LCA == v){
            printf("%d is an ancestor of %d.\n", v, u);
        }else{
            printf("LCA of %d and %d is %d.\n", u, v, LCA);
        }
    }
    
    return 0;
}

