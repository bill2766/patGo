#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 100000
#define MAX_K 10000

int value[MAX_N], resultList[MAX_N],removedList[MAX_N], resultCnt = 0, removedCnt = 0;

bool marked[MAX_K + 1]; // 这里要加1，因为下标从0开始

void printList(int list[], int cnt){
    if(cnt == 0)return; // 长度可能是0，要及时终止函数
    
    // 打印前cnt - 1 个结点
    for(int i = 0, t, l = cnt - 1; i < l; i++){
        t = list[i];
        printf("%05d %d %05d\n", t, value[t], list[i + 1]);
    }
    // 打印最后一个结点
    printf("%05d %d -1\n", list[cnt - 1], value[list[cnt - 1]]);
}

int main() {
    int N, S, next[MAX_N];
    scanf("%d %d",&S, &N);
    for(int i = 0, address; i < N; i++){
        scanf("%d", &address);
        scanf("%d", &value[address]);
        scanf("%d", &next[address]);
    }
    // 初始化marked数组，默认所有绝对值未存在
    fill(marked, marked + MAX_K + 1, false);
    
    // 边遍历边讲结点放到结果列表和删去列表中
    for(int x = S, absVal; x != -1; x = next[x]){
        absVal = fabs(value[x]);
        if(marked[absVal]){
            removedList[removedCnt++] = x;
        }else{// 如果遍历到新值结点，还需将其值标记为已存在
            marked[absVal] = true;
            resultList[resultCnt++] = x;
        }
    }
    
    // 打印列表
    printList(resultList, resultCnt);
    printList(removedList, removedCnt);
    return 0;
}
