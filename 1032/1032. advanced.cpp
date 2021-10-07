#include <cstdio>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];

int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }

    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        //遍历第一条链表，将访问过的结点的flag都标记为true
        //当遍历第二条结点的时候，如果遇到了true的结点就输出并结束程序，没有遇到就输出-1
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}