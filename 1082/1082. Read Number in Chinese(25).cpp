#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string ddict[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

string danwei[10] = {"","","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};

string val;
int ssize;

string result = "";

int main(){
    cin>>val;
    if(val[0] == '-'){
        result = "Fu";
        ssize = val.length()-1;
        val = val.substr(1);
    }else{
        ssize = val.length();
    }

    int ind = 0;
    while(ind < ssize){
        int zhi = val[ind] - 48;
        if(zhi != 0){
            if(ssize -ind > 1){
                result += " " + ddict[zhi]+ " "+ danwei[ssize-ind];
            }else{
                result += " " + ddict[zhi];
            }
        }else{
            if(ssize-ind == 5){
                result += " " + danwei[ssize-ind];
            }
        }
        ind++;
    }

    if(result[0] == ' '){
        result = result.substr(1);
    }
    cout<<result;

    return 0;
}

/*
-123456789

Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu


100800

yi Shi Wan ling ba Bai

101111111

1000000

100 0001
*/