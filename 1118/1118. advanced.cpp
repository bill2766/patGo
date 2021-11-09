#include <iostream>
using namespace std;
int n, m, k;
const int maxn = 10010;
int fa[maxn] = {0}, cnt[maxn] = {0};

int findFather(int x) {
    int a = x;
    while(x != fa[x])
        x = fa[x];
    while(a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) fa[faA] = faB;
}

//exist[i]表示鸟的id——i在输入的鸟的序号里面是否出现过
bool exist[maxn];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= maxn; i++)
        fa[i] = i;

    int id, temp;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &k, &id);
        exist[id] = true;
        for(int j = 0; j < k-1; j++) {
            scanf("%d", &temp);
            Union(id, temp);
            exist[temp] = true;
        }
    }

    for(int i = 1; i <= maxn; i++) {
        if(exist[i] == true) {
            int root = findFather(i);
            cnt[root]++;
        }
    }

    //遍历cnt数组并累加所有不为0的个数即可得知有多少棵树，累加所有出现过的鸟的id的cnt的值即可得知鸟的个数
    int numTrees = 0, numBirds = 0;
    for(int i = 1; i <= maxn; i++) {
        //寻找 根
        if(exist[i] == true && cnt[i] != 0) {
            numTrees++;
            numBirds += cnt[i];
        }
    }

    printf("%d %d\n", numTrees, numBirds);

    scanf("%d", &m);
    int ida, idb;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &ida, &idb);
        printf("%s\n", (findFather(ida) == findFather(idb)) ? "Yes" : "No");
    }
    return 0;
}