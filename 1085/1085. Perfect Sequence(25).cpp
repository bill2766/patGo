#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int main(){
    long long arr[MAX_N];

    int n;
    int p;
    scanf("%d %d",&n,&p);

    if(n == 0){
        cout<<n;
        return 0;
    }

    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);


    int maxLen = 1;
    long long mp;
    int mid;
    for(int min=0; min<=n-1; min++){
        mp = arr[min] * p;

        //等同于upper_bound()函数
        int left = min+1;
        int right = n;
        //找到第一个大于mp的下标
        while(left < right){
            mid = (left + right) / 2;
            if(arr[mid] <= mp){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        //left-min等同于 第一个大于mp的下标-min = 最后一个小于等于mp的下标-min+1 = 序列的长度
        if(left - min > maxLen){
            maxLen = left - min;
        }
    }

    cout<<maxLen;

    return 0;
}

/*
10 8
2 3 20 4 5 1 6 7 8 9

8
*/

/*
3 6
2 2 2

3
*/