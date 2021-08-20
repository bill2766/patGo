#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Peo{
    string id;
    int inH;
    int inM;
    int inS;

    int outH;
    int outM;
    int outS;
};

vector<Peo> peos;

bool cmp(Peo a, Peo b){
    if(a.inH != b.inH){
        return a.inH < b.inH;
    }else if(a.inM != b.inH){
        return a.inM < b.inM;
    }else{
        return a.inS < b.inS;
    }
}

bool cmp2(Peo a, Peo b){
    if(a.outH != b.outH){
        return a.outH > b.outH;
    }else if(a.outM != b.outM){
        return a.outM > b.outM;
    }else{
        return a.outS > b.outS;
    }
}

int main(){
    int peoNum;
    scanf("%d",&peoNum);

    for(int i=0; i<peoNum; i++){
        Peo p;   
        cin>>p.id;
        scanf("%d:%d:%d %d:%d:%d",&p.inH,&p.inM,&p.inS,&p.outH,&p.outM,&p.outS);
        peos.push_back(p);
    }

    int earlier, later;
    sort(peos.begin(),peos.end(),cmp);
    cout<<peos.front().id<<" ";

    sort(peos.begin(),peos.end(),cmp2);
    cout<<peos.front().id;

    return 0;
}

/*
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
*/