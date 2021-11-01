#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1010;

int n;
int in[MAX_N], level[MAX_N];
int t = 0;

void inOrder(int ind){
    if(ind >= n) return;
    inOrder(ind*2+1);
    //因为是中序遍历，所以遍历结果与中序数组in中的值从0开始依次递增的结果相同，即in[t++]（t从0开始），
    //将in[t++]赋值给level[root]数组
    level[ind] = in[t++];
    inOrder(ind*2+2);
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    sort(in,in+n);

    inOrder(0);

    printf("%d",level[0]);
    for(int i=1;i<n;i++){
        printf(" %d",level[i]);
    }
    
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 0

6 3 8 1 5 7 9 0 2 4
*/