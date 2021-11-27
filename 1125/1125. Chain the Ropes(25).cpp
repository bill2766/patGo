#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N = 10010;
int N;
int nums[MAX_N];


int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+N);

    double res = (nums[0]+nums[1]) / 2.0;
    for(int i=2; i<N; i++){
        res = (res+nums[i]) / 2.0;
    }

    printf("%d", int(res));

    return 0;
}

/*
8
10 15 12 3 4 13 1 15

14
*/