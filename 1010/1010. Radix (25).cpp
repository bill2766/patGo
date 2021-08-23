#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

//char转换成相应的数字
int digTo10(char c){
    if(c-'0' >=0 && c-'0' <10){
        return c-'0';
    }else if(c - 'a' >=0 && c-'a' <26){
        return c-'a'+10;
    }else{
        return -1;
    }
}

//radix进制转换成10进制的函数
long long nTo10(string val, int radix){
    long long sum = 0;
    int len = val.length();
    for(int i=len-1; i>=0;i--){
        sum += digTo10(val[i]) * pow(radix,len-1-i);
    }
    return sum;
}

//找到dig中最大的值，为了给low赋值dig+1用
int maxV(string str){
    int max = 0; 
    int dig;
    for(int i=0; i<str.length();i++){
        dig = digTo10(str[i]);
        if(dig > max){
            max = dig;
        }
    }
    return max;
}

//利用二分法找到Radix
long long findRadix(string str, long long first_10){
    long long low = maxV(str) + 1;
    //high最大可以为另外那个数，当str为1的时候有可能成立，为1时值的大小为radix
    //如果进制比另外那个数还要大，那随随便便都不能等于另外那个数了
    long long high = max(first_10,low);
    while(low <= high){
        long long mid = (low + high) / 2;
        long long t = nTo10(str,mid);
        //t<0表示溢出，数字太大了，大到无法用long long表示，说明不合适，要缩小high
        if(t<0 || t > first_10){
            high = mid - 1;
        }else if(t == first_10){
            return mid;
        }else{
            low = mid + 1;            
        }
    }
    return -1;
}

int main(){
    string a,b;
    int c,d;
    cin>>a>>b>>c>>d;


    long long first_10;
    string second;

    if(c == 1){
        first_10 = nTo10(a,d);
        second = b;
    }else{
        first_10 = nTo10(b,d);
        second = a;
    }

    long long result = findRadix(second,first_10);
    if(result == -1){
        printf("Impossible");
    }else{
        printf("%d",result);
    }

    return 0;
}


/*
6 110 1 10

2
*/

/*
1 ab 1 2

Impossible
*/