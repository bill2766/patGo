#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAX_PEO = 2010;

int N, K;

map<string, int> stringToInt;
map<int, string> intToString;
int idNumber = 1;

int stoifunc(string str){
    if(stringToInt[str] == 0){
        stringToInt[str] = idNumber;
        intToString[idNumber] = str;
        return idNumber++;
    }else{
        return stringToInt[str];
    }
}

int G[MAX_PEO][MAX_PEO];
//每个人的weight（通话时间）
int weight[MAX_PEO];
bool vis[MAX_PEO];

void dfs(int u, int &head, int &numNumber, int &totalWeight){
    //设置vis为true
    vis[u] = true;
    numNumber++;

    if(weight[u] > weight[head]){
        head = u;
    }
    for(int v=1;v<idNumber; v++){
        //对所有可以链接的brother（弟兄）
        if(G[u][v] != 0){
            totalWeight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false){
                dfs(v, head, numNumber, totalWeight);
            }
        }
    }
}

map<string, int> ans;
void dfsTrave(){
    for(int i=1;i<idNumber;i++){
        int head = i;
        int numNumber = 0;
        int totalWeight = 0;
        dfs(i, head, numNumber, totalWeight);
        if(numNumber > 2 && totalWeight > K){
            ans[ intToString[head] ] = numNumber;
        }
    }
}

int main(){
    cin>>N>>K;

    string s1, s2;
    int w;
    for(int i=0;i<N;i++){
        cin>>s1>>s2>>w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }

    dfsTrave();

    cout<<ans.size()<<endl;
    for(map<string,int>::iterator it= ans.begin(); it!=ans.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}