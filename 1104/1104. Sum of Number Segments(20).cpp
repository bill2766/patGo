#include <iostream>

using namespace std;


int main(){
    int n;
    double val;
    scanf("%d\n",&n);
    long long res = 0;

    for(int i=1; i<=n; i++){
        cin>>val;
        res += (long long)(val * 1000) * i * (n-i+1);
    }

    printf("%.2f",res/1000.0);
    
    return 0;
}

/*
4
0.1 0.2 0.3 0.4

5.00
*/