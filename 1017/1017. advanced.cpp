#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define maxK 100
#define maxN 10000

struct Customer{
    int arrive;
    int cost;
} customers[maxN];

struct Window{
    int customerId;
    int popTime;
    Window(int customerId, int popTime) : customerId(customerId), popTime(popTime){};
    friend bool operator < (Window w1, Window w2){return w1.popTime > w2.popTime;}
};

bool cmp1(Customer c1, Customer c2){ return c1.arrive < c2.arrive;}

int main() {
    int n, k, h, m, s, cost, t, count = 0, total = 0;
    int limit = 9 * 60 * 60;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d:%d:%d %d", &h, &m, &s, &cost);
        t = ((h - 8) * 60 + m) * 60 + s;
        if(t > limit) continue;
        customers[count].arrive = t;
        customers[count].cost = cost * 60;
        
        // 累计有效客户数
        count++;
    }
    sort(customers, customers + count, cmp1);
    
    // 使用优先队列来存放窗口对象
    priority_queue<Window> q;
    int id = 0;
    
    // 让每个窗口服务第一位客户
    for(;id < k && id < count; id++){
        int t = customers[id].arrive;
        // 如果早于营业时间，则窗口的popTime为客户的服务时间
        if(t < 0){
            total -= t;
            q.push(Window(id, customers[id].cost));
        }else{
            q.push(Window(id, customers[id].cost + t));
        }
    }
    
    // 接着每个窗口出来一个客户就从队列里再进去一个
    if(k < count){
        while (true) {
            Window next = q.top();
            q.pop();
            int t = next.popTime;
            if(id >= count) break;
            if(customers[id].arrive < t){
                total += t - customers[id].arrive;
                q.push(Window(id, t + customers[id].cost));
            }else{
                q.push(Window(id, customers[id].arrive + customers[id].cost));
            }
            id++;
        }
    }
    
    // 计算平均等待时间
    printf("%.1lf", total / 60. / count);
    return 0;
}
