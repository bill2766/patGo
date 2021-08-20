#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//存储子结点，下标为名称
vector<int> v[100];
//book记录层的叶子结点数目
int book[100], maxdepth = -1;

void dfs(int index, int depth) {
    //更新当前depth的叶子结点数目；并且更新maxdepth
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    //递归 叶子结点
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}

int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);

    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
        
    return 0;
}