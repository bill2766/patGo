////////////////////////////////////
//在本机运行不了
////////////////////////////////////
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 10010;
int N, Q;
int father[MAX_N];
set<int> unionBirds;
set<int> rootBirds;

void Init(){
    for(int i=1; i<=MAX_N; i++){
        father[i] = i;
    }
}

int findFather(int x){
    int thex = x;
    while(x != father[x]){
        x = father[x];
    }
    while(thex != father[thex]){
        int temp = thex;
        thex = father[thex];
        father[temp] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

int main(){
    Init();
    cin>>N;
    
    int K;
    for(int i=0;i<N;i++){
        cin>>K;
        vector<int> birds;
        birds.resize(K);       
        for(int j=0;j<K;j++){
            cin>>birds[j];
            unionBirds.insert(birds[j]);
        }
        
        for(int z=1; z<K; z++){
            Union(birds[0],birds[z]);
        }
    }
    
    for(set<int>::iterator it = unionBirds.begin(); it != unionBirds.end(); it++){
        rootBirds.insert(findFather(*it));
    }

    cout<<rootBirds.size()<<" "<<unionBirds.size()<<endl;

    cin>>Q;
    int a, b;
    for(int i=0;i<Q;i++){
        cin>>a>>b;
        if(findFather(a) == findFather(b)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}

/*
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

2 10
Yes
No
*/