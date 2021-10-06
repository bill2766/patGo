#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    
    int left;
    if(n % 2 == 1){
        left = n/2+1;
    }else{
        left = n/2;
    }

    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n,cmp);

    int result = 0;
    for(int i=0;i<n;i++){
        if(i<left){
            result += arr[i];
        }else{
            result -= arr[i];
        }
    }

    cout<< n%2<<" "<<result;
    return 0;
}

/*
10
23 8 10 99 46 2333 46 1 666 555

0 3611


13
110 79 218 69 3721 100 29 135 2 6 13 5188 85

1 9359
*/