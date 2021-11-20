#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N  = 510;
const int INF = 1000000000;

int Cmax, N, Sp, M;
int G[MAX_N][MAX_N];
int bikeNums[MAX_N];

int d[MAX_N];
bool vis[MAX_N];
vector<int> pre[MAX_N];

void Dijkstra(int s){
    fill(d,d+MAX_N,INF);
    fill(vis,vis+MAX_N,false);
    d[s] = 0;

    for(int i=0;i<N+1;i++){
        int u=-1, MIN = INF;
        for(int j=0;j<N+1;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int v=0; v<=N; v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }else if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] == d[v]){
                pre[v].push_back(u);
            }
        }
    }
}

vector<int> ansPath;
int ansBNum;
int ansBRet;

vector<int> tempPath;
void DFS(int s, int v){
    tempPath.push_back(v);
    if(v == s){
        int tempBNum = 0;
        //顺路带的自行车
        int inTheWay = 0;
        for(int i=tempPath.size()-2; i>=0; i--){
            int ind = tempPath[i];
            if(bikeNums[ind] < Cmax/2){
                if(inTheWay >= Cmax/2 - bikeNums[ind]){
                    inTheWay -= (Cmax/2-bikeNums[ind]);
                }else{
                    tempBNum += (Cmax/2 - bikeNums[ind] - inTheWay);
                    inTheWay = 0;
                }
            }else if(bikeNums[ind] > Cmax/2){
                inTheWay += bikeNums[ind] - Cmax/2;
            }else{
                continue;
            }
        }

        if(tempBNum < ansBNum){
            ansBNum = tempBNum;
            ansBRet = inTheWay;
            ansPath = tempPath;
        }else if(tempBNum == ansBNum && inTheWay < ansBRet){
            ansBRet = inTheWay;
            ansPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i=0;i<pre[v].size();i++){
        DFS(s, pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    fill(G[0],G[0]+MAX_N*MAX_N,INF);
    cin>>Cmax>>N>>Sp>>M;
    for(int i=0;i<N+1;i++) G[i][i] = 0;
    for(int i=1;i<=N;i++) cin>>bikeNums[i];

    int Si,Sj, Tij;
    for(int i=0;i<M;i++){
        cin>>Si>>Sj>>Tij;
        G[Si][Sj] = G[Sj][Si] = Tij;
    }

    Dijkstra(0);

    ansBNum = INF;
    DFS(0, Sp);

    cout<<ansBNum<<" ";
    for(int i=ansPath.size()-1;i>=0;i--){
        printf("%d",ansPath[i]);
        if(i != 0){
            printf("->");
        }else{
            printf(" ");
        }
    }
    cout<<ansBRet;

    return 0;
}

/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

3 0->2->3 0
*/