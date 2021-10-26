#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 110;

int N, M;

struct Node{
    int depth;
    vector<int> childs;
};
vector<Node> nodes;

int depthNum[MAX_N];

void bfs(int root){
    queue<int> q;
    nodes[root].depth = 1;
    q.push(root);
    
    while(!q.empty()){
        int n = q.front();
        q.pop();
        depthNum[nodes[n].depth]++;
        
        for(int i=0;i<nodes[n].childs.size();i++){
            int childind = nodes[n].childs[i];
            nodes[childind].depth = nodes[n].depth + 1;
            q.push(nodes[n].childs[i]);
        }

    }
}

int main(){
    scanf("%d %d",&N, &M);
    nodes.resize(N+1);

    int parent, num, temp;
    for(int i=0;i<M;i++){
        scanf("%d %d",&parent,&num);
        for(int c=0;c<num;c++){
            scanf("%d",&temp);
            nodes[parent].childs.push_back(temp);
        }
    }

    fill(depthNum,depthNum+N+1,0);
    bfs(1);

    int maxnum = 0;
    int resdepth;
    for(int i=1;i<N+1;i++){
        if(maxnum < depthNum[i]){
            maxnum = depthNum[i];
            resdepth = i;
        }
    }

    printf("%d %d",maxnum,resdepth);

    return 0;
}

/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

9 4
*/