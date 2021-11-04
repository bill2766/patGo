#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N,K;

struct peo
{
    string name;
    int age;
    int net_worth;
    peo(){}
};
vector<peo> peos;

bool cmp1(peo a, peo b){
    if(a.net_worth != b.net_worth){
        return a.net_worth > b.net_worth;
    }else if(a.age != b.age){
        return a.age < b.age;
    }else{
        return a.name < b.name;
    }
}

int main(){
    scanf("%d%d\n",&N,&K);
    peos.resize(N);
    for(int i=0;i<N;i++){
        cin>>peos[i].name>>peos[i].age>>peos[i].net_worth;
    }
    sort(peos.begin(),peos.end(),cmp1);

    int count;
    int searchNum;
    int amin, amax;
    for(int i=1;i<=K;i++){
        printf("Case #%d:\n",i);
        count = 0;
        cin>>searchNum>>amin>>amax;
        for(int j=0;j<N;j++){
            if(count >= searchNum) break;
            if(peos[j].age >= amin && peos[j].age <= amax){
                cout<<peos[j].name<<" "<<peos[j].age<<" "<<peos[j].net_worth<<endl;
                count++;
            }
        }
        if(count == 0) printf("None\n");
    }

    return 0;
}

/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50

Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/