#include <cstdio>

int findNotOk(int* arr, int begin, int end){
    for(int i=begin; i<end; i++){
        if(arr[i] != i) return i;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    int* arr = new int[n];
    int t;
    for(int i=0; i<n; i++){
        scanf("%d",&t);
        arr[t] = i;
    }

    int count = 0;
    int temp = 0;
    int firstPos = 1;
    firstPos = findNotOk(arr, firstPos, n);

    while(firstPos){
        if(arr[0] == 0){
            arr[0] = arr[firstPos];
            arr[firstPos] = 0;
            count++;
        }

        while(arr[0] != 0){
            temp = arr[0];
            arr[0] = arr[temp];
            arr[temp] = temp;
            count++;
        }
        firstPos = findNotOk(arr, firstPos, n);
    }

    printf("%d\n", count);

    return 0;
}

/*
10
3 5 7 2 6 4 9 0 8 1

9
*/