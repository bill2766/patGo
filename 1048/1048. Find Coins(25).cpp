#include <iostream>
#include <vector>
using namespace std;

/////////////////太耗时
// int main(){
//     int n, sum;
//     cin>>n>>sum;

//     vector<int> coins(n);
//     for(int i=0;i<n;i++){
//         cin>>coins[i];
//     }

//     int mini = 501;
//     int otherj = 501;
//     int tempi;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(coins[i] + coins[j] == sum){
//                 tempi = min(coins[i],coins[j]);
//                 if(mini > tempi){
//                     mini = tempi;
//                     otherj = max(coins[i],coins[j]);
//                 }
//             }
//         }
//     }
//     if(mini != 501){
//         cout<<mini<<" "<<otherj;
//     }else{
//         cout<<"No Solution";
//     }
//     return 0;
// }

int arr[10001];
int main(){
    int n,sum;
    cin>>n>>sum;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr[temp]++;
    }

    for(int i=0;i<10001;i++){
        if(arr[i] != 0){
            //以免碰到arr[i]+arr[sum-i]=sum且i=sum-i的情况
            arr[i]--;
            if(sum > i && arr[sum-i]!=0){
                cout<<i<<" "<<(sum-i);
                return 0;
            }
            arr[i]++;
        }
    }
    cout<<"No Solution";
    return 0;
}

/*
8 15
1 2 8 7 2 4 11 15

4 11
*/