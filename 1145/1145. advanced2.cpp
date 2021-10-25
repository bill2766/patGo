#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX_M 10007
#define MAX 100000
using namespace std;

int table[MAX_M], cnt = 0;
int MSize;

bool isPrime(int n){
    if(n <= 1) return false;// 注意小于等于1不是素数
    for(int i = 2, l = sqrt(n); i <= l; i++){
        if(n % i == 0)return false;
    }
    return true;
}

// 插入
bool insert(int n){
    int M;
    int step = 0;
    while (step < MSize) {
        M = (n + step * step) % MSize;
        if(table[M] == 0){
            table[M] = n;
            return true;
        }
        step++;
    }
    return false;
}

// 搜索
void search(int n){
    int M;
    int step = 0;
    while (step < MSize) {
        M = (n + step * step) % MSize;
        if(table[M] == 0 || table[M] == n){
            cnt += step + 1;
            return;
        }
        step++;
    }
    cnt += MSize + 1;
}
int main() {
// 求大于10000的最小素数，用于设置table的大小，当然也可以无脑把table开大一点
//    int Test = 10000;
//    while (!isPrime(Test)) Test++;
//    printf("%d", Test);
//    return 0;
    
    
    memset(table, 0, sizeof(int));
    
    int N, M;
    
    scanf("%d %d %d", &MSize, &N, &M);
    while (!isPrime(MSize)) MSize++;// 找到第一个大于等于TSize的素数
    for(int i = 0, n; i < N; i++){
        scanf("%d", &n);
        if(!insert(n)){
            printf("%d cannot be inserted.\n", n);
        }
    }
    for(int i = 0, n; i < M; i++){
        scanf("%d", &n);
        search(n);
    }
    printf("%.1f", cnt / (float)M);
    return 0;
}

