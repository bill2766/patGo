#include <iostream>
#include <cmath>
using namespace std;

long int num, temp;

int main(){
    cin>>num;
    //在这里根号num是向下取整，所以可能出现num = 根号num * (根号num+1)
    int maxn = sqrt(num)+1;

    //第一个数first，长度len
    int first=0, len=0;
    //第一个数从2开始，直到maxn
    for(int i=2; i<=maxn; i++){
        //temp作为连乘的积
        temp = 1;

        int j;
        for(j = i; j<=maxn; j++){
            temp *= j;
            //尽量让temp多一点乘j
            //num不可以被temp整除则退出，这是j是连乘最后一个数+1
            if(num % temp != 0) break;
        }
        //这时i为第一个数，j为连乘最后一个数+1。因此j-i为长度
        //找到更长的
        if(j - i > len){
            len = j-i;
            first = i;
        }
    }

    //没有一个连乘可以被质数整除，因此i=j->j-i=0 == len。first也不会更新
    if(first == 0){
        cout<<1<<endl<<num;
    }else{
        cout<<len<<endl;
        for(int i=0; i<len; i++){
            cout<<first + i;
            if(i != len-1) cout<<'*';
        }
    }

    return 0;
}