#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string str;
string res;

int main(){
    scanf("%d\n",&n);

    string temp;
    getline(cin,res);
    for(int i=1;i<n;i++){
        getline(cin,str);

        int aInd = str.length()-1;
        int bInd = res.length()-1;
        while(aInd>=0 && bInd>=0 && str[aInd] == res[bInd]){
            temp += str[aInd];
            aInd--;
            bInd--;
        }
        reverse(temp.begin(),temp.end());
        res = temp;
        temp = "";
    }

    if(res.length() != 0){
        cout<<res;
    }else{
        cout<<"nai";
    }
    

    return 0;
}

/*
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

nyan~


3
Itai!
Ninjinnwaiyada T_T
T_T

nai
*/