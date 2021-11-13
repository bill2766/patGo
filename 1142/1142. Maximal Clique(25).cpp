    #include <cstdio>
    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    const int MAX_NV = 210;

    int Nv, Ne;
    int G[MAX_NV][MAX_NV];

    int M;

    //检查内的点
    int inQuesArr[MAX_NV];
    int isClique(int quesArr[], int K){
        for(int i=0;i<K;i++){
            for(int j=i+1;j<K;j++){
                int u = quesArr[i];
                int v = quesArr[j];
                if(G[u][v] == 0){
                    return 2;
                }
            }
        }

        for(int i=1;i<=Nv; i++){
            //检查外的点
            if(inQuesArr[i] == 0){
                for(int j=0;j<K;j++){
                    if(G[i][quesArr[j]] == 0) break;
                    if(j == K-1) return 1;
                }
            }
        }

        return 0;
    }

    int main(){
        cin>>Nv>>Ne;

        int v1, v2;
        for(int i=0;i<Ne; i++){
            cin>>v1>>v2;
            G[v1][v2] = 1;
            G[v2][v1] = 1;
        }

        cin>>M;
        int K;
        for(int i=0;i<M;i++){
            //一定得是inQuesArr+MAX_NV！
            fill(inQuesArr,inQuesArr+MAX_NV,0);

            cin>>K;
            int quesArr[K];
            for(int j=0;j<K;j++){
                cin>>quesArr[j];
                inQuesArr[quesArr[j]] = 1;
            }

            int check = isClique(quesArr, K);

            if(check == 0){
                printf("Yes\n");
            }else if(check == 1){
                printf("Not Maximal\n");
            }else if(check == 2){
                printf("Not a Clique\n");
            }
        }

        return 0;
    }

    /*
    8 10
    5 6
    7 8
    6 4
    3 6
    4 5
    2 3
    8 2
    2 7
    5 3
    3 4
    6
    4 5 4 3 6
    3 2 8 7
    2 2 3
    1 1
    3 4 3 6
    3 3 2 1

    Yes
    Yes
    Yes
    Yes
    Not Maximal
    Not a Clique
    */