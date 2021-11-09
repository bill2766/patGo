#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 1010;

int N;
int father[MAX_N];

int findFather(int x){
    int thex = x;
    while(x != father[x]) x = father[x];

    while(thex != father[thex]){
        int temp = thex;
        thex = father[thex];
        father[temp] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = father[B];
    }
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        father[i] = i;
    }



    return 0;
}