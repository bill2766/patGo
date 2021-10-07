#include <iostream>

using namespace std;

const int MAX_N = 100010;

int firstA, firstB, n;
int sizeA = 0, sizeB = 0;

char ddata[MAX_N];

int nnext[MAX_N];
int addrA[MAX_N];
int addrB[MAX_N];

int main(){
    scanf("%d %d %d",&firstA,&firstB,&n);

    int temp;
    for(int i=0; i<n; i++){
        scanf("%d ",&temp);
        scanf("%c",&ddata[temp]);
        scanf("%d",&nnext[temp]);
    }

    while(firstA != -1){
        addrA[sizeA++] = firstA;
        firstA = nnext[firstA];
    }
    while(firstB != -1){
        addrB[sizeB++] = firstB;
        firstB = nnext[firstB];
    }

    int resultAddr = -1;
    int indA = sizeA-1,indB = sizeB-1;
    while(indA >= 0 && indB >= 0){
        if(addrA[indA] == addrB[indB]){
            resultAddr = addrA[indA];
            indA--;
            indB--;
        }else{
            break;
        }
    }

    if(resultAddr != -1){
        printf("%05d",resultAddr);
    }else{
        printf("-1");
    }
    

    return 0;
}

/*
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

67890


00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1

-1
*/