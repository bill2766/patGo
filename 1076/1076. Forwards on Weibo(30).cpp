#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1010;

int n,l;

struct Node{
    int layer;
    //follows表示的是a被b关注，“被关注”
    vector<int> follows;
}peos[MAX_N];

int getForward(int peoId){
    int out = 0;
    bool visited[MAX_N] = {false};
    //设置peoId为true：如果碰到它被关注了，也不让它进入队列
    visited[peoId] = true;

    queue<int> q;
    q.push(peoId);
    peos[peoId].layer = 0;

    int peo;
    while(q.size() != 0){
        peo=q.front();
        //达到layer了（已经计入out），退出循环
        if(peos[peo].layer == l){
            break;
        }
        q.pop();
        for(int i=0;i<peos[peo].follows.size();i++){
            int follow = peos[peo].follows[i];
            if(visited[follow] == false){
                //新的follow加入队尾，并设置层数
                q.push(follow);
                peos[follow].layer = peos[peo].layer+1;
                visited[follow] = true;
                out++;
            }
        }
    }
    return out;
}

int main(){
    scanf("%d %d",&n,&l);

    int num;
    int peoId;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&peoId);
            peos[peoId].follows.push_back(i);
        }
    }

    vector<int> res;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>peoId;
        res.push_back(getForward(peoId));
    }

    for(int i=0;i<res.size();i++){
        printf("%d",res[i]);
        if(i != res.size()-1){
            printf("\n");
        }
    }

    return 0;
}

/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6

4
5
*/