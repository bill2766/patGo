#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> res;

int main(){
    string a, b;
    cin>>a>>b;

    for(int i=0; i<b.length(); i++){
        if(res.find(b[i]) == res.end()){
            res[b[i]] = 1;
        }else{
            res[b[i]]++;
        }
    }

    int waste = 0;
    int loss = 0;

    for(int i=0; i<a.length(); i++){
        if(res.find(a[i]) == res.end()){
            waste++;
        }else{
            res[a[i]]--;
            if(res[a[i]] < 0) waste++;
        }
    }

    for(map<char,int>::iterator it = res.begin(); it!=res.end(); it++){
        if(it->second > 0){
            loss+= it->second;
        }
    }

    if(loss == 0){
        cout<<"Yes "<<waste;
    }else{
        cout<<"No "<<loss;
    }

    return 0;
}

/*
ppRYYGrrYBR2258
YrR8RrY

Yes 8


ppRYYGrrYB225
YrR8RrY

No 2
*/