#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string ge[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string up[13] = {"#","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> geB;
map<string, int> upB;

string eTom(string str){
    int val = stoi(str);
    if(val % 13 != 0 && val / 13 != 0){
        return up[val/13]+" "+ge[val%13];
    }
    if(val % 13 != 0 && val / 13 == 0){
        return ge[val%13];
    }
    if(val % 13 == 0 && val / 13 != 0){
        return up[val/13];
    }
    return "tret";
}

string mToe(string str){
    if(str.find(" ") != -1){
        string s1 = str.substr(0,str.find(" "));
        string s2 = str.substr(str.find(" ")+1);
        return to_string(upB[s1]*13 + geB[s2]);
    }else{
        if(upB.find(str) != upB.end()){
            return to_string(upB[str]*13);
        }else{
            return to_string(geB[str]);
        }
        
    }
}

int main(){
    geB["tret"] = 0;
    for(int i=1; i<=12; i++){
        geB[ge[i]] = i;
        upB[up[i]] = i;
    }

    int n;
    scanf("%d\n",&n);

    string temp;
    for(int i=0; i<n; i++){
        getline(cin, temp);
        if(temp[0] >= '0' && temp[0] <= '9'){
            cout<<eTom(temp)<<endl;
        }else{
            cout<<mToe(temp)<<endl;
        }
    }

    return 0;
}

/*
4
29
5
elo nov
tam

hel mar
may
115
13
*/