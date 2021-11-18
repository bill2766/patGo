#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Stu{
    string name;
    string id;
    int grade;
};
vector<Stu> stus;
int n;

int grade1, grade2;

bool cmp1(Stu a, Stu b){
    return a.grade > b.grade;
}

int main(){
    cin>>n;
    stus.resize(n);

    string name, id;
    int grade;
    for(int i=0;i<n;i++){
        cin>>stus[i].name>>stus[i].id>>stus[i].grade;
    }

    cin>>grade1>>grade2;
    for(int i=0;i<n;i++){
        if(stus[i].grade < grade1 || stus[i].grade > grade2){
            stus[i].grade = -1;
        }
    }
    sort(stus.begin(),stus.end(),cmp1);

    if(stus[0].grade == -1){
        printf("NONE");
    }else{
        for(int i=0;i<n;i++){
            if(stus[i].grade != -1){
                cout<<stus[i].name<<" "<<stus[i].id<<endl;
            }else{
                break;
            }
        }
    }

    return 0;
}

/*
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

Mike CS991301
Mary EE990830
Joe Math990112


2
Jean AA980920 60
Ann CS01 80
90 95

NONE
*/