#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int MAX_N = 1010;

int rates[25];
int N;

struct node{
    string name;
    int month, day, hour, min;
    int time;
    int state;
}datas[MAX_N];

bool cmp1(node a, node b){
    if(a.name != b.name){
        return a.name < b.name;
    }else{
        return a.time < b.time;
    }
}

map<string, vector<node> > realRecords;

double billFromZero(node call){
    double out = 0;
    //天
    out += rates[24] * 60 * call.day;
    //out
    out += rates[call.hour] * call.min;
    //小时
    for (int i = 0; i < call.hour; i++)
        out += rates[i] * 60;
    return out / 100.0;
}

int main(){
    for(int i=0;i<=23;i++){
        scanf("%d",&rates[i]);
        rates[24] += rates[i];
    }
    scanf("%d\n",&N);
    for(int i=0;i<N;i++){
        cin>>datas[i].name;
        scanf("%d:%d:%d:%d", &datas[i].month, &datas[i].day, &datas[i].hour, &datas[i].min);
        string temp;
        cin>>temp;
        if(temp == "on-line"){
            datas[i].state = 0;
        }else{
            datas[i].state = 1;
        }
        datas[i].time = datas[i].day * 24 * 60 + datas[i].hour * 60 + datas[i].min;
    }

    sort(datas, datas+N, cmp1);
    
    for(int i=1;i<N;i++){
        if(datas[i-1].name == datas[i].name && datas[i-1].state == 0 && datas[i].state == 1){
            realRecords[datas[i].name].push_back(datas[i-1]);
            realRecords[datas[i].name].push_back(datas[i]);
        }
    }

    double total = 0;
    for(map<string,vector<node> >::iterator it = realRecords.begin(); it!= realRecords.end(); it++){
        cout<<it->first;
        printf(" %02d\n",it->second.front().month);
        for(int i=0;i<=it->second.size()-2;i+=2){
            int a1d = it->second[i].day, a1h = it->second[i].hour, a1m = it->second[i].min;
            int a2d = it->second[i+1].day, a2h = it->second[i+1].hour, a2m = it->second[i+1].min;
            printf("%02d:%02d:%02d ",a1d,a1h,a1m);
            printf("%02d:%02d:%02d ",a2d,a2h,a2m);
            printf("%d ",(a2d-a1d) * 24 * 60 + (a2h-a1h) * 60 + (a2m-a1m));
            double cost = billFromZero(it->second[i+1]) - billFromZero(it->second[i]);
            printf("$%.2lf\n",cost);
            total += cost;
        }
        printf("Total amount: $%.2lf\n",total);
        total = 0;
    }

    return 0;
}

/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/