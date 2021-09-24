#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define maxK 1001
#define maxN 20
#define maxM 10

struct Window{
    queue<int> q;
    int popTime;
}windows[maxN];

//每位客户的花费时间
int cost[maxK];

int finished[maxK];
int n, m, k, q;

// 填满黄线前的位置
int fillWindow(){
    int id = 1;
    //先按窗口数，轮一遍。是为了更新popTime
    for(int j = 0; j < n; j++){
        //第一位客户需要的时间：popTime
        windows[j].popTime = cost[id];
        //客户加入队列
        windows[j].q.push(id);
        //如果客户都在黄线内，那么直接返回
        if(++id > k) return id;
    }

    //再轮一遍，直到窗口内填满 或 人都在黄线内
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n; j++){
            windows[j].q.push(id);
            //如果客户都在黄线内，那么直接返回
            if(++id > k) return id;
        }
    }
    //return id是为了返回刚好没在黄线内的人
    return id;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);

    for(int i = 1; i <= k; i++){
        scanf("%d", &cost[i]);
    }

    // 初始化完成时间， -1代表无法完成业务
    fill(finished, finished + maxK, -1);

    int id = fillWindow();

    // 模拟
    for(int t = 0; t < 540; t++){ //8:00～17:00。共9小时 = 540分钟
        for(int i = 0; i < n; i++){
            //这个客户如果还没到popTime，跳过
            if(windows[i].popTime != t) continue;
            //否则到达了服务完这位客户的时间，记录完成时间（完成的分钟，没有加8小时）
            // 出列， 记录完成时间
            finished[windows[i].q.front()] = t;
            windows[i].q.pop();
            
            if(windows[i].q.size() > 0){
                // 更新出列时间
                windows[i].popTime = t + cost[windows[i].q.front()];
            }
            //如果id到达了k，那没有人在黄线外了
            if(id > k) continue;
            
            // 空出空位， 黄线外的客户进去一个
            windows[i].q.push(id);
            id++;
        }
    }
    
    //如果超过17:00，如果还有客户，去服务完他们
    // 完成每个窗口当前服务的客户（如果有的话）
    for(int i = 0; i < n; i++){
        if(windows[i].q.size() < 1) continue;
        finished[windows[i].q.front()] = windows[i].popTime;
    }
    
    //打印结果
    int query, timestamp;
    for(int i = 0; i < q; i++){
        scanf("%d", &query);
        timestamp = finished[query];
        if(timestamp == -1){
            printf("Sorry\n");
            continue;
        }
        printf("%02d:%02d\n", timestamp / 60 + 8, timestamp % 60);
    }
    return 0;
}
