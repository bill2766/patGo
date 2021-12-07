/////////////////////////////////////
//26分
/////////////////////////////////////

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_M = 110;

struct Pair{
    int arriveTime;
    int playTime;
    int isVip;

    int serveTime;
    Pair():serveTime(-1){}
};
vector<Pair> pairs;
int N, K, M; 

struct Desk{
    int finishTime;
    bool isVipDesk;
    int count;
    Desk():finishTime(0), isVipDesk(false),count(0){}
};
vector<Desk> desks;

bool cmp1(Pair a, Pair b){
    return a.arriveTime < b.arriveTime;
}

bool cmp2(Pair a, Pair b){
    return a.serveTime < b.serveTime;
}

int main(){
    cin>>N;
    pairs.resize(N);
    int hour, minu, sec, playTimeMin, isVip;
    for(int i=0; i<N; i++){
        scanf("%d:%d:%d %d %d", &hour, &minu, &sec, &playTimeMin, &isVip);
        int arriveTime = hour * 60 * 60 + minu * 60 + sec - 8*60*60;
        pairs[i].arriveTime = arriveTime;
        pairs[i].playTime = (playTimeMin <= 120 ? playTimeMin * 60: 120 * 60);
        pairs[i].isVip = isVip;
    }

    sort(pairs.begin(), pairs.end(), cmp1);

    cin>>K>>M;
    desks.resize(K+1);
    for(int i=0; i<M; i++){
        int temp;
        cin>>temp;
        desks[temp].isVipDesk = true;
    }

    for(int t = 0; t< 13*60*60; t++){
        for(int i=1; i<=K; i++){
            //如果有桌子
            if(desks[i].finishTime <= t){
                //如果是普通桌子
                if(desks[i].isVipDesk == 0){
                    //如果有客户
                    int pInd;
                    for(pInd=0; pInd<N; pInd++){
                        if(pairs[pInd].arriveTime > t){
                            pInd = -1;
                            break;
                        }else{
                            if(pairs[pInd].serveTime == -1){
                                //未玩过
                                break;
                            }else{
                                //玩过
                                continue;
                            }
                        }
                    }
                    //找不到人
                    if(pInd == -1 || pInd == N) break;

                    pairs[pInd].serveTime = t;
                    desks[i].finishTime = t + pairs[pInd].playTime;
                    desks[i].count++;
                }else{
                    //如果是vip桌子
                    //先找vip客户
                    int pInd;
                    for(pInd=0; pInd<N; pInd++){
                        if(pairs[pInd].arriveTime > t){
                            pInd = -1;
                            break;
                        }else{
                            if(pairs[pInd].serveTime != -1 || pairs[pInd].isVip == 0){
                                continue;
                            }else{
                                break;
                            }
                        }
                    }
                    //找不到则让普通用户玩
                    if(pInd == -1 || pInd == N){
                        for(pInd=0; pInd<N; pInd++){
                            if(pairs[pInd].arriveTime > t){
                                pInd = -1;
                                break;
                            }else{
                                if(pairs[pInd].serveTime == -1){
                                    //未玩过
                                    break;
                                }else{
                                    //玩过
                                    continue;
                                }
                            }
                        }
                    }
                    //普通用户也找不到
                    if(pInd == -1 || pInd == N) break;

                    pairs[pInd].serveTime = t;
                    desks[i].finishTime = t + pairs[pInd].playTime;
                    desks[i].count++;
                }
            }
        }
    }

    sort(pairs.begin(), pairs.end(), cmp2);

    for(int i=0; i<N; i++){
        if(pairs[i].serveTime != -1){
            int aH, aM, aS, sH, sM, sS, waitTime;
            aH = pairs[i].arriveTime / 3600 + 8;
            aM = pairs[i].arriveTime % 3600 / 60;
            aS = pairs[i].arriveTime % 60;
            sH = pairs[i].serveTime / 3600 + 8;
            sM = pairs[i].serveTime % 3600 / 60;
            sS = pairs[i].serveTime % 60;
            waitTime = round(1.0 * (pairs[i].serveTime - pairs[i].arriveTime) / 60);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",    aH, aM, aS, sH, sM, sS, waitTime);
        }
    }
    for(int i=1;i<=K;i++){
        printf("%d",desks[i].count);
        if(i != K) printf(" ");
    }

    return 0;
}


/*
10
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 30 0
08:12:00 10 1
20:40:00 13 0
08:01:30 15 1
20:53:00 10 1
20:54:00 10 0
3 1
2

08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:40:00 20:40:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
20:53:00 20:53:00 0
4 3 2
*/