#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 10010;

string str[MAX_N];

bool cmp1(string a, string b){
    return (a+b) < (b+a);
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin>>str[i];
    }
    sort(str, str+N, cmp1);

    string res;
    for(int i=0; i<N; i++){
        res += str[i];
    }
    while(res.length() != 0 && res[0] == '0'){
        res.erase(res.begin());
    }

    if(res.length() == 0){
        cout<<"0";
    }else{
        cout<<res;
    }

    return 0;
}

/*
5 32 321 3214 0229 87

22932132143287
*/