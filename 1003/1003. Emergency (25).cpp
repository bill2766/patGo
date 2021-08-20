#include <cstdio>
#include <algorithm>
using namespace std;


const int maxn = 510;
const int INF = 1000000000;

int N, M;
int C1, C2;

int G[maxn][maxn];
int weight[maxn];

int d[maxn];
int w[maxn];
int num[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s){
    fill(d,d+maxn,INF);
    fill(w,w+maxn,0);
    fill(num,num+maxn,0);

    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;

    for(int i=0; i<N; i++){
        int u=-1, MIN = INF;
        for(int j=0; j<N; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0; v<N; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }else if(d[u] + G[u][v] == d[v]){
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                    }
                    num[v] = num[v] + num[u]; //原来的几条 加上 现在的几条
                }
            }
        }
    }
}

int main(){
    fill(G[0],G[0]+maxn*maxn,INF);

    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0; i<N; i++){
        scanf("%d",&weight[i]);
    }

    int from, to, wei;
    for(int i=0; i<M; i++){
        scanf("%d%d%d",&from,&to,&wei);
        G[from][to] = wei;
        G[to][from] = wei;
    }

    Dijkstra(C1);
    printf("%d %d",num[C2], w[C2]);
    return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/

//2 4


/*
6 7 0 5
1 4 3 2 2 4
0 2 2
0 1 1
1 3 2
2 4 1
2 3 4
4 5 2
3 5 2
*/

//2 11