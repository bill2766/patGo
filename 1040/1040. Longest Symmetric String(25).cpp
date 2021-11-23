#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int longestPalindrome(string s){
    int num = s.length();
    if(num <= 1){
        return num;
    }

    int maxLen = 1;
    bool dp[num][num];
    
    for(int i=0;i<num;i++) dp[i][i] = true;

    for(int L=2; L<=num; L++){
        for(int i=0; i<num; i++){
            //j - i + 1 = L
            int j = i + L -1;
            if(j >= num) break;

            if(s[i] != s[j]){
                dp[i][j] = false;
            }else{
                if(j - i + 1 <= 3){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = dp[i+1][j-1];
                }
            }

            //这里实际上没有L > maxLen也会正确
            //因为for循环是从L=2开始慢慢变大的，如果有更大的长度直接赋值即可
            if(dp[i][j] == true && L > maxLen){
                maxLen = L;
            }
        }
    }
    return maxLen;
}

int main(){
    string inStr;
    getline(cin, inStr);

    int res = longestPalindrome(inStr);

    cout<<res;

    return 0;
}

/*
Is PAT&TAP symmetric?

11
*/