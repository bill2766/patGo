#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#define MAX_N 100000
#define SQRT_N 317
using namespace std;

int table[MAX_N], block[SQRT_N];
stack<int> s;

void push(int n){
    s.push(n);
    table[n]++;
    block[n / SQRT_N]++;
}

int pop(){
    int n = s.top;
    s.pop();
    table[n]--;
    block[n / SQRT_N]--;
    return n;
}

int peekMedian(){
    int K = (s.size() + 1) / 2;
    int i=0, j=0;
    while(j + block[i] < K){
        j += block[i];
        i++
    }

    int k = i * SQRT_N;
    while(j + table[k] < K){
        j += table[k];
        k++;
    }
    return k;
}

int main(){
    memset(table, 0, sizeof(int));
    memset(block, 0, sizeof(int));

    int N;
    scanf("%d",&N);

    char cmd[30];
    int t;
    for(int i=0; i<N; i++){
        scanf("%s",cmd);
        if(cmd[1] == 'o'){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                printf("%d\n",pop());
            }
        }else if(cmd[1] == 'u'){
            scanf("%d",&t);
            push(t);
        }else{
            if(s.empty()){
                printf("Invalid\n");
            }else{
                printf("%d\n", peekMedian());
            }
        }
    }
    return 0;
}