#include <iostream>
#include <vector>
using namespace std;

vector<int> sum, resultArr;
int n, m;

void Func(int i, int &j, int &tempsum) {
    int left = i, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if(sum[mid] - sum[i-1] >= m)
            right = mid;
        else
            left = mid + 1;
    }
    j = right;
    tempsum = sum[j] - sum[i-1];
}

int main() {
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }

    //min ans，初始化为所有数之和
    int minans = sum[n];
    for(int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        //超过minans，忽略
        if(tempsum > minans) continue;
        if(tempsum >= m) {
            //如果现在的情况小于minans，清空resultArr
            if(tempsum < minans) {
                resultArr.clear();
                minans = tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }

    //打印结果
    for(int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i+1]);

    return 0;
}