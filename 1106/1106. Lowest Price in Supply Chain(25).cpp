#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 100010;
int N;
double P, r;

struct Node{
    vector<int> childs;
};
vector<Node> nodes;

int mindepth = MAX_N;
int resnum = 0;

void dfs(int root, int depth){
    if(depth > mindepth) return;
    if(nodes[root].childs.empty()){
        if(depth < mindepth){
            mindepth = depth;
            resnum = 1;
        }else if(depth == mindepth){
            resnum++;
        }
    }

    for(int i=0;i<nodes[root].childs.size();i++){
        dfs(nodes[root].childs[i],depth+1);
    }
}

int main(){
    scanf("%d %lf %lf",&N, &P, &r);
    nodes.resize(N);

    int ki;
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&ki);
        if(ki != 0){
            for(int j=0;j<ki;j++){
                scanf("%d",&temp);
                nodes[i].childs.push_back(temp);
            }
        }else{

        }
    }
    dfs(0,0);  

    printf("%.4lf %d",P * pow(1+r/100.0,mindepth),resnum);

    return 0;
}

/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0

1.8362 2
*/