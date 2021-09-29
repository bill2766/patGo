#include <iostream>
#include <string>
using namespace std;


int main(){
    string str;
    cin>>str;
    int len = str.length();

    int result = 0;

    int pnum = 0;
    int tnum = 0;
    int pnums[len];
    int tnums[len];

    for(int i=0; i<len; i++){
        if(str[i] == 'P'){
            pnum += 1;
        }
        if(str[len-i-1] == 'T'){
            tnum += 1;
        }
        pnums[i] = pnum;
        tnums[len-i-1] = tnum;
    }

    for(int i=0; i<len; i++){
        if(str[i] == 'A'){
            result = (result + (pnums[i] * tnums[i]) % 1000000007) % 1000000007;
        }
    }

    cout<<result;

    return 0;
}

/*
APPAPT

2
*/