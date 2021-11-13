#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 510;

int N, M;
int G[MAX_N][MAX_N];
int degree[MAX_N] = {0};

bool visited[MAX_N];
void dfs(int u){
    visited[u] = true;
    for(int v=1;v<=N;v++){
        if(G[u][v] != 0){
            G[u][v] = G[v][u] = 0;
            if(visited[v] == false){
                dfs(v);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    int v1, v2;
    for(int i=0;i<M;i++){
        cin>>v1>>v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
        degree[v1]++;
        degree[v2]++;
    }

    int isWhat = 0;
    for(int i=1;i<=N;i++){
        isWhat+=degree[i] % 2 ;

        printf("%d",degree[i]);
        if(i != N){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    bool isCnt = true;
    dfs(1);
    for(int i=1;i<=N;i++){
        if(visited[i] == false){
            isCnt = false;
            break;
        }
    }

    if(isWhat == 0 && isCnt){
        printf("Eulerian");
    }else if(isWhat == 2 && isCnt){
        printf("Semi-Eulerian");
    }else{
        printf("Non-Eulerian");
    }

    return 0;
}


/*
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6

2 4 4 4 4 4 2
Eulerian


6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6

2 4 4 4 3 3
Semi-Eulerian


5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3

3 3 4 3 3
Non-Eulerian
*/