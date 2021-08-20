#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100;

struct node{
    int layer;
    vector<int> child;
}nodes[101];

int N, M;
//每一层叶子结点数目
int layers[maxn] = {0};
int maxLayer = 0;

void BFS(int s){
    queue<int> q;
    q.push(s);
    nodes[s].layer = 0;

    while(!q.empty()){
        int n = q.front();
        q.pop();

        //如果它是叶子结点，则当前所在layer的叶子结点数目++
        if(nodes[n].child.size() == 0){
            layers[nodes[n].layer] += 1;
        }

        //记录每个点的layer
        for(int i=0;i<nodes[n].child.size(); i++){
            int child = nodes[n].child[i];
            q.push(child);
            nodes[child].layer = nodes[n].layer + 1;

            //更新最大层数
            // if(nodes[child].layer > maxLayer){
            //     maxLayer = nodes[child].layer;
            // }
            //使用max函数
            maxLayer = max(maxLayer,nodes[child].layer);
        }
    }

    for(int i=0; i<=maxLayer; i++){
        printf("%d",layers[i]);
        if(i != maxLayer){
            printf(" ");
        }
    }
}


int main(){
    scanf("%d%d",&N,&M);

    int id, childNum, childId;
    for(int i=0; i<M; i++){
        scanf("%d %d",&id,&childNum);
        for(int j=0; j<childNum; j++){
            scanf("%d",&childId);
            nodes[id].child.push_back(childId);
        }
    }

    BFS(01);

    return 0;
}

/*
2 1
01 1 02
*/

//0 1