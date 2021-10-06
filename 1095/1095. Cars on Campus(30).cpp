#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAX_N = 10010;

struct record{
    char id[10];
    int time;
    int state;
}records[MAX_N];

int n, k;

bool cmp1(record a, record b){
    if(strcmp(a.id,b.id) != 0){
        return strcmp(a.id,b.id) <= 0;
    }else{
        return a.time <= b.time;
    }
}

bool cmp2(record a, record b){
    return a.time < b.time;
}

int main(){
    scanf("%d %d",&n,&k);
    int hour,min,sec;
    char state[5];
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d %s",records[i].id,&hour,&min,&sec,state);
        records[i].time = hour*60*60 + min*60 + sec;
        if(strcmp(state,"in") == 0){
            records[i].state = 1;
        }else{
            records[i].state = -1;
        }
    }

    sort(records,records+n,cmp1);

    // for(int i=0;i<n;i++){
    //     cout<<records[i].id<<" "<<records[i].time<<" "<<records[i].state<<endl;
    // }

    vector<record> rRecords;
    map<string,int> mapp;
    int maxtime = -1;
    for(int i=0;i<=n-2;i++){
        if(strcmp(records[i].id,records[i+1].id) == 0 && records[i].state == 1 && records[i+1].state == -1){
            //保存正确的record：rRecords
            rRecords.push_back(records[i]);
            rRecords.push_back(records[i+1]);
            //记录id和停留时间
            if(mapp.find(records[i].id) == mapp.end()){
                mapp[records[i].id] = records[i+1].time - records[i].time;
            }else{
                mapp[records[i].id] += (records[i+1].time - records[i].time);
            }
            if(maxtime < mapp[records[i].id]){
                maxtime = mapp[records[i].id];
            }
        }
    }

    sort(rRecords.begin(),rRecords.end(),cmp2);
    
    //记录record时间的车数量
    vector<int> cnt(n);
    for(int i=0;i<rRecords.size();i++){
        if(i == 0){
            cnt[i] = rRecords[i].state;
        }else{
            cnt[i] = cnt[i-1] + rRecords[i].state;
        }
    }

    //获得车的数量
    int temptime = 0;
    int tempindex = 0;
    for(int i=0;i<k;i++){
        scanf("%d:%d:%d",&hour,&min,&sec);
        temptime = hour*60*60 + min*60 + sec;
        int j;
        //找到刚好大于record的时间点之前1个
        for(j=tempindex;j<cnt.size();j++){
            if(temptime >= rRecords[j].time){
                //特殊情况：后面找不到record了
                if(j == cnt.size()-1){
                    printf("%d\n",cnt[j]);
                }
                continue;
            }else{
                printf("%d\n",cnt[j-1]);
                break;
            }
        }
        tempindex = j;
    }

    //获得最长停车
    for(map<string,int>::iterator it=mapp.begin();it!=mapp.end();it++){
        //如果时间等于最长时间
        if(it->second == maxtime){
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d",maxtime/3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}

/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00


1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/