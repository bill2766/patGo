#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 210;
int N, M;
int G[MAX_N][MAX_N];

int K;

int minInd;
int minSimple = 1000000000;
void travel(int pInd, int chosenCitys[], int cNumber){
    int mmap[N+1];
    //一定要初始化，不然在平台上会运行错误
    fill(mmap,mmap+N+1,0);
    int sum = 0;
    
    for(int i=1;i<cNumber; i++){
        if(G[chosenCitys[i-1]][chosenCitys[i]] != 0){
            mmap[chosenCitys[i-1]] = 1;
            mmap[chosenCitys[i]] = 1;
            sum += G[chosenCitys[i-1]][chosenCitys[i]];
        }else{
            printf("Path %d: NA (Not a TS cycle)\n",pInd);
            return;
        }
    }

    for(int i=1; i<=N;i++){
        if(mmap[i] == 0){
            printf("Path %d: %d (Not a TS cycle)\n",pInd, sum);
            return;
        }
    }

    if(chosenCitys[0] != chosenCitys[cNumber-1]){
        printf("Path %d: %d (Not a TS cycle)\n",pInd, sum);
        return;
    }

    if(cNumber == N+1){
        printf("Path %d: %d (TS simple cycle)\n",pInd, sum);
        if(sum < minSimple){
            minSimple = sum;
            minInd = pInd;
        }
    }else if(cNumber > N+1){
        printf("Path %d: %d (TS cycle)\n",pInd, sum);
        if(sum < minSimple){
            minSimple = sum;
            minInd = pInd;
        }
    }
}

int main(){
    cin>>N>>M;

    int c1, c2, dist;
    for(int i=0;i<M;i++){
        cin>>c1>>c2>>dist;
        G[c1][c2] = dist;
        G[c2][c1] = dist;
    }

    cin>>K;
    int cNumber;
    for(int pInd=1; pInd<=K; pInd++){
        cin>>cNumber;
        int chosenCitys[cNumber];
        for(int j=0; j<cNumber; j++){
            cin>>chosenCitys[j];
        }

        travel(pInd, chosenCitys, cNumber);
    }
    printf("Shortest Dist(%d) = %d",minInd,minSimple);

    return 0;
}


/*
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6

Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8
*/