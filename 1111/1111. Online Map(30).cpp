#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAX_N = 510;

int N, M;
int bbegin, eend;
int G[MAX_N][MAX_N];
int times[MAX_N][MAX_N];


int d[MAX_N];
bool vis[MAX_N];
int pre[MAX_N];
int t[MAX_N];
int NodesNum[MAX_N];

void Dijkstra1(int s){
    fill(d,d+MAX_N,INF);
    fill(vis,vis+MAX_N,false);
    d[s] = 0;
    fill(t,t+MAX_N,INF);
    t[s] = 0;
    for(int i=0;i<N;i++) pre[i] = i;

    for(int i=0;i<N;i++){
        int u=-1, MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v<N;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    t[v] = t[u] + times[u][v];
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v] && t[u] + times[u][v] < t[v]){
                    t[v] = t[u] + times[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void Dijkstra2(int s){
    fill(t,t+MAX_N,INF);
    t[s] = 0;
    fill(vis,vis+MAX_N,false);
    fill(NodesNum,NodesNum+MAX_N,INF);
    NodesNum[s] = 1;
    for(int i=0;i<N;i++) pre[i] = i;
    
    for(int i=0;i<N;i++){
        int u=-1, MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && t[j] < MIN){
                u = j;
                MIN = t[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v<N;v++){
            if(vis[v] == false && times[u][v] != INF){
                if(t[u] + times[u][v] < t[v]){
                    t[v] = t[u] + times[u][v];
                    NodesNum[v] = NodesNum[u] + 1;
                    pre[v] = u;
                }else if(t[u] + times[u][v] == t[v] && NodesNum[u] + 1 < NodesNum[v]){
                    NodesNum[v] = NodesNum[u] + 1;
                    pre[v] = u;
                }
            }
        }
    }
}

void DFS(int s, int v, int pre[]){
    if(v == s){
        printf("%d -> ",v);
        return;
    }
    DFS(s, pre[v], pre);
    printf("%d",v);
    if(v != eend) printf(" -> ");
}

int main(){
    fill(G[0],G[0]+MAX_N*MAX_N, INF);
    fill(times[0], times[0]+MAX_N*MAX_N, INF);

    cin>>N>>M;

    int v1, v2, oneway, length, time;
    for(int i=0;i<M;i++){
        cin>>v1>>v2>>oneway>>length>>time;
        if(oneway == 0){
            G[v2][v1] = length;
            times[v2][v1] = time;
        }
        G[v1][v2] = length;
        times[v1][v2] = time;
    }
    cin>>bbegin>>eend;

    Dijkstra1(bbegin);
    int ans1Dis = d[eend];
    int ans1Pre[MAX_N];
    copy(begin(pre),end(pre),begin(ans1Pre));

    Dijkstra2(bbegin);
    int ans2Time = t[eend];
    int ans2Pre[MAX_N];
    copy(begin(pre),end(pre),begin(ans2Pre));
    
    bool isSame = true;
    for(int i=0;i<N;i++){
        if(ans1Pre[i] != ans2Pre[i]){
            isSame = false;
            break;
        }
    }
    
    if(isSame){
        printf("Distance = %d; Time = %d: ",ans1Dis, ans2Time);
        DFS(bbegin, eend, ans1Pre);
    }else{
        printf("Distance = %d: ",ans1Dis);
        DFS(bbegin, eend, ans1Pre);
        printf("\n");
        printf("Time = %d: ",ans2Time);
        DFS(bbegin, eend, ans2Pre);
    }

    return 0;
}

/*
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5

Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5


7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Distance = 3; Time = 4: 3 -> 2 -> 5
*/