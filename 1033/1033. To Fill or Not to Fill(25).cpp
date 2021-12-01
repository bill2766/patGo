#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

double Cmax, D, Davg;
int N;
struct station{
    double Pi;
    double Di;
};

bool cmp1(station a, station b){
    return a.Di < b.Di;
}

vector<station> stations;

int main(){
    scanf("%lf %lf %lf %d",&Cmax, &D, &Davg, &N);

    stations.resize(N+1);
    for(int i=0; i<N; i++){
        scanf("%lf %lf", &stations[i].Pi, &stations[i].Di);
    }
    // 将终点作为虚拟加油站
    stations[N].Pi = 0.0;
    stations[N].Di = D;
    // 增加加油站个数
    N++;
    // 按距离排序
    sort(stations.begin(), stations.end(), cmp1);

    // 第一个加油站不在起点，汽车无法启动
    if(stations[0].Di != 0.0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }

    // 初始化满油状态最远距离
    double maxDis = Cmax * Davg;

    int ind = 0;
    double remainGas = 0;
    double fee = 0;

    while(ind < N){
        //从[ind+1, N)开始，选择比当前加油站便宜 或（次一级的选择） 选择可以到达的油费最少的车站
        int toInd = -1;
        double minPrice = 1000000000;
        for(int i=ind+1; i<N; i++){
            //可达
            if(stations[ind].Di + maxDis >= stations[i].Di){
                //如果找到了比当前加油站低的，就直接去吧
                if(stations[i].Pi < stations[ind].Pi){
                    toInd = i;
                    minPrice = stations[i].Pi;
                    break;
                }
                //否则，就找到其中最低的
                if(stations[i].Pi < minPrice){
                    toInd = i;
                    minPrice = stations[i].Pi;
                }
            }
        }
        //如果找不到能到达的加油站，则退出循环
        if(toInd == -1) break;
        // printf("我将要去%d\n",toInd);
        
        double move = stations[toInd].Di-stations[ind].Di;
        //如果要去的加油站油价 低于 目前加油站的油价，则加油至刚刚好
        if(stations[toInd].Pi < stations[ind].Pi){
            //剩余的油 肯定<= 路上需要的油
            //因为剩余油的情况 只有在一段路上“当前”加油站的油价最低的时候油加满才可能出现
            //而找到下一个油价低的加油站已经是那段路 的后面了
            //因此剩余的油肯定用的完
            fee += stations[ind].Pi * (move / Davg - remainGas);
            remainGas = 0;
        //否则加满
        }else{
            fee += stations[ind].Pi * (Cmax-remainGas);
            remainGas = Cmax - move / Davg;
        }
        ind = toInd;
    }

    //如果ind < N-1，则表示失败
    if(ind < N-1){
        printf("The maximum travel distance = %.2lf",stations[ind].Di+maxDis);
    }else{
        printf("%.2lf",fee);
    }

    return 0;
}

/*
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

749.17


50 1300 12 2
7.10 0
7.00 600

The maximum travel distance = 1200.00
*/