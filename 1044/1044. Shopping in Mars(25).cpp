#include <iostream>
#include <vector>

using namespace std;

// //数组要大，不然就是段错误
// const int MAX_N = 1000000;
// const int INF = 1000000000;

// int n,m;
// int d[MAX_N];

// struct Node{
//     int begin;
//     int end;
//     Node(int b,int e):begin(b),end(e){}
// };

// int loss = INF;
// vector<Node> res;


// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>d[i];
//     }

//     long long temp_sum = 0;
//     int temp_loss = INF;
//     for(int i=1;i<=n;i++){
//         for(int j=i;j<=n;j++){
//             temp_sum += d[j];
//             if(temp_sum < m){
//                 continue;
//             }else{
//                 temp_loss = temp_sum - m;
//                 if(temp_loss < loss){
//                     loss = temp_loss;
//                     res.clear();
//                     res.push_back(Node(i,j));
//                 }else if(temp_loss == loss){
//                     res.push_back(Node(i,j));
//                 }
//                 temp_sum = 0;
//                 temp_loss = INF;
//                 break;
//             }
//         }
//     }

//     for(int i=0;i<res.size();i++){
//         cout<<res[i].begin<<"-"<<res[i].end;
//         if(i != res.size()-1){
//             cout<<endl;
//         }
//     }

//     return 0;
// }

vector<int> sum, resultArr;
int n,m;

//获得第一个>=m的位置 或 最后一个位置
void Func(int i,int& j,int& tempSum){
    int left=i, right=n;
    int mid;
    while(left < right){
        mid = (left+right) /2;
        if(sum[mid] - sum[i-1] >= m){
            right = mid;
        }else{
            left = mid +1;
        }
    }
    j = left;
    tempSum = sum[j] - sum[i-1];
}

int main(){
    scanf("%d %d",&n,&m);
    sum.resize(n+1);
    for(int i=1;i <= n;i++){
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }

    int minans = sum[n];
    for(int i=1;i<=n;i++){
        int j, tempSum;
        Func(i,j,tempSum);
        if(tempSum > minans) continue;
        if(tempSum >= m){
            if(tempSum < minans){
                resultArr.clear();
                minans = tempSum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }

    for(int i=0;i<=resultArr.size()-2;i+=2){
        printf("%d-%d",resultArr[i],resultArr[i+1]);
        if(i != resultArr.size()-2){
            printf("\n");
        }
    }

    return 0;
}


/*
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

1-5
4-6
7-8
11-11
*/

/*
5 13
2 4 5 7 9

2-4
4-5
*/