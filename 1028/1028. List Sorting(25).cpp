#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;

int n,c;

struct Node{
    int id;
    char name[10];
    int grade;
}peos[MAX_N];

bool cmp0(Node a,Node b){
    return a.id < b.id;
}  

bool cmp1(Node a,Node b){
    if(strcmp(a.name,b.name) != 0){
        return strcmp(a.name,b.name) <= 0;
    }else{
        return a.id < b.id;
    }
}  

bool cmp2(Node a, Node b){
    if(a.grade != b.grade){
        return a.grade <= b.grade;
    }else{
        return a.id < b.id;
    }
}

int main(){
    scanf("%d %d",&n,&c);

    for(int i=0;i<n;i++){
        scanf("%d %s %d",&peos[i].id,&peos[i].name,&peos[i].grade);
    }

    if(c == 1){
        sort(peos,peos+n,cmp0);
    }else if(c == 2){
        sort(peos,peos+n,cmp1);
    }else{
        sort(peos,peos+n,cmp2);
    }

    for(int i=0;i<n;i++){
        printf("%06d %s %d\n",peos[i].id,peos[i].name,peos[i].grade);
    }

    return 0;
}

/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

000001 Zoe 60
000007 James 85
000010 Amy 90


4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98

000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60


4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 9

000002 James 9
000001 Zoe 60
000007 James 85
000010 Amy 90
*/