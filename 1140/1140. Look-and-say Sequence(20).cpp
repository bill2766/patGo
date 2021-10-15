#include <iostream>
#include <string>
using namespace std;

int d,n;
string temp;
string res;

char w;
int ccount;

int main(){
    cin>>d>>n;
    res = to_string(d);
    for(int i=2;i<=n;i++){
        temp = res;
        res = "";
        w = temp[0];
        ccount = 1;
        for(int j=1;j<temp.length();j++){
            if(temp[j] == w){
                ccount++;
            }else{
                res+=(w+to_string(ccount));
                w = temp[j];
                ccount = 1;
            }
        }
        res+=(w+to_string(ccount));
    }

    cout<<res;

    return 0;
}

/*
1 8

1123123111
*/