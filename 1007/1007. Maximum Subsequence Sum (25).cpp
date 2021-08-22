#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------------------部分成功，原因可能是tempi前推的时候没有找到最小的i
/*
const int maxn = 10001;

int seq[maxn];
vector<int> subseq;

int dp[maxn] = {0};
int maxDp = 0;

int main(){
    int maxInd;

    int num;
    scanf("%d",&num);

    for(int i=0; i<num; i++){
        scanf("%d",&seq[i]);
    }

    if(seq[0] > 0){
        dp[0] = seq[0];
    }

    for(int i=1; i<num; i++){
        if(dp[i-1] + seq[i] >= seq[i]){
            dp[i] = dp[i-1] + seq[i];
        }else{
            dp[i] = seq[i];
        }
    }
    
    bool allNeg = true;
    for(int i=0; i<num; i++){
        if(dp[i] > maxDp){
            maxDp = dp[i];
            maxInd = i;
            allNeg = false;
        }
    }

    if(!allNeg){
        int temp = maxDp;
        int tempi = maxInd;
        while(temp != 0){
            subseq.push_back(seq[tempi]);
            temp -= seq[tempi];
            tempi--;
        }

        printf("%d %d %d",maxDp, subseq.back(), subseq.front());
    }else{
        printf("%d %d %d",maxDp, seq[0], seq[num-1]);
    }

    return 0;
}
*/

/*
10
-10 1 2 3 4 -5 -23 3 7 -21
*/

//10 1 4

/*
4 
1 -1 2 3
*/

//5 2 3


//优解
int main(){
    int n;
    scanf("%d",&n);

    vector<int> arr(n);

    int sum=-1, leftindex=0, rightindex=n-1;
    int temp=0, tempindex=0;

    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
        temp = temp + arr[i];
        if(temp < 0){
            temp = 0;
            tempindex = i+1;
        }else{
            if(temp > sum){
                sum = temp;
                leftindex = tempindex;
                rightindex = i;
            }
        }
    }
    if(sum < 0) sum =0;

    printf("%d %d %d",sum,arr[leftindex],arr[rightindex]);
    return 0;
}