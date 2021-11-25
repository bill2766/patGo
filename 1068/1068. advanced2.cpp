#include <cstdio>
#include <algorithm>
#include <functional>// 包含greater<int>()
#define MAX_N 10000
#define MAX_M 100

using namespace std;



//w[i]表示金币面值（同时是weight重量和cost价值），dp[v]表示空间为v时最大的价值
int w[MAX_N + 1] = {0},dp[MAX_N + 1];

int res[MAX_N + 1];
//c[i][v]表示达到价值v时是否放入第i个硬币
bool c[MAX_N + 1][MAX_M + 1];

int main() {
    //N为硬币个数，M为应付金额
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &w[i]);
    }
    //为了后面逆向输出（从小到的大的）路径
    sort(w + 1, w + N + 1, greater<int>());
    
    //边界
    fill(dp, dp + MAX_N + 1, 0);

    for(int i = 1; i <= N; i++){
        for(int v = M; v >= w[i]; v--){
            //状态转移方程
            if(dp[v] <= dp[v - w[i]] + w[i]){
                dp[v] = dp[v - w[i]] + w[i];
                c[i][v] = true;
            }else{
                c[i][v] = false;
            }
        }
    }
    
    //遍历完成后如果dp[M]!=M即没有一个序列能达到M，否则逆向查找出路径（题目要求输出字典序小的）
    if(dp[M] != M){
        printf("No Solution");
    }else{
        //res.push( c[k从N->0][v -= w[k]] )
        int cnt = 0, k = N, v = M;
        while (k >= 0) {
            if(c[k][v]){
                res[cnt++] = w[k];
                v -= w[k];
            }
            k--;
        }
        
        printf("%d", res[0]);
        for(int i = 1; i < cnt; i++){
            printf(" %d", res[i]);
        }
    }

    return 0;
}
