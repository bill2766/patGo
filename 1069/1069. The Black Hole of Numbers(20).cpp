#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string N;

string to4Str(string str){
    while(str.length() < 4){
        str = "0" + str;
    }
    return str;
}

bool allSame(string str){
    if(str[0]==str[1] && str[1] == str[2] && str[2]==str[3]){
        return true;
    }else{
        return false;
    }
}

bool cmp(int a, int b){
    return a>b;
}
string getBigStr(string str){
    int strInt[4];
    for(int i=0;i<4;i++){
        strInt[i] = int(str[i]);
    }

    sort(strInt,strInt+4,cmp);

    string out;
    for(int i=0;i<4;i++){
        out += strInt[i];
    }
    return out;
}

string getSmallStr(string str){
    int strInt[4];
    for(int i=0;i<4;i++){
        strInt[i] = int(str[i]);
    }

    sort(strInt,strInt+4);

    string out;
    for(int i=0;i<4;i++){
        out += strInt[i];
    }
    return out;
}

int main(){
    cin>>N;
    N = to4Str(N);

    if(allSame(N)){
        cout<<N<<" - "<<N<<" = "<<"0000";
    }else{
        int resultInt = 0;
        while(resultInt != 6174){
            string bigStr = getBigStr(N);
            string smallStr = getSmallStr(N);

            int bigInt = stoi(bigStr);
            int smallInt = stoi(smallStr);
            resultInt = bigInt - smallInt;
            string resultstr = to4Str(to_string(resultInt));
            cout<<bigStr<<" - "<<smallStr<<" = "<<resultstr;
            if(resultInt != 6174){
                printf("\n");
            }

            N = resultstr;
        }
    }

    return 0;
}


/*
6767

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
*/