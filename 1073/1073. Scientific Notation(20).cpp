#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    string in;
    string out = "";

    cin>>in;
    if(in[0] == '-'){
        out += "-";
    }

    string val;
    string::iterator it;
    for(it = ++in.begin();*it != 'E';it++){
        val += *it;
    }

    string offset;
    for(it++;it!=in.end();it++){
        offset+=*it;
    }
    int offsetInt = atoi(offset.c_str());

    val.erase(val.begin()+1);
    if(offsetInt < 0){
        out+="0.";
        while(offsetInt+1 < 0){
            out+="0";
            offsetInt++;
        }
        out+=val;
    }else{
        out+=val[0];
        int temp = 1;
        while(temp < val.length() || temp <= offsetInt){
            if(temp < val.length()){
                out+=val[temp];
            }else{
                out+="0";
            }

            //如果不需要加零，则加个.
            if((temp == offsetInt) && (temp < val.length()-1)){
                out+=".";
            }
            temp++;
        }
    }

    cout<<out;

    return 0;
}

/*
+1.23400E-03

0.00123400


-1.2E+10

-12000000000
*/