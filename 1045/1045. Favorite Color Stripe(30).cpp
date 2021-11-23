#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

//最大颜色数量
const int MAX_N = 210;
const int MAX_M = 10010;

int N, M;
int like[MAX_N];
//arr为保存喜欢颜色的排名
int arr[MAX_M];
int arrNum = 0;

int dp[MAX_M];
int res;

int main(){
    fill(like, like+MAX_N, -1);
    res = 0;

    cin>>N>>M;

    int temp;
    for(int i=0; i<M; i++){
        cin>>temp;
        like[temp] = i;
    }

    int befNum;
    cin>>befNum;
    for(int i=0;i<befNum;i++){
        cin>>temp;
        if(like[temp] >= 0){
            arr[arrNum++] = like[temp];
        }
    }

    for(int i=0;i<arrNum;i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] <= arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        res = max(res, dp[i]);
    }

    cout<<res;
    return 0;
}

/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

7
*/