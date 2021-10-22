#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MAX_N = 1010;

int m, n;
int arr[MAX_N];

void postOrder(int ind){
    int left = ind*2, right = ind*2+1;
    if(ind > n) return;
    postOrder(left);
    postOrder(right);
    printf("%d",arr[ind]);
    if(ind != 1){
        printf(" ");
    }else{
        printf("\n");
    }
}

int main(){
    scanf("%d %d",&m,&n);

    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[j]);
        }

        int isBig = 1, isSmall = 1;
        for(int k=2;k<=n;k++){
            if(arr[k] < arr[k/2]) isSmall = 0;
            if(arr[k] > arr[k/2]) isBig = 0;
        }
        if(isBig) cout<<"Max Heap"<<endl;
        if(isSmall) cout<<"Min Heap"<<endl;
        if(!isBig && !isSmall) cout<<"Not Heap"<<endl;

        postOrder(1);
    }
    
    return 0;
}

/*
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56

Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
*/