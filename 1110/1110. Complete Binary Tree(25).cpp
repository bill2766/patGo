#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 110;

int N;

struct node{
    int pos;
    int left;
    int right;
    node():pos(-1),left(-1),right(-1){}
};
vector<node> nodes;

int base = 0;
bool isNotBase[MAX_N];

bool hasNode[MAX_N];

void layerOrder(int root){
    bool iscbt = true;
    int end;
    fill(hasNode,hasNode+N,false);

    queue<int> q;
    q.push(root);
    nodes[root].pos = 1;

    int node, lchild, rchild;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(nodes[node].pos <= N){
            hasNode[nodes[node].pos] = true;
        }
        
        lchild = nodes[node].left;
        rchild = nodes[node].right;
        if(lchild != -1){
            nodes[lchild].pos = nodes[node].pos * 2;
            q.push(lchild);
        }
        if(rchild != -1){
            nodes[rchild].pos = nodes[node].pos * 2 + 1;
            q.push(rchild);
        }
        if(q.empty()) end = node;
    }

    for(int i=1;i <= N;i++){
        if(hasNode[i] == false){
            iscbt = false;
            break;
        }
    }
    if(iscbt){
        printf("YES %d",end);
    }else{
        printf("NO %d",base);
    }
}

int main(){
    cin>>N;
    nodes.resize(N);
    fill(isNotBase,isNotBase+N,false);

    string left, right;
    for(int i=0;i<N;i++){
        cin>>left>>right;
        if(left != "-"){
            nodes[i].left = stoi(left);
            isNotBase[stoi(left)] = true;
        }
        if(right != "-"){
            nodes[i].right = stoi(right);
            isNotBase[stoi(right)] = true;
        }
    }
    while(isNotBase[base]) base++;

    layerOrder(base);

    return 0;
}

/*
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -

YES 8


8
- -
4 5
0 6
- -
2 3
- 7
- -
- -

NO 1
*/