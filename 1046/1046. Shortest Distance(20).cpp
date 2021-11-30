#include <cstdio>
using namespace std;

const int MAX_N = 100010;

int N;
int G[MAX_N];

int main(){
    scanf("%d",&N);
    
    int temp;
    for(int i=1; i<=N; i++){
        scanf("%d",&temp);
        G[i] = temp;
    }
    
    int M;
    scanf("%d",&M);
    int d1, d2;
    for(int i=0; i<M; i++){
        scanf("%d %d",&d1, &d2);
        //使d1<=d2
        if(d1 > d2){
            temp = d1;
            d1 = d2;
            d2 = temp;
        }

        int res = 0;
        for(int i=d1; i<=d2-1; i++){
            res += G[i];
        }

        int res2 = 0;
        for(int i=d1-1; i>=1; i--){
            res2 += G[i];
        }
        for(int i=N; i>=d2; i--){
            res2 += G[i];
        }

        if(res < res2){
            printf("%d\n",res);
        }else{
            printf("%d\n",res2);
        }
    }

    return 0;
}

/*
5 1 2 4 14 9
3
1 3
2 5
4 1

3
10
7
*/