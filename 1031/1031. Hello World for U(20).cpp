#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int main(){
    string str;
    cin>>str;
    int N = str.length();

    int nh, nv;
    //因为 2nv + nh = (N+2)
    //向下取 表示nv要小于nh，小数部分给nh；除非nv = nh
    nv = (N+2) / 3;
    nh = N + 2 - nv - nv;

    string kong = "";
    for(int j=0; j<nh-2; j++) kong+=" ";

    for(int i=0; i < nv-1; i++){    
        string out = str[i] + kong + str[N-1-i];
        cout<<out<<endl;
    }
    for(int i=nv-1; i<nv-1+nh; i++){
        cout<<str[i];
    }

    return 0;
}

/*
helloworld!

h   !
e   d
l   l
lowor
*/