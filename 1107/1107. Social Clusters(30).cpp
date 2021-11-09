#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1010;

int N;
int father[MAX_N];

void Init(){
    for(int i=1;i<MAX_N;i++){
        father[i] = i;
    }
}

int findFather(int x){
    int thex = x;
    while(x != father[x]) x = father[x];

    while(thex != father[thex]){
        int temp = thex;
        thex = father[thex];
        father[temp] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

int course[1010] = {0};
vector<int> isRoot;

int cmp1(int a, int b){return a > b;}

int main(){
    Init();
    scanf("%d",&N);

    int tSize;
    int t;
    for(int i=1;i<=N;i++){
        scanf("%d: ",&tSize);
        for(int j=0;j<tSize;j++){
            scanf("%d",&t);
            if(course[t] == 0){
                course[t] = i;
            }
            Union(findFather(course[t]), i);
            
        }
    }

    //isRoot[i]表示编号i的人是不是它自己社交圈子的根结点，如果等于0表示不是根结点，
    //如果不等于0，每次标记isRoot[findFather(i)]++，那么isRoot保存的就是如果当前是根结点，那么这个社交圈里面的总人数
    isRoot.resize(N + 1);
    for(int i=1; i<=N; i++){
        int fa = findFather(i);
        isRoot[fa]++;
    }
    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(isRoot[i] != 0){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }

    return 0;
}

/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

3
4 3 1
*/