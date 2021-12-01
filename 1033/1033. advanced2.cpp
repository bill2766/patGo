#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 500
#define INFINTITY 999999

struct Station{
    double D;
    double price;
}stations[500];

bool cmp(Station s1, Station s2){
    return s1.D < s2.D;
}

int main() {
    double C, D, Davg;
    int N;
    scanf("%lf %lf %lf %d", &C, &D, &Davg, &N);

    for(int i = 0; i < N; i++){
        scanf("%lf %lf", &stations[i].price, &stations[i].D);
    }
    // 将终点作为虚拟加油站
    stations[N].price = 0.0;
    stations[N].D = D;
    
    // 增加加油站个数
    N++;
    
    // 按距离排序
    sort(stations, stations + N, cmp);
    
    // 第一个加油站不在起点，汽车无法启动
    if(stations[0].D != 0.0){
        printf("%s", "The maximum travel distance = 0.00");
    }else{
        // 初始化满油状态最远距离
        double MAX = C * Davg;
        
        double gas = 0.0;
        double total = 0.0;
        int i = 0;
        Station *current = &stations[0];
        Station *target = NULL;
        
        // 遍历加油站
        while (i < N) {
            current = &stations[i];
            target = NULL;
            
            // 从下一个加油站开始考虑，所有在可到达范围内的加油站
            i++;
            double fastDist = current->D + MAX;
            while (i < N && stations[i].D <= fastDist) {
                // 找到一个价格更低的加油站， 则将它作为目标
                if(stations[i].price < current->price){
                    target = &stations[i];
                    break;
                }
                
                // 否则持续寻找可达范围内最便宜的加油站
                if(target == NULL || stations[i].price <= target->price){
                    target = &stations[i];
                }
                i++;
            }
            
            // 找不到可到达的加油站， 退出
            if(target == NULL) break;
            
            // 计算需要的汽油和移动距离
            double need = 0.0, move = target->D - current->D;
            if(target->price < current->price){ // 目标加油站价钱比当前的低，则只加到达目的加油站所需油量
                need = max(0.0, move / Davg - gas);
                gas = 0.0;
            }else{// 否则加满汽油
                need = C - gas;
                gas = C - move / Davg;
            }
            total += need * current->price;
            i = (int)(target - stations);
        }
        
        // 不能到达终点，输出最远移动距离
        if(i < N){
            printf("The maximum travel distance = %.2lf", current->D + MAX);
        }else{
            printf("%.2lf", total);
        }
    }
    return 0;
}
