#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //获得2个数
    int v1,v2;
    scanf("%d%d",&v1,&v2);
    int result = v1 + v2;

    bool isPos = 1; //是否正数
    if(result < 0){
        isPos = 0;
        result = -result;
    }
    
    string out = "";

    string str = to_string(result); //转为string，统一变成正数
    int count=0;
    int i = str.length() -1;

    //从个位数开始输入，每3位数后加“,”
    while(i >= 0){
        if(count == 3){
            out+=",";
            count = 0;
        }
        out+=str[i];
        count++;
        i--;
    }
    reverse(out.begin(),out.end());

    if(!isPos){
        out = "-" + out;
    }
    cout << out;
    return 0;
}