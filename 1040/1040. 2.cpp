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
    fill(dp[0], dp[0]+num*num, false);
    
    for(int i=0; i<num; i++){
        dp[i][i] = true;
        if(i < num - 1 && s[i] == s[i+1]){
            dp[i][i+1] = true;
            maxLen = 2;
        }
    }

    for(int L=3; L<=num; L++){
        for(int i=0; i + L -1 < num; i++){
            //j - i + 1 = L
            int j = i + L -1;

            if(s[i] == s[j] && dp[i+1][j-1] == true) {
                dp[i][j] = true;
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