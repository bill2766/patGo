#include <cstdio>
#include <vector>
#define MAX_N 1001
using namespace std;

int heap[MAX_N], N;
bool maxHeap = true, minHeap = true;

vector<int> path;

void dfs(int k){
    if(k > N) return;
    path.push_back(heap[k]);
    if(k * 2 > N){// 到达叶子结点，输出路径
        printf("%d", path[0]);
        for(int i = 1, l = (int)path.size(); i < l; i++){
            printf(" %d", path[i]);
            if(maxHeap && path[i] > path[i - 1]) maxHeap = false;// 发现路径上有不符合大根堆的偏序关系，则不是大根堆
            if(minHeap && path[i] < path[i - 1]) minHeap = false;// 同理
        }
        putchar('\n');
    }else{
        dfs(k * 2 + 1);
        dfs(k * 2);
    }
    path.pop_back();
    
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &heap[i]);
    }
    
    dfs(1);
    printf(maxHeap ? "Max Heap" : (minHeap ? "Min Heap" : "Not Heap"));
    return 0;
}

