#include <cstdio>
#include <map>

using namespace std;

const int MAX_N = 31;

int N;
int in[MAX_N];
int post[MAX_N];

map<int,int> res;

void pre(int root, int start, int end, int index){
    if(start > end) return;

    int i = start;
    while(i < end && in[i] != post[root]) i++;

    res[index] = post[root];

    pre(root-(end-i)-1,start,i-1,2*index+1);
    pre(root-1,i+1,end,2*index+2);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&post[i]);
    for(int i=0;i<N;i++) scanf("%d",&in[i]);

    pre(N-1,0,N-1,0);

    map<int,int>::iterator it = res.begin();
    for(;it!=res.end();it++){
        printf("%d",it->second);
        if(it != --res.end()) printf(" ");
    }
    return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

4 1 6 3 5 7 2
*/