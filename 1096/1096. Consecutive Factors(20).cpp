#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long int num, temp;

int main(){
    cin>>num;
    int maxn = sqrt(num) + 1;

    int begin=0, len=0;
    for(int i=2; i<maxn; i++){
        temp = 1;

        int j;
        for(j = i; j<maxn; j++){
            temp *= j;
            if(num % temp != 0) break;
        }

        if(j-i > len){
            len = j-i;
            begin = i;
        }
    }

    if(begin == 0){
        cout<<1<<endl<<num;
    }else{
        cout<<len<<endl;
        for(int i=0; i<len; i++){
            printf("%d",begin + i);
            if(i != len-1) printf("*");
        }
    }

    return 0;
}

/*
630

3
5*6*7
*/