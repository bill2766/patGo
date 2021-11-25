#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 10010;
const int MAX_M = 110;
//将其看做价值和质量等同的0-1背包问题，将硬币从大到小排序后，依次考虑是否放入第i个硬币

//w[i]表示金币面值（同时是重量w[i]和价值c[i]），dp[v]表示空间为v时最大的价值
int w[MAX_N],dp[MAX_M];
//c[i][v]表示达到价值v时是否放入第i个硬币
int c[MAX_N][MAX_M];

//N为硬币个数，M为应付金额
int N, M;

bool cmp1(int a, int b){
    return a>b;
}

int main(){
    cin>>N>>M;
    //下标从1开始
    for(int i=1; i<=N; i++) cin>>w[i];

    //从大到小排序w[1]~w[N]。为了后面逆向输出（从小到的大的）路径
    sort(w+1, w+N+1, cmp1);

    //边界
    for(int v=0; v<=M; v++){
        dp[v] = 0;
    }

    for(int i=1; i<=N; i++){
        for(int v=M; v>=w[i]; v--){
            //状态转移方程
            //等价于dp[v] = max(dp[v], dp[v-w[i]]+c[i]); 在这道题中w[i]=c[i]
            //一定得是>=，这表示如果有机会选后面的（小的）（也就是当前的i），一定选后面
            if(dp[v-w[i]] + w[i] >= dp[v]){
                dp[v] = dp[v-w[i]] + w[i];
                //表示在当前的i物品下的当前v下这个物品被选中了
                c[i][v] = true;
            }else{
                c[i][v] = false;
            }
        }
    }

    vector<int> res;
    //遍历完成后如果dp[M]!=M即没有一个序列能达到M，否则逆向查找出路径（题目要求输出字典序小的）
    if(dp[M] != M){
        printf("No Solution");
    }else{
        //res.push( c[k从N->1][v -= w[k]] )
        int i = N, v = M;
        while(i >= 1){
            if(c[i][v] == true){
                res.push_back(w[i]);
                v-= w[i];
            }
            i--;
        }

        for(int i=0; i<res.size(); i++){
            printf("%d",res[i]);
            if(i != res.size()-1) printf(" ");
        }
    }

    return 0;
}

/*
8 9
5 9 8 7 2 3 4 1

1 3 5


4 8
7 2 4 3

No Solution
*/