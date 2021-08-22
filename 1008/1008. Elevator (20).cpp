#include <cstdio>


int main(){
    int sum = 0;

    int N;
    scanf("%d",&N);

    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    int nowPos = 0;
    for(int i=0; i<N; i++){
        if(arr[i] - nowPos > 0){
            sum += 6 * (arr[i] - nowPos);
        }else if(arr[i] - nowPos < 0){
            sum += 4 * (-(arr[i] - nowPos));
        }
        nowPos = arr[i];
    }

    sum+= N * 5;

    printf("%d",sum);

    return 0;
}

/*
3 2 3 1
*/

//41