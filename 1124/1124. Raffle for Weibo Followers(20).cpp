#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> res;

bool haveIn(string str){
    for(int i=0;i<res.size();i++){
        if(res[i] == str){
            return true;
        }
    }
    return false;
}

int main(){
    //转发总数、中奖者跳过数和第一个赢家的索引
    int m,n,s;
    cin>>m>>n>>s;

    string str;
    int count=0;
    for(int i=1;i<=m;i++){
        cin>>str;
        if(i == s){
            res.push_back(str);
        }
        if(i > s){
            count++;
            if(count == n){
                if(!haveIn(str)){
                    res.push_back(str);
                    count = 0;
                }else{
                    count--;
                }
            }
        }
    }

    if(!res.empty()){
        for(int i=0;i<res.size();i++){
            cout<<res[i];
            if(i != res.size()-1){
                cout<<endl;
            }
        }
    }else{
        printf("Keep going...");
    }
    return 0;
}

/*
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain

PickMe
Imgonnawin!
TryAgainAgain


2 3 5
Imgonnawin!
PickMe

Keep going...
*/