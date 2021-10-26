#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node{
    double amount;
    vector<int> chains;
};

vector<Node> nodes;
int N;
double P, r;

double res = 0.0;

void dfs(int root,int deep){
    if(nodes[root].chains.size() == 0){
        res += nodes[root].amount * pow(1 + r,deep);
        return;
    }
    for(int i=0;i<nodes[root].chains.size();i++){
        dfs(nodes[root].chains[i],deep+1);
    }
}

int main(){
    scanf("%d %lf %lf",&N,&P,&r);
    nodes.resize(N);
    r = r / 100.0;

    int childNum;
    double temp1;
    int temp2;
    for(int i=0;i<N;i++){
        scanf("%d",&childNum);
        if(childNum == 0){
            scanf("%lf",&temp1);
            nodes[i].amount = temp1;
        }else{
            for(int j=0;j<childNum;j++){
                scanf("%d",&temp2);
                nodes[i].chains.push_back(temp2);
            }
        }
    }

    dfs(0,0);

    printf("%.1lf",res * P);

    return 0;
}

/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

42.4
*/