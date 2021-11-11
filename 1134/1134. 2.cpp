#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int K;

int main(){
    cin>>N>>M;
    vector<int> vertex[N];
    int v1, v2;
    for(int i=0;i<M;i++){
        cin>>v1>>v2;
        vertex[v1].push_back(i);
        vertex[v2].push_back(i);
    }

    cin>>K;
    for(int i=0;i<K;i++){
        int vNumber;
        int curV;
        int hash[M];
        fill(hash,hash+M,0);

        cin>>vNumber;
        for(int j=0;j<vNumber;j++){
            cin>>curV;
            for(int edInd=0;edInd<vertex[curV].size();edInd++){
                hash[vertex[curV][edInd]] = 1;
            }
        }

        bool flag = false;
        for(int edInd=0;edInd<M;edInd++){
            if(hash[edInd] == 0){
                printf("No\n");
                flag = true;
                break;
            }
        }
        if(!flag) printf("Yes\n");
    }

    return 0;
}