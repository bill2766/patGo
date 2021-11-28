#include <iostream>
#include <string>
#include <map>
using namespace std;



int main(){
    string a, b;
    cin>>a>>b;
    
    map<char, int> res;
    int resNum = 0;
    char out[81];

    int aInd = 0, bInd = 0;
    while(aInd < a.length()){
        if(toupper(a[aInd]) == toupper(b[bInd])){
            aInd++;
            bInd++;
        }else{
            if(res.find( toupper(a[aInd]) ) == res.end()){
                res[ toupper(a[aInd]) ] = resNum;
                out[resNum] = toupper(a[aInd]);
                resNum++;
            }
            aInd++;
        }
    }

    for(int i=0; i<resNum; i++){
        printf("%c", out[i]);
    }

    return 0;
}


/*
7_This_is_a_test
_hs_s_a_es

7TI
*/