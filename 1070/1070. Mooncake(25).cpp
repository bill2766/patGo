#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    float amount; //需要是float，不然过不了第2个测试点
    float price;
    float rate;
};

int n;
int demand;

bool cmp(Node a, Node b){
    return a.rate > b.rate;
}

vector<Node> market;

float maxProfit = 0.0;

int main(){
    cin>>n>>demand;
    market.resize(n+1);

    for(int i=0;i<n;i++){
        scanf("%f",&market[i].amount);
    }
    for(int i=0;i<n;i++){
        scanf("%f",&market[i].price);
        market[i].rate = market[i].price / market[i].amount;
    }

    sort(market.begin(),market.end(),cmp);

    for(int i=0;i<market.size();i++){
        if(demand >= market[i].amount){
            demand -= market[i].amount;
            maxProfit += market[i].price;
            if(demand == 0){
                break;
            }
        }else{
            maxProfit += (demand * market[i].rate);
            break;
        }
    }

    printf("%.2f",maxProfit);
    
    return 0;
}

/*
3 200
180 150 100
7.5 7.2 4.5

9.45
*/