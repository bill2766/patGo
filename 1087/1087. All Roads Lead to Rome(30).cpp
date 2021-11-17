#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 201;
const int INF = 1000000000;

int N, K;

int idNum = 0;
map<string, int> cityToId;
map<int,string> idToCity;

int endId;
struct Node{
    int v; //目标顶点
    int dis; //距离
};
vector<Node> Adj[MAX_N];
int weights[MAX_N];
int d[MAX_N];
bool vis[MAX_N];
vector<int> pre[MAX_N];


int getId(string str){
    if(cityToId.find(str) == cityToId.end()){
        cityToId[str] = idNum;
        idToCity[idNum] = str;
        return idNum++;
    }else{
        return cityToId[str];
    }
}

void Dijkstra(int s){
    fill(d,d+MAX_N,INF);
    d[0] = 0;

    for(int i=0;i<N; i++){
        int u=-1, MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;

        for(int j=0; j<Adj[u].size(); j++){
            int v = Adj[u][j].v;
            if(vis[v] == false && Adj[u][j].dis != INF && d[u] + Adj[u][j].dis < d[v]){
                d[v] = d[u] + Adj[u][j].dis;
                pre[v].clear();
                pre[v].push_back(u);
            }else if(d[u] + Adj[u][j].dis == d[v]){
                pre[v].push_back(u);
            }
        }
    }
}

vector<int> tempPath;
vector<int> ansPath;
int ansPathNum = 0;
int ansWeight = 0, ansAveWeight = 0;

void DFS(int v){
    tempPath.push_back(v);
    if(v == 0){
        int weight = 0;
        int avgWeight = 0;
        for(int i=0;i<tempPath.size();i++){
            weight += weights[tempPath[i]];
        }
        avgWeight = 1.0 * weight / (tempPath.size()-1);
        if(weight > ansWeight){
            ansPath = tempPath;
            ansWeight = weight;
            ansAveWeight = avgWeight;
        }else if(weight == ansWeight && ansAveWeight < avgWeight){
            ansPath = tempPath;
            ansAveWeight = avgWeight;
        }
        tempPath.pop_back();
        ansPathNum++;
        return;
    }
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    string sCity;
    cin>>N>>K>>sCity;

    getId(sCity);
    string cityStr;
    int weight;
    for(int i=0;i<N-1;i++){
        cin>>cityStr>>weight;
        int nowId = getId(cityStr);
        weights[nowId] = weight;
    }
    endId = cityToId["ROM"];

    string fCity, tCity;
    int dis;
    for(int i=0;i<K;i++){
        cin>>fCity>>tCity>>dis;
        Node node;

        node.v = getId(tCity);
        node.dis = dis;
        Adj[getId(fCity)].push_back(node);

        node.v = getId(fCity);
        node.dis = dis;
        Adj[getId(tCity)].push_back(node);
    }

    Dijkstra(0);

    DFS(endId);
    printf("%d %d %d %d\n",ansPathNum, d[endId], ansWeight, ansAveWeight);
    for(int i=ansPath.size()-1; i>=0; i--){
        cout<<idToCity[ansPath[i]];
        if(i != 0) cout<<"->";
    }

    return 0;
}

/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

3 3 195 97
HZH->PRS->ROM
*/