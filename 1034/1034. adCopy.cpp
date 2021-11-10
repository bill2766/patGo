#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> stringToInt;
map<int, string> intToString;

int idNumber = 1;
int k;

map<string, int> ans;

int stoifunc(string s){
    if(stringToInt[s] == 0){
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    }else{
        return stringToInt[s];
    }
}

int G[2010][2010];
int weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMumber, int &totalweight){
    vis[u] = true;
    numMumber++;
    if(weight[u] > weight[head]){
        head = u;
    }
    for(int v=1; v<idNumber; v++){
        if(G[u][v] > 0){
            totalweight += G[u][v];
            //遍历过一条边之后就把这条边的权值设为0（ G[u][v] = G[v][u] = 0;）防止出现回路遍历死循环
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false){
                dfs(v, head, numMumber, totalweight);
            }
        }
    }
}


void dfsTrave(){
    for(int i=1; i<idNumber; i++){
        if(vis[i] == false){
            //初始化
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k){
                ans[intToString[head]] = numMember;
            }
        }
    }
}

int main(){
    int n;
    cin >>n>>k;
    string s1, s2;
    int w;
    for(int i=0; i<n; i++){
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
    for(map<string,int>::iterator it = ans.begin(); it!=ans.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}