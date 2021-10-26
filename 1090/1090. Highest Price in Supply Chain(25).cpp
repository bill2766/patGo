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

int head;
double maxprice = 0;
int maxnum = 0;

void dfs(int root, int depth){
    double price = P * pow(1+r,depth);
    if(price > maxprice){
        maxnum = 1;
        maxprice = price;
    }else if(price == maxprice){
        maxnum++;
    }
    for(int i=0;i<nodes[root].childs.size();i++){
        dfs(nodes[root].childs[i], depth+1);
    }
}

int main(){
    scanf("%d %lf %lf",&N, &P, &r);
    nodes.resize(N);
    r = r/100.0;
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        if(temp != -1){
            nodes[temp].childs.push_back(i);
        }else{
            head = i;
        }
    }
    dfs(head,0);

    printf("%.2lf %d", maxprice, maxnum); 
    return 0;
}

/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6

1.85 2
*/