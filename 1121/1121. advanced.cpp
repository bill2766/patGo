#include <cstdio>
#include <algorithm>
#define MAX_ID 1000000
#define MAX_M 10000
using namespace std;

int couples[MAX_ID], idInPart[MAX_M], single[MAX_M];
bool inPart[MAX_ID];

int main() {
    fill(couples, couples + MAX_ID, -1);// 初始化为-1，代表每个人都是单身
    fill(inPart, inPart + MAX_ID, false);
    
    // couples[a] = b 表示a的配偶是b
    int N;
    scanf("%d", &N);
    for(int i = 0, a, b; i < N; i++){
        scanf("%d %d", &a, &b);
        couples[a] = b;
        couples[b] = a;
    }
    
    
    // 边读入Party成员边分别标记该成员是否在party上，同时存储party的成员
    int M;
    scanf("%d", &M);
    for(int i = 0, t; i < M; i++){
        scanf("%d", &t);
        inPart[t] = true;
        idInPart[i] = t;
    }
    
    // 遍历party成员，如果该成员是单身的，或者他的配偶不在party上，则他是单身的
    int cnt = 0;
    for(int i = 0, t; i < M; i++){
        t = idInPart[i];
        if(couples[t] == -1 || !inPart[couples[t]]){
            single[cnt++] = t;
        }
    }
    
    // 排序
    sort(single, single + cnt);
    
    // 输出结果
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        if(i > 0) putchar(' ');
        printf("%05d", single[i]);
    }
    return 0;
}
