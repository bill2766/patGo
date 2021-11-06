#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> pos;
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int a, int b) {
    if (inl > inr) return;
    //都是对应的下标，1～n
    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
    //若a和b在根结点的左边，则a和b的最近公共祖先在当前子树根结点的左子树寻找
    if (aIn < inRoot && bIn < inRoot)
        lca(inl, inRoot-1, preRoot+1, a, b);
    //如果a和b在当前子树根结点的两边，在当前子树的根结点就是a和b的最近公共祖先
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    //如果a和b在当前子树根结点的右边，则a和b的最近公共祖先就在当前子树的右子树寻找
    else if (aIn > inRoot && bIn > inRoot)
        lca(inRoot+1, inr, preRoot+1+(inRoot-inl), a, b);
    else if (aIn == inRoot)
            printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
            printf("%d is an ancestor of %d.\n", b, a);
}

int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    in.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }
    return 0;
}