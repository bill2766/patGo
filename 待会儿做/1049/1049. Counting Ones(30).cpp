#include <cstdio>
#include <string>
using namespace std;

int oneNum(int val){
    int count = 0;
    string str = to_string(val);
    for(int i=0; i<str.length(); i++){
        if(str[i] == '1'){
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    scanf("%d",&N);
    int res = 0;
    for(int i=1; i<=N; i++){
        res += oneNum(i);
    }

    printf("%d",res);

    return 0;
}

/*
12

5
*/