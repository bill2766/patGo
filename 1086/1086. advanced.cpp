#include <cstdio>
#define MAX_N 30

int tree[(1 << 30) + 1];
int postOrder[MAX_N], cnt = 0;

void dfs(int root){
    if(tree[root] == 0) return;
    dfs(root * 2);// 递归求左子树
    dfs(root * 2 + 1);// 递归求右子树
    postOrder[cnt++] = root;// 将根结点下标加入到后序数组中
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    char s[5];
    for(int i = 0, k = 1, l = 2 * N; i < l; i++){
        scanf("%s", s);
        if(s[1] == 'u'){ // push操作，插入新结点并将指针移动到新结点的左子结点
            scanf("%d", &tree[k]);
            k = k * 2;
        }else{// pop操作，比较复杂
            if(k % 2 == 0){// 如果当前指向的是左子结点，则将指针移动到与之相同父结点的右子结点
                k++;
            }else{
                // 不断向上移动直到移动到一个左子结点
                do{
                    k = k / 2;
                }
                while (k % 2 == 1);
                
                k++;// 移动到同父结点的右子结点
            }
        }
    }
    dfs(1);
    
    // 输出结果
    printf("%d", tree[postOrder[0]]);
    for(int i = 1; i < N; i++){
        printf(" %d", tree[postOrder[i]]);
    }
    return 0;
}

