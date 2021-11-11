#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 201;

int N, M;
int G[MAX_N][MAX_N];

int K;

bool isUnhindered(int path[], int vNumber){
    for(int i=0;i<vNumber-1;i++){
        int from = path[i];
        int to = path[i+1];
        if(G[from][to] != 1){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>N>>M;

    int v1, v2;
    for(int i=0;i<M;i++){
        cin>>v1>>v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }

    cin>>K;
    for(int i=0;i<K;i++){
        int vNumber;
        map<int, bool> mapp;
        cin>>vNumber;
        int path[vNumber];
        for(int j=0;j<vNumber; j++){
            cin>>path[j];
            mapp[path[j]] = true;
        }

        if(vNumber != N+1 || path[0] != path[vNumber-1]){
            printf("NO\n");
            continue;
        }

        bool flag1 = false;
        for(int j=1;j<=N;j++){
            if(mapp[j] == false){
                flag1 = true;
                break;
            }
        }
        if(flag1){
            printf("NO\n");
            continue;
        }

        if(isUnhindered(path,vNumber)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}

/*
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1

YES
NO
NO
NO
YES
NO
*/