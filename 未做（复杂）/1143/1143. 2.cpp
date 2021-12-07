#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 10010;

int M, N;
map<int, bool> hasNode;

int pre[MAX_N];

int main(){
    
    scanf("%d %d",&M, &N);
    for(int i=0;i<N;i++){
        scanf("%d",&pre[i]);
        hasNode[pre[i]] = true;
    }

    int u, v;
    int res;
    for(int i=0;i<M;i++){
        scanf("%d %d",&u, &v);

        for(int j=0;j<N;j++){
            if( (u <= pre[j] && v >= pre[j]) || (u >= pre[j] && v <= pre[j]) ){
                res = pre[j];
                break;
            }
        }

        if(hasNode[u] == false && hasNode[v] == false){
            printf("ERROR: %d and %d are not found.\n",u,v);
        }else if(hasNode[u] == true && hasNode[v] == false){
            printf("ERROR: %d is not found.\n",v);
        }else if(hasNode[u] == false && hasNode[v] == true){
            printf("ERROR: %d is not found.\n",u);
        }else{
            if(res == u){
                printf("%d is an ancestor of %d.\n",u,v);
            }else if(res == v){
                printf("%d is an ancestor of %d.\n",v,u);
            }else{
                printf("LCA of %d and %d is %d.\n",u,v,res);
            }
        }
    }

    return 0;
}