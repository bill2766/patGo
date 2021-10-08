#include <iostream>

using namespace std;

const int MAX_N = 100010;

int first, n, k;

int ssize = 0;

int ddata[MAX_N];
int nnext[MAX_N];

int addr[MAX_N];
int result[MAX_N];

int main(){
    cin>>first>>n>>k;

    int temp;
    for(int i=0;i<n;i++){
        scanf("%d ",&temp);
        scanf("%d %d",&ddata[temp],&nnext[temp]);
    }

    while(first != -1){
        addr[ssize++] = first;
        first = nnext[first];
    }

    int ind = 0;
    for(int i=0;i<ssize;i++){
        if(ddata[addr[i]] < 0){
            result[ind++] = addr[i];
        }
    }
    for(int i=0;i<ssize;i++){
        if(ddata[addr[i]] >= 0 && ddata[addr[i]] <= k){
            result[ind++] = addr[i];
        }
    }
    for(int i=0;i<ssize;i++){
        if(ddata[addr[i]] > k){
            result[ind++] = addr[i];
        }
    }

    //打印
    for(int i=0;i<=ssize-2;i++){
        printf("%05d %d %05d\n",result[i],ddata[result[i]],result[i+1]);
    }
    printf("%05d %d -1",result[ssize-1],ddata[result[ssize-1]]);

    return 0;
}

/*
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218

33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/