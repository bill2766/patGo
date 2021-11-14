#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 1010;

int N, M;
vector<int> adj[MAX_N];
int in[MAX_N];

int K;

vector<int> res;
void isTopoOrder(int aInd, int quesArr[]){
    //temp in，暂时的in数组
    vector<int> tin(in, in+N+1);
    for(int i=0;i<N;i++){
        if(tin[ quesArr[i] ] == 0){
            int u = quesArr[i];
            for(int j=0; j<adj[u].size(); j++){
                int v = adj[u][j];
                tin[v]--;
            }
        }else{
            res.push_back(aInd);
            return;
        }
    }
}

int main(){
    cin>>N>>M;
    
    int start, end;
    for(int i=0;i<M;i++){
        cin>>start>>end;
        adj[start].push_back(end);
        in[end]++;
    }

    cin>>K;
    for(int i=0;i<K;i++){
        int quesArr[N];
        for(int j=0;j<N;j++){
            cin>>quesArr[j];
        }
        isTopoOrder(i, quesArr);
    }

    for(int i=0;i<res.size();i++){
        printf("%d",res[i]);
        if(i != res.size()-1) printf(" ");
    }

    return 0;
}

/*
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
6
5 2 3 6 4 1
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6

0 4 5
*/