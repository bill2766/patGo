#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 1020;
const int INF = 1000000000;

int N, M, K, Ds;
int G[MAX_N][MAX_N];

int posToInt(string gas){
    if(gas[0] != 'G'){
        return stoi(gas);
    }else{
        return N + stoi(gas.substr(1));
    }
}

int d[MAX_N];
bool vis[MAX_N];

int tempGasLoc;
double tempMinDisMax, tempAvgDis;

int resGasLoc;
double resMinDisMax, resAvgDis;

int main(){
    fill(G[0], G[0]+MAX_N*MAX_N, INF);
    for(int i=0; i<MAX_N; i++) G[i][i] = 0;
    
    scanf("%d %d %d %d", &N, &M, &K, &Ds);
    string p1, p2;
    int dist;
    int p1Int, p2Int;
    for(int i=0;i<K;i++){
        cin>>p1>>p2>>dist;
        p1Int = posToInt(p1); 
        p2Int = posToInt(p2);
        G[p1Int][p2Int] = G[p2Int][p1Int] = min(G[p1Int][p2Int], dist);
    }

    resGasLoc = -1;
    resMinDisMax = -1;
    resAvgDis = INF;
    for(int index=N+1;index<=N+M;index++){
        tempMinDisMax = INF;
        tempAvgDis = 0;
        fill(d,d+MAX_N,INF);
        d[index] = 0;
        fill(vis,vis+MAX_N,false);
        
        
        for(int i=0;i<N+M;i++){
            int u = -1, MIN = INF;
            for(int j=1; j<=N+M; j++){
                if(vis[j] == false && d[j] < MIN){
                    u = j;
                    MIN = d[j];
                }
            }
            if(u == -1) break;
            vis[u] = true;

            for(int v=1; v<=N+M; v++){
                if(vis[v]==false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                }
            }
        }

        for(int i=1;i<=N;i++){
            if(d[i] <= Ds){
                tempAvgDis += 1.0 * d[i];
                if(d[i] < tempMinDisMax) tempMinDisMax = d[i];
            }else{
                tempMinDisMax = -1;
                break;
            }
        }
        if(tempMinDisMax == -1) continue;
        tempAvgDis = tempAvgDis / N;
        if(tempMinDisMax > resMinDisMax){
            resGasLoc = index;
            resMinDisMax = tempMinDisMax;
            resAvgDis = tempAvgDis;
        }else if(tempMinDisMax == resMinDisMax && tempAvgDis < resAvgDis){
            resGasLoc = index;
            resAvgDis = tempAvgDis;
        }
    }

    if(resGasLoc == -1){
        printf("No Solution");
    }else{
        printf("G%d\n%0.1f %0.1f",resGasLoc - N,resMinDisMax,resAvgDis);
    }

    return 0;
}

/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

G1
2.0 3.3


2 1 2 10
1 G1 9
2 G1 20

No Solution
*/