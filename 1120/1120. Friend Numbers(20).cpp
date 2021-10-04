#include <iostream>
#include <string>
#include <set>
using namespace std;

int n;
set<int> res;

int getId(string str){
    int out = 0;
    for(int i=0;i<str.length();i++){
        out += (str[i] - '0');
    }
    return out;
}

int main(){
    cin>>n;
    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        res.insert(getId(temp));
    }

    cout<<res.size()<<endl;
    for(set<int>::iterator it=res.begin(); it!=res.end(); it++){
        printf("%d",*it);
        if(it != --res.end()){
            printf(" ");
        }
    }
    return 0;
}

/*
8
123 899 51 998 27 33 36 12

4
3 6 9 26
*/