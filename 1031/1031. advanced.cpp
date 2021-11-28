#include <iostream>
#include <cstdio>
#include <cstring>
int main() {
    char str[100];
    scanf("%s", str);
    
    // 通过公式计算出n1、n2
    int
    N = (int)strlen(str),
    n1 = (N + 2) / 3,
    n2 = N + 2 - n1 - n1;
    
    // 输出第一行到倒数第二行
    for(int i = 0; i < n1 - 1; i++){
        putchar(str[i]);
        
        // 输出中间的空格
        for(int j = n2 - 3; j >= 0; j--){
            putchar(' ');
        }
        
        
        putchar(str[N - i - 1]);
        
        // 记得输出换行符
        putchar('\n');
    }
    
    // 输出最后一行
    for(int i = n1 - 1, l = n1 + n2 - 1; i < l; i++){
        putchar(str[i]);
    }
    return 0;
}

