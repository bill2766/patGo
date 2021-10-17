#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 1010;

int n;
string account;
string password;

int n2 = 0;
vector<string> resAcc;
vector<string> resPass;

map<char,char> ddict;

string newPass(string str){
    string out = "";
    for(string::iterator it=str.begin();it!=str.end();it++){
        if(ddict.find(*it) == ddict.end()){
            out += *it;
        }else{
            out += ddict[*it];
        }
    }
    return out;
}

int main(){
    ddict['1'] = '@';
    ddict['0'] = '%';
    ddict['l'] = 'L';
    ddict['O'] = 'o';

    cin>>n;
    string nowPass;
    for(int i=0;i<n;i++){
        cin>>account>>password;
        nowPass = newPass(password);
        if(password != nowPass){
            n2++;
            resAcc.push_back(account);
            resPass.push_back(nowPass);
        }
    }

    if(n2 == 0){
        if(n == 1){
            printf("There is %d account and no account is modified",n);
        }else{
            printf("There are %d accounts and no account is modified",n);
        }
    }else{
        printf("%d\n",n2);
        for(int i=0;i<n2;i++){
            cout<<resAcc[i]<<" "<<resPass[i];
            if(i != n2-1){
                cout<<endl;
            }
        }
    }

    return 0;
}

/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

2
Team000002 RLsp%dfa
Team000001 R@spodfa


1
team110 abcdefg332

There is 1 account and no account is modified


2
team110 abcdefg222
team220 abcdefg333

There are 2 accounts and no account is modified
*/