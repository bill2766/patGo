#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_MSize = 10100;

int MSize, N;
int hhash[MAX_MSize];

bool isprime(int num){
    if(num == 1) return false;
    for(int i=2;i*i <= num;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void findPos(int val){
    for(int step=0;step < MSize;step++){
        int pos = (val+step*step) % MSize;
        if(hhash[pos] == 0){
            hhash[pos] = 1;
            printf("%d",pos);
            return;
        }
    }
    printf("-");
}


int main(){
    scanf("%d %d",&MSize,&N);
    while(!isprime(MSize)) MSize++;
    
    fill(hhash,hhash+MSize,0);
    
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        findPos(temp);

        if(i != N-1){
            printf(" ");
        }
    }

    return 0;
}

/*
4 4
10 6 4 15

0 1 4 -
*/