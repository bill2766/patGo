#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 101;

int N;
struct peo{
    string id;
    int grade;
    int group;
    int final_rank;
    int local_rank;
    peo(string id,int grade,int group):id(id),grade(grade),group(group),final_rank(0),local_rank(0){}
    peo(){}
};
vector<peo> peos;

bool cmp1(peo a, peo b){
    if(a.group != b.group){
        return a.group < b.group;
    }else{
        return a.grade > b.grade;
    }
}

bool cmp2(peo a, peo b){
    if(a.grade != b.grade){
        return a.grade > b.grade;
    }else{
        return a.id < b.id;
    }
}

int main(){
    cin>>N;
    int K;
    string id;
    int grade;
    for(int i=1;i<=N;i++){
        cin>>K;
        for(int j=0;j<K;j++){
            cin>>id>>grade;
            peos.push_back(peo(id,grade,i));
        }
    }

    sort(peos.begin(), peos.end(), cmp1);

    int count, rank;
    for(int i=0;i<peos.size();i++){
        if(i==0 || peos[i].group != peos[i-1].group){
            count = 1;
            rank = 1;
        }else{
            count++;
            if(peos[i].grade < peos[i-1].grade){
                rank = count;
            }
        }
        peos[i].local_rank = rank;
    }

    sort(peos.begin(), peos.end(), cmp2);
    for(int i=0;i<peos.size();i++){
        if(i==0){
            peos[i].final_rank = 1;
        }else{
            if(peos[i].grade < peos[i-1].grade){
                peos[i].final_rank = i+1;
            }else{
                peos[i].final_rank = peos[i-1].final_rank;
            }
        }
    }

    cout<<peos.size()<<endl;
    for(int i=0;i<peos.size();i++){
        cout<<peos[i].id<<" "<<peos[i].final_rank<<" "<<peos[i].group<<" "<<peos[i].local_rank<<endl;
    }

    return 0;
}

/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/