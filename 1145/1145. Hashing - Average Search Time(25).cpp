#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_MSize = 10010;
int MSize, N, M;
int arr[MAX_MSize];

int sum = 0;

bool isprime(int num){
    if(num <= 1) return false;
    for(int i=2; i * i <= num ;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

bool insert(int val){
    int pos;
    for(int i=0;i<MSize;i++){
        pos = (val + i*i) % MSize;
        if(arr[pos] == 0){
            arr[pos] = val;
            return true;
        }
    }
    return false;
}

void find(int val){
    int count = 0;
    int i;
    for(i=0;i<MSize;i++){
        count++;
        int pos = (val + i*i) % MSize;
        if(arr[pos] == 0 || arr[pos] == val) break;
    }
    sum+=count;
    if(i == MSize) sum+=1;
}  

int main(){
    scanf("%d %d %d",&MSize,&N,&M);
    fill(arr,arr+MAX_MSize,0);
    while(!isprime(MSize)) MSize++;

    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        bool isinsert = insert(temp);
        if(!isinsert) printf("%d cannot be inserted.\n",temp);
    }

    for(int i=0;i<M;i++){
        scanf("%d",&temp);
        find(temp);
    }

    printf("%.1f", sum*1.0/M);

    return 0;
}

/*
4 5 4
10 6 4 15 11
11 4 15 2

15 cannot be inserted.
2.8
*/