#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

set<char> words;

int main(){
    string senStr;
    string worStr;
    getline(cin,senStr);
    getline(cin,worStr);

    for(int i=0;i<worStr.length();i++){
        words.insert(worStr[i]);
    }

    set<char>::iterator sit;
    for(string::iterator it=senStr.begin();it!=senStr.end();it++){
        sit = words.find(*it);
        if(sit == words.end()){
            cout<<*it;
        }
    }

    return 0;
}

/*
They are students.
aeiou

Thy r stdnts.
*/
