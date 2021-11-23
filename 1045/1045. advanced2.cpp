#include <iostream>
#include <algorithm>

#define MAX_M 200
#define MAX_L 10000

int rank[MAX_M + 1];

int main() {
    std::fill(rank, rank + MAX_M + 1, -1);
    
    // 读取喜欢序列，将数字转化为权值
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0, t; i < M; i++){
        scanf("%d", &t);
        rank[t] =  i;
    }
    
    // 读取待裁剪序列，其中属于喜欢序列的数字直接转换为权值存储
    int L, a[MAX_L], len = 0;
    scanf("%d", &L);
    for(int i = 0, t; i < L; i++){
        scanf("%d", &t);
        if(rank[t] >= 0){
            a[len++] = rank[t];
        }
    }
    
    // 求最大不下降子序列
    int dp[MAX_L], res = -1;
    for(int i = 0; i < len; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j] && dp[j] + 1 > dp[i]){// ai可以跟在以aj为结尾的最长递增子序列的后面，且在该序列后加上ai会使得序列更长，则更新
                dp[i] = dp[j] + 1;
            }
        }
        res = std::max(res, dp[i]); // 更新答案
    }
    
    printf("%d", res);
    return 0;
}
