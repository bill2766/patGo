#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX_N 100000
using namespace std;
int main() {
    int N, P;
    int a[MAX_N];
    scanf("%d %d", &N, &P);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    
    int cnt = 0;
    for(int i = 0, j; i < N; i++){
        // 注意这里的类型转换，避免乘积溢出
        j = (int)(upper_bound(a + i + 1, a + N, (long long)a[i] * P) - a);
        cnt = max(cnt, j - i);
    }
    printf("%d", cnt);
    return 0;
}