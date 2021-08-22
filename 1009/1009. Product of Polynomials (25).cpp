#include <cstdio>
#include <map>
using namespace std;

struct Node{
    int exp; //指数
    float coe; //系数
};

int main(){
    int aNum;
    int bNum;

    scanf("%d",&aNum);
    struct Node A[aNum];
    for(int i=0; i<aNum; i++){
        scanf("%d %f",&A[i].exp,&A[i].coe);
    }
    scanf("%d",&bNum);
    struct Node B[bNum];
    for(int i=0; i<bNum; i++){
        scanf("%d %f",&B[i].exp,&B[i].coe);
    }

    map<int,float> result;
    for(int i=0; i<aNum; i++){
        for(int j=0; j<bNum; j++){
            result[A[i].exp + B[j].exp] += A[i].coe * B[j].coe;
        }
    }

    //删除0
    for(map<int,float>::iterator it = result.begin();it != result.end();it++){
        if(it->second == 0){
            result.erase(it);
        }
    }

    printf("%d ",result.size());
    for(map<int,float>::iterator it = --result.end();;it--){
        printf("%d %.1f",it->first,it->second);
        if(it == result.begin()){
            break;
        }else{
            printf(" ");
        }
    }

    return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/

//3 3 3.6 2 6.0 1 1.6