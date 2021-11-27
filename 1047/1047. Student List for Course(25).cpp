#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 40010;
const int MAX_K = 2510;

int N, K;
char names[MAX_N][5];
vector<int> classes[MAX_K];

bool cmp1(int a, int b){
    return strcmp(names[a],names[b]) < 0;
}

int main(){
    scanf("%d %d",&N, &K);
    int couNum;
    int curCou;
    for(int i=0; i<N; i++){
        scanf("%s %d", names[i], &couNum);
        for(int j=0; j<couNum; j++){
            scanf("%d", &curCou);
            classes[curCou].push_back(i);
        }
    }

    for(int cou=1; cou <= K; cou++){
        printf("%d %d\n", cou, classes[cou].size());
        sort(classes[cou].begin(), classes[cou].end(), cmp1);
        for(int i=0; i<classes[cou].size(); i++){
            printf("%s\n", names[classes[cou][i]]);
        }
    }

    return 0;
}

/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/