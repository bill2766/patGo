#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 110;

int N;

struct node{
    int left;
    int right;
    node():left(-1),right(-1){}
}nodes[MAX_N];

int base = 0;
bool isNotBase[MAX_N];

int maxPos = -1;
int last;

void dfs(int root, int index){
    if(index > maxPos){
        maxPos = index;
        last = root;
    }
    if(nodes[root].left != -1) dfs(nodes[root].left, index*2);
    if(nodes[root].right != -1) dfs(nodes[root].right,index*2+1);
}

int main(){
    // scanf("%d\n",&N);
    cin>>N;
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

    dfs(base, 1);

    if(maxPos == N){
        printf("YES %d",last);
    }else{
        printf("NO %d",base);
    }

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