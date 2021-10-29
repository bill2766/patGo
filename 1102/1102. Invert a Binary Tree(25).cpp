#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 11;

int n;
struct node{
    int lchild;
    int rchild;
    node():lchild(-1),rchild(-1){}
}nodes[MAX_N];

int isroot[MAX_N];
int root;

void layerOrder(){
    int count = 0;
    queue<int> q;
    q.push(root);
    int ind;
    while(!q.empty()){
        ind = q.front();
        q.pop();
        count++;
        printf("%d",ind);
        if(count != n) printf(" ");
        if(nodes[ind].rchild != -1) q.push(nodes[ind].rchild);
        if(nodes[ind].lchild != -1) q.push(nodes[ind].lchild);
    }
}

int sidest;

void inOrder(int root){
    if(root == -1) return;
    inOrder(nodes[root].rchild);
    printf("%d",root);
    if(root != sidest) printf(" ");
    inOrder(nodes[root].lchild);
}

int main(){
    scanf("%d\n",&n);

    fill(isroot,isroot+n,1);
    char lind;
    char rind;
    for(int i=0;i<n;i++){
        cin>>lind>>rind;
        if(lind != '-'){
            int lindInt = lind - '0';
            nodes[i].lchild = lindInt;
            isroot[lindInt] = 0;
        }
        if(rind != '-'){
            int rindInt = rind - '0';
            nodes[i].rchild = rindInt;
            isroot[rindInt] = 0;
        }
    }
    root = 0;
    while(isroot[root] == 0) root++;

    sidest = root;
    while(nodes[sidest].lchild != -1) sidest = nodes[sidest].lchild;

    layerOrder();
    printf("\n");
    inOrder(root);

    return 0;
}

/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/