#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nc, np;
vector<int> cPos;
vector<int> cNeg;
vector<int> pPos;
vector<int> pNeg;

bool cmp(int a, int b){
    return a>b;
}

int sum = 0;

int main(){
    cin>>nc;
    int val;
    for(int i=0;i<nc;i++){
        scanf("%d",&val);
        if(val > 0){
            cPos.push_back(val);
        }else{
            cNeg.push_back(val);
        }
    }
    cin>>np;
    for(int i=0;i<np;i++){
        scanf("%d",&val);
        if(val > 0){
            pPos.push_back(val);
        }else{
            pNeg.push_back(val);
        }
    }
    sort(cNeg.begin(),cNeg.end());
    sort(pNeg.begin(),pNeg.end());

    sort(cPos.begin(),cPos.end(),cmp);
    sort(pPos.begin(),pPos.end(),cmp);

    int i = 0;
    while(i != cPos.size() && i != pPos.size()){
        sum += (cPos[i] * pPos[i]);
        i++;
    }
    i = 0;
    while(i != cNeg.size() && i != pNeg.size()){
        sum += (cNeg[i] * pNeg[i]);
        i++;
    }

    cout<<sum;

    return 0;
}

/*
4
1 2 4 -1
4
7 6 -2 -3

43
*/