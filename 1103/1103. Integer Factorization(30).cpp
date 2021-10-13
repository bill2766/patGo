#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_N = 401;

int n,k,p;

int numsSize = 0;
int nums[MAX_N];

int maxsumSingle = -1;

vector<int> temp, ans;

void dfs(int index, int nowK, int sum, int sumSingle){
    if(nowK == k && sum == n){
        //不能>=，否则会选择“数小”的数组去了
        if(sumSingle > maxsumSingle){
            maxsumSingle = sumSingle;
            ans = temp;
        }
        return;
    }
    //处理完numsSize个数 / 超过k个数 / 和超过“n”
    if(index == numsSize || nowK > k || sum > n) return;
    //选
    temp.push_back(nums[index]);
    dfs(index,nowK+1,sum+pow(nums[index],p),sumSingle+nums[index]);
    temp.pop_back();
    //不选
    dfs(index+1,nowK,sum,sumSingle);
}


int main(){
    cin>>n>>k>>p;
    //从n的p根号开始～1
    for(int i=pow(n,(double)1/p);i>=1;i--){
        nums[numsSize++] = i;
    }

    // for(int i=0;i<numsSize;i++){
    //     cout<<nums[i]<<endl;
    // }

    dfs(0,0,0,0);

    if(!ans.empty()){
        cout<<n<<" "<<"="<<" ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"^"<<p;
            if(i != ans.size()-1){
                cout<<" + ";
            }
        }
    }else{
        printf("Impossible");
    }

    return 0;
}

/*
169 5 2

169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2


169 167 3

Impossible
*/