#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    map<string, vector<int> > res;
    
    cin>>n>>k;

    int cid;
    int stuNum;
    string stu;
    for(int i=0;i<k;i++){
        cin>>cid>>stuNum;
        for(int j=0;j<stuNum;j++){
            cin>>stu;
            res[stu].push_back(cid);
        }
    }

    for(map<string, vector<int> >::iterator it = res.begin();it != res.end();it++){
        sort(it->second.begin(),it->second.end());
    }

    for(int i=0;i<n;i++){
        cin>>stu;
        cout<<stu<<" "<<res[stu].size();
        for(int j=0;j<res[stu].size();j++){
            cout<<" "<<res[stu][j];
        }
        if(i != n-1){
            cout<<endl;
        }
    }

    return 0;
}

/*
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9

ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/