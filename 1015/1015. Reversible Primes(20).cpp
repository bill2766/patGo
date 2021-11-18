#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N, D;
int revN;

int revInt(int n, int d){
    vector<int> toD;
    while(n != 0){
        toD.push_back(n % d);
        n = n / d;
    }
    int revN = 0;
    for(int i=0;i<toD.size();i++){
        revN += pow(d,toD.size()-1-i) * toD[i];
    }
    return revN;
}

bool isPrime(int n){
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i=2; i<=sqr; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    while(true){
        scanf("%d %d",&N,&D);
        if(N < 0) break;

        string revNStr = to_string(N);
        revN = revInt(N,D);

        if(isPrime(N) && isPrime(revN)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}

/*
73 10
23 2
23 10
-2

Yes
Yes
No
*/