#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

string tenTo13(int val){
    string out = "";
    while(val !=0){
        switch (val % 13)
        {
        case 10:
            out += "A";
            break;
        case 11:
            out += "B";
            break;
        case 12:
            out += "C";
            break;
        default:
            out += to_string(val % 13);
            break;
        }
        val /= 13;
    }
    reverse(out.begin(),out.end());
    return out;
}

int main(){
    int red, green, blue;
    scanf("%d %d %d",&red,&green,&blue);

    string red13,green13,blue13;
    red13 = tenTo13(red);
    green13 = tenTo13(green);
    blue13 = tenTo13(blue);
    red13.insert(0,2-red13.length(),'0');
    green13.insert(0,2-green13.length(),'0');
    blue13.insert(0,2-blue13.length(),'0');

    cout<<"#"<<red13<<green13<<blue13;
    
    return 0;
}

/*
15 43 71

#123456
*/