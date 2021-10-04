#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string inVal;
int step = 0;
string outVal;
string outReverse;
int k;

string Func(string str){
    string rev = str;
    reverse(rev.begin(),rev.end());

    string out = "";
    int carry = 0;
    int now;
    for(int i=str.length()-1; i>=0; i--){
        now = (str[i]-'0') + (rev[i]-'0') + carry;
        if(now >= 10){
            carry = 1;
            out += to_string(now-10);
        }else{
            carry = 0;
            out += to_string(now);
        }
    }
    if(carry == 1){
        out += '1';
    }
    reverse(out.begin(),out.end());
    return out;

}

int main(){
    cin>>inVal>>k;

    //本身就是回文的情况
    outVal = inVal;
    outReverse = outVal;
    reverse(outReverse.begin(),outReverse.end());
    if(outVal == outReverse){
        cout<<inVal<<endl<<0;
        return 0;
    }

    for(int i=0;i<k;i++){
        step++;
        outVal = Func(outVal);
        outReverse = outVal;
        reverse(outReverse.begin(),outReverse.end());
        if(outVal == outReverse){
            break;
        }
    }
    cout<<outVal<<endl<<step;
    return 0;
}

/*
67 3

484
2
*/

/*
69 3

1353
3
*/