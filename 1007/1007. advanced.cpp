#include <iostream>
#include <vector>
using namespace std;

int main() {
    //n 数目
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1
        , temp = 0, tempindex = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        //更新temp
        temp = temp + v[i];
        //如果temp<0，表示是负数，一定会舍弃
        if (temp < 0) {
            temp = 0;
            //让tempindex变成i+1，给后面使用
            tempindex = i + 1;
        //如果temp大于当前sum
        } else if (temp > sum) {
            //更新sum
            sum = temp;
            //设置左下标和右下标
            leftindex = tempindex;
            rightindex = i;
        }
    }
    //没找到，则默认设为0
    if (sum < 0) sum = 0;

    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}