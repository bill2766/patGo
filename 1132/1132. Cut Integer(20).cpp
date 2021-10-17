#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string val;
    int len;
    string a;
    string b;
    for(int i=0;i<n;i++){
        cin>>val;
        len = val.length();
        a = val.substr(0,len/2);
        b = val.substr(len/2,len/2);
        float check = atof(val.c_str()) / atof(a.c_str()) / atof(b.c_str());
        if(check == (int)check){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}


/*
3
167334
2333
12345678

Yes
No
No
*/