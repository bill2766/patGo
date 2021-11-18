#include <cstdio>
#include <algorithm>
using namespace std;

int ag,as,ak;
int bg,bs,bk;
int resg,ress,resk;

void convert(){
    if(resk >= 29){
        ress += resk/29;
        resk %= 29;
    }
    if(ress >= 17){
        resg += ress/17;
        ress %= 17;
    }
}

int main(){
    scanf("%d.%d.%d %d.%d.%d",&ag,&as,&ak,&bg,&bs,&bk);

    resg = ag + bg;
    ress = as + bs;
    resk = ak + bk;
    
    convert();
    printf("%d.%d.%d",resg,ress,resk);

    return 0;
}

/*
3.2.1 10.16.27

14.1.28
*/