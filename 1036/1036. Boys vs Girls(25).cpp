#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int mGrade = 101;
int fGrade = -1;

char mName[15];
char fName[15];
char mId[15];
char fId[15];

int main(){
    scanf("%d",&n);

    char name[15];
    char sex;
    char id[15];
    int grade;
    for(int i=0;i<n;i++){
        scanf("%s %c %s %d",name,&sex,id,&grade);
        if(sex == 'M'){
            if(grade < mGrade){
                mGrade = grade;
                strcpy(mName,name);
                strcpy(mId,id);
            }
        }else{
            if(grade > fGrade){
                fGrade = grade;
                strcpy(fName,name);
                strcpy(fId,id);
            }
        }
    }

    if(fGrade != -1){
        printf("%s %s\n",fName,fId);
    }else{
        printf("Absent\n");
    }
    if(mGrade != 101){
        printf("%s %s\n",mName,mId);
    }else{
        printf("Absent\n");
    }
    if(fGrade != -1 && mGrade != 101){
        printf("%d",fGrade-mGrade);
    }else{
        printf("NA");
    }

    return 0;
}


/*
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Mary EE990830
Joe Math990112
6


1
Jean M AA980920 60

Absent
Jean AA980920
NA
*/