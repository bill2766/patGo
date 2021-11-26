#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M;

map<string, vector<string> > titles;
map<string, vector<string> > authors;
map<string, vector<string> > keywords;
map<string, vector<string> > pubers;
map<string, vector<string> > pubYears;

void addKeyWord(string key_words, string id){
    int begin = 0, len = 0;
    for(int i=0; i<key_words.length(); i++){
        
        if(key_words[i] == ' '){
            string keyword = key_words.substr(begin, len);
            keywords[keyword].push_back(id);
            begin = i+1;
            len = 0;
        }else{
            len++;
        }
    }
    //最后一个
    string keyword = key_words.substr(begin, len);
    keywords[keyword].push_back(id);
}

bool cmp1(string a, string b){
    return a < b;
}

int main(){
    scanf("%d\n",&N);
    for(int i=0; i<N; i++){
        string id, title, author, keyWords, puber, pubYear;
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyWords);
        getline(cin, puber);
        getline(cin, pubYear);
        titles[title].push_back(id);
        authors[author].push_back(id);
        addKeyWord(keyWords, id);
        pubers[puber].push_back(id);
        pubYears[pubYear].push_back(id);
    }

    scanf("%d\n",&M);
    for(int i=0; i<M; i++){
        string command;
        getline(cin, command);
        int code = command[0] - '0';
        string comm = command.substr(3);
        
        cout<<command<<endl;
        switch (code)
        {
        case 1:
            if(titles[comm].empty()){
                printf("Not Found\n");
            }else{
                sort(titles[comm].begin(), titles[comm].end(), cmp1);
                for(int i=0; i<titles[comm].size(); i++){
                    cout<<titles[comm][i]<<endl;
                }
            }
            break;
        case 2:
            if(authors[comm].empty()){
                printf("Not Found\n");
            }else{
                sort(authors[comm].begin(), authors[comm].end(), cmp1);
                for(int i=0; i<authors[comm].size(); i++){
                    cout<<authors[comm][i]<<endl;
                }
            }
            break;
        case 3:
            if(keywords[comm].empty()){
                printf("Not Found\n");
            }else{
                sort(keywords[comm].begin(), keywords[comm].end(), cmp1);
                for(int i=0; i<keywords[comm].size(); i++){
                    cout<<keywords[comm][i]<<endl;
                }
            }
            break;
        case 4:
            if(pubers[comm].empty()){
                printf("Not Found\n");
            }else{
                sort(pubers[comm].begin(), pubers[comm].end(), cmp1);
                for(int i=0; i<pubers[comm].size(); i++){
                    cout<<pubers[comm][i]<<endl;
                }
            }
            break;
        case 5:
            if(pubYears[comm].empty()){
                printf("Not Found\n");
            }else{
                sort(pubYears[comm].begin(), pubYears[comm].end(), cmp1);
                for(int i=0; i<pubYears[comm].size(); i++){
                    cout<<pubYears[comm][i]<<endl;
                }
            }
            break;
        }
    }

    return 0;
}

/*
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla

1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
*/