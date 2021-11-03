#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct peo{
    long long int id;
    int cai;
    int de;
    int total;
    peo(long long int id, int cai, int de, int total):id(id),cai(cai),de(de),total(total){}
    peo(){}
};
int N, L, H;
int num = 0;
vector<peo> peos[4];

bool cmp1(peo a, peo b){
    if(a.total != b.total){
        return a.total > b.total;
    }else if(a.de != b.de){
        return a.de > b.de;
    }else{
        return a.id < b.id;
    }
}

int main(){
    cin>>N>>L>>H;
    long long int id;
    int cai, de;
    int toAddGroup;
    for(int i=0;i<N;i++){
        cin>>id>>de>>cai;
        if(de >= H && cai >= H){
            toAddGroup = 0;
        }else if(cai >= L && cai < H && de >= H){
            toAddGroup = 1;
        }else if(cai >= L && cai < H && de >= L && de < H && de >= cai){
            toAddGroup = 2;
        }else if(cai >= L && de >= L){
            toAddGroup = 3;
        }else{
            toAddGroup = -1;
        }
        if(toAddGroup != -1){
            peos[toAddGroup].push_back(peo(id,cai,de,cai+de));
            num++;
        }
    }

    for(int i=0;i<=3;i++){
        sort(peos[i].begin(),peos[i].end(),cmp1);
    }

    cout<<num<<endl;
    for(int i=0;i<=3;i++){
        for(int j=0;j<peos[i].size();j++){
            cout<<peos[i][j].id<<" "<<peos[i][j].de<<" "<<peos[i][j].cai<<endl;
        }
    }

    return 0;
}

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60


12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/