#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 110;

int N, M, S;

struct node{
    int weight;
    vector<int> childs;
}nodes[MAX_N];

bool cmp(int cind1, int cind2){
    return nodes[cind1].weight > nodes[cind2].weight;
}

vector<int> path;
int tempsum = 0;

void dfs(int root){
    path.push_back(nodes[root].weight);
    tempsum += nodes[root].weight;
    if(nodes[root].childs.empty()){
        if(tempsum == S){
            //print
            for(int i=0; i<path.size(); i++){
                printf("%d",path[i]);
                if(i != path.size()-1){
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
        }
    }else{
        for(int i=0;i<nodes[root].childs.size();i++){
            int childind = nodes[root].childs[i];
            dfs(childind);
            path.pop_back();
            tempsum -= nodes[childind].weight;
        }
    }
}

int main(){
    scanf("%d %d %d",&N, &M, &S);

    for(int i=0; i<N; i++) scanf("%d",&nodes[i].weight);

    int nind, csize, onechild;
    for(int i=0; i<M; i++){
        scanf("%d %d",&nind, &csize);
        for(int j=0; j<csize; j++){
            scanf("%d",&onechild);
            nodes[nind].childs.push_back(onechild);
        }
        sort(nodes[nind].childs.begin(),nodes[nind].childs.end(),cmp);
    }

    dfs(0);

    return 0;
}

/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19

10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/