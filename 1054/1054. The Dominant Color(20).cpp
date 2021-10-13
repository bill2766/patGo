#include <iostream>
#include <map>
using namespace std;

int m, n;
int res;

map<int,int> ddict;

int main(){
    cin>>m>>n;

    int val;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>val;
            if(ddict.find(val) == ddict.end()){
                ddict[val] = 1;
            }else{
                ddict[val]+=1;
            }
            if(ddict[val] > m * n / 2){
                res = val;
            }
        }
    }

    cout<<res;
    
    return 0;
}

/*
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24

24
*/