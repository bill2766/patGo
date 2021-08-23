#include <cstdio>

int main(){
    float A[3],B[3],C[3];
    scanf("%f %f %f",&A[0],&A[1],&A[2]);
    scanf("%f %f %f",&B[0],&B[1],&B[2]);
    scanf("%f %f %f",&C[0],&C[1],&C[2]);

    int max = 0;
    float maxResult = 0;
    int maxInd = 0;

    for(int i=0; i<3; i++){
        if(A[i] > max){
            max = A[i];
            maxInd = i;
        }
    }
    if(maxInd == 0){
        printf("W ");
    }else if(maxInd == 1){
        printf("T ");
    }else{
        printf("L ");
    }
    maxResult=A[maxInd];
    max = 0;
    maxInd=0;

    for(int i=0; i<3; i++){
        if(B[i] > max){
            max = B[i];
            maxInd = i;
        }
    }
    if(maxInd == 0){
        printf("W ");
    }else if(maxInd == 1){
        printf("T ");
    }else{
        printf("L ");
    }
    maxResult*=B[maxInd];
    max = 0;
    maxInd=0;

    for(int i=0; i<3; i++){
        if(C[i] > max){
            max = C[i];
            maxInd = i;
        }
    }
    if(maxInd == 0){
        printf("W ");
    }else if(maxInd == 1){
        printf("T ");
    }else{
        printf("L ");
    }
    maxResult*=C[maxInd];
    max = 0;
    maxInd=0;

    printf("%.2f",(maxResult*0.65-1)*2);
    return 0;
}

/*
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
*/

//T T W 39.31