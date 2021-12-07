#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int weight;
    //比较过程用的下标
    int index;
    int rank;
    //原来的下标，要输出的开始下标
    int index0;
};

bool cmp1(node a, node b){
    return a.index0 < b.index0;
}

int main(){
    int n, g, num;
    scanf("%d %d",&n,&g);

    vector<int> v(n);
    vector<node> w(n);

    for(int i=0; i<n; i++){
        scanf("%d",&v[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }

    queue<node> q;
    for(int i=0; i<n; i++){
        q.push(w[i]);
    }

    while(!q.empty()){
        int size = q.size();
        //先考虑最后的极端情况，只剩一个
        if(size == 1){
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }

        int group = size / g;
        if(size % g != 0){
            group += 1;
        }

        node maxnode;
        int maxn = -1, cnt = 0;
        //这个for循环结果是：过完了第一波，剩下每组最大的那个回到queue里
        for(int i=0; i<size; i++){
            node temp = q.front();
            w[temp.index].rank = group+1;
            q.pop();
            cnt++;
            if(temp.weight > maxn){
                maxn = temp.weight;
                maxnode = temp;
            }
            //凑够一组或者到了最后
            if(cnt == g || i == size-1){
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }

    //按号码牌给出排名
    sort(w.begin(), w.end(), cmp1);
    for(int i=0; i<n; i++){
        if(i != 0) printf(" ");
        printf("%d",w[i].rank);
    }

    return 0;
}

/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

5 5 5 2 5 5 5 3 1 3 5
*/