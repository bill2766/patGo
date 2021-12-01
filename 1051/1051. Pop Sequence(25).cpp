#include <cstdio>
#include <stack>
using namespace std;

int M, N, K;

int main(){
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<K; i++){
        int arr[N];
        for(int j=0; j<N; j++){
            scanf("%d", &arr[j]);
        }

        stack<int> s;
        int toAdd = 1;
        int ind = 0;
        bool flag = true;
        while(ind < N){
            //如果s为空 或 不相等
            if(s.empty() || s.top() != arr[ind]){
                if(toAdd == N+1 || s.size() == M){
                    printf("NO\n");
                    flag = false;
                    break;
                }
                s.push(toAdd++);
            //pop
            }else{
                s.pop();
                ind++;
            }
        }
        if(flag) printf("YES\n");
    }

    return 0;
}

/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

YES
NO
NO
YES
NO
*/