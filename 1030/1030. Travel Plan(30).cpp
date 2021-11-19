#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 510;
const int INF = 1000000000;

struct Node{
    int v;
    int dis;
};
vector<Node> Adj[MAX_N];
int N, M, S, D;
int costs[MAX_N][MAX_N];

int d[MAX_N];
bool vis[MAX_N];
int pre[MAX_N];
int c[MAX_N];

void Dijkstra(int s){
    fill(d,d+MAX_N, INF);
    fill(vis,vis+MAX_N,false);
    d[s] = 0;

    for(int i=0;i<N;i++) pre[i] = i;
    fill(c,c+MAX_N, INF);
    c[s] = 0;

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

        for(int j=0;j<Adj[u].size();j++){
            int v = Adj[u][j].v;
            if(vis[v]==false && d[u] + Adj[u][j].dis < d[v]){
                d[v] = d[u] + Adj[u][j].dis;
                c[v] = c[u] + costs[u][v];
                pre[v] = u;
            }else if(d[u] + Adj[u][j].dis == d[v] && c[u] + costs[u][v] < c[v]){
                c[v] = c[u] + costs[u][v];
                pre[v] = u;
            }
        }
    }
}

void DFS(int s, int v){
    if(pre[v] == v){
        printf("%d ",v);
        return;
    }
    DFS(s, pre[v]);
    printf("%d ",v);
}

int main(){
    cin>>N>>M>>S>>D;
    int c1, c2, dis, cost;
    for(int i=0;i<M;i++){
        cin>>c1>>c2>>dis>>cost;
        Node node;
        node.dis = dis;
        node.v = c2;
        Adj[c1].push_back(node);
        node.v = c1;
        Adj[c2].push_back(node);
        costs[c1][c2] = costs[c2][c1] = cost;
    }

    Dijkstra(S);

    DFS(S, D);
    printf("%d %d",d[D],c[D]);

    return 0;
}

/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

0 2 3 3 40
*/