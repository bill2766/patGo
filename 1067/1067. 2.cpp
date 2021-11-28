#include <cstdio>
int a[100010] = {0};
int b[100010] = {0};

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(a[i] != i){
            b[i] = 1;
        }
    }
    
    int count = 0;
    for(int i=0; i<n; i++){
        if(b[i] == 1){
            int ans = a[i];
            b[i] = -1;
            count++;
            while(b[ans] == 1){
                b[ans] = -1;
                ans = a[ans];
                count++;
            }
            count++;
        }
    }
    if(a[0] != 0) count-=2;

    printf("%d", count);

    return 0;
}