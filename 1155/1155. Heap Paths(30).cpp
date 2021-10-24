#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1010;

int n;
int arr[MAX_N];

vector<int> path;

void traverse(int ind){
    path.push_back(arr[ind]);

    //有限度的遍历
    if(ind*2+1 <= n){
        traverse(ind*2+1);
        path.pop_back();
    }
    if(ind*2 <= n){
        traverse(ind*2);
        path.pop_back();
    }
    //如果 ind 是 叶子结点，输出路径
    if(ind*2 > n){
        for(int i=0;i<path.size();i++){
            printf("%d",path[i]);
            if(i != path.size() -1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }

    traverse(1);

    int maxheap = 1, minheap = 1;
    for(int i=2;i<=n;i++){
        if(arr[i] < arr[i/2]) minheap = 0;
        if(arr[i] > arr[i/2]) maxheap = 0;
    }
    if(minheap) printf("Min Heap");
    else if(maxheap) printf("Max Heap");
    else printf("Not Heap");

    return 0;
}

/*
8
98 72 86 60 65 12 23 50

98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap


8
8 38 25 58 52 82 70 60

8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap


8
10 28 15 12 34 9 8 56

10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap
*/