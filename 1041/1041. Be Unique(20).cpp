#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_VAL = 100010;

int rrank[MAX_VAL];

int main(){
    fill(rrank, rrank+MAX_VAL, -1);
    int N;
    scanf("%d",&N);
    int temp = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &temp);
        if(rrank[temp] == -1){
            rrank[temp] = i;
        }else{
            rrank[temp] = -2;
        }
    }

    int resInd = MAX_VAL;
    int res = -1;
    for(int i=0; i<MAX_VAL; i++){
        if(rrank[i] != -1 && rrank[i] != -2){
            if(rrank[i] < resInd){
                resInd = rrank[i];
                res = i;
            }
        }
    }
    if(res != -1){
        printf("%d",res);
    }else{
        printf("None");
    }

    return 0;
}

/*
7 5 31 5 88 67 88 17

31


5 888 666 666 888 888

None
*/