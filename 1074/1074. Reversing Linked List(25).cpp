#include <iostream>

using namespace std;

const int MAX_N = 100010;

int n,k;
int first;
int ddata[MAX_N];

int nnext[MAX_N];
int list[MAX_N];
int result[MAX_N];

int ssize = 0;

int main(){
    cin>>first>>n>>k;

    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        scanf("%d",&ddata[temp]);
        scanf("%d",&nnext[temp]);
    }

    while(first != -1){
        list[ssize++] = first;
        first = nnext[first];
    }

    //只有一个元素的情况，快速结束
    if(ssize == 1){
        printf("%05d %d -1",list[0],ddata[list[0]]);
        return 0;
    }

    for(int i=0;i<ssize;i++){
        result[i] = list[i];
    }

    int left,right;
    for(int i=0;i<ssize/k;i++){
        left = i * k;
        for(right=left+k-1;right>=(i*k);right--){
            result[left] = list[right];
            left++;
        }
    }

    for(int i=0;i<=ssize-2;i++){
        printf("%05d %d %05d\n",result[i],ddata[result[i]],result[i+1]);
    }
    printf("%05d %d -1",result[ssize-1],ddata[result[ssize-1]]);

    return 0;
}

/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/