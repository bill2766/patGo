#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxN = 20;
const int maxK = 1001;
const int maxM = 10;

int n, m, k, q;

struct window{
    queue<int> q;
    int popTime;
}windows[maxN];

int cost[maxK];

int finished[maxK];

int fillWindow(){
    int id = 1;
    //第1轮
    for(int i=0;i<n;i++){
        windows[i].q.push(id);
        windows[i].popTime = cost[id];
        id++;
        if(id > k){
            return id;
        }
    }
    //后面几轮
    for(int i=1;i<=m-1;i++){
        for(int j=0;j<n;j++){
            windows[j].q.push(id);
            id++;
            if(id > k){
                return id;
            }
        }
    }
    //还有多余的人
    return id;
}

int main(){
    fill(finished,finished + maxK,-1);

    scanf("%d%d%d%d",&n,&m,&k,&q);

    for(int i=1;i<=k;i++){
        scanf("%d",&cost[i]);
    }

    int id = fillWindow();

    for(int time=0 ;time<540 ;time++){
        for(int i=0 ;i<n ;i++){
            if(windows[i].popTime != time){
                continue;
            }
            
            finished[windows[i].q.front()] = time;
            windows[i].q.pop();

            if(windows[i].q.size() > 0){
                windows[i].popTime = time + cost[windows[i].q.front()];
            }

            if(id > k){
                continue;
            }

            windows[i].q.push(id);
            id++;
        }
    }

    //完成剩余的服务
    for(int i=0;i<n;i++){
        if(windows[i].q.size() < 1) continue;
        finished[windows[i].q.front()] = windows[i].popTime;
    }

    //打印
    int custId,timestamp;
    for(int i=0;i<q;i++){
        scanf("%d",&custId);
        timestamp = finished[custId];
        if(timestamp != -1){
            printf("%02d:%02d\n",timestamp/60+8,timestamp % 60);
        }else{
            printf("Sorry\n");
        }
    }

    return 0;
}

/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
*/