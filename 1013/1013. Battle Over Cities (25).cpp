#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXV = 1010;

int N, M, K;

bool G[MAXV][MAXV];
int checkCity[MAXV];

bool vis[MAXV] = {false};

void geneOneArea(int node, int cToDel){
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=1; v<=N; v++){
            if(G[u][v] == true && vis[v] == false && v!=cToDel){
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int getAreaNum(int cToDel){
    int areaNum = 0;
    for(int i=1; i<=N; i++){
        if(vis[i] == false && i != cToDel){
            geneOneArea(i, cToDel);
            areaNum++;
        }
    }
    return areaNum;
}

void printHighways(){
    for(int i=0; i<K; i++){
        //checkCity[i]，忽略这个城市
        int areaNum = getAreaNum(checkCity[i]);
        printf("%d\n",areaNum-1);

        fill(vis,vis+MAXV,false);
    }
}

int main(){
    fill(G[0], G[0]+MAXV*MAXV, false);

    scanf("%d%d%d",&N,&M,&K);

    int c1, c2;
    for(int i=0; i<M; i++){
        scanf("%d%d",&c1,&c2);
        G[c1][c2] = true;
        G[c2][c1] = true;
    }

    for(int i=0; i<K; i++){
        scanf("%d",&checkCity[i]);
    }

    printHighways();
    return 0;
}


/*
3 2 3
1 2
1 3
1 2 3
*/

/*
1
0
0
*/