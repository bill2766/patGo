///////////////////////////////
//15分，内存超限。ac版见2.cpp
///////////////////////////////

// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int MAX_N = 10010;

// int N, M;
// bool G[MAX_N][MAX_N];
// bool tempG[MAX_N][MAX_N];

// int K;
// int curM;

// void initTempG(){
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             tempG[i][j] = G[i][j];
//         }
//     }
// }

// void diffuse(int u){
//     for(int v=0;v<N;v++){
//         if(tempG[u][v] == 1){
//             tempG[u][v] = tempG[v][u] = 0;
//             curM++;
//         }
//     }
// }

// bool isVertexCover;
// void diffuseTrave(int vNumber, int vArr[]){
//     for(int i=0; i<vNumber; i++){
//         diffuse(vArr[i]);
//     }
// }

// int main(){
//     cin>>N>>M;

//     int v1, v2;
//     for(int i=0;i<M;i++){
//         cin>>v1>>v2;
//         G[v1][v2] = 1;
//         G[v2][v1] = 1;
//     }

//     cin>>K;
//     for(int i=0; i<K; i++){
//         initTempG();
//         isVertexCover = true;
//         curM = 0;

//         int vNumber;
//         cin>>vNumber;
//         int vArr[vNumber];
//         for(int j=0; j<vNumber; j++){
//             cin>>vArr[j];
//         }
//         diffuseTrave(vNumber, vArr);

//         if(curM == M){
//             cout<<"Yes"<<endl;
//         }else{
//             cout<<"No"<<endl;
//         }
//     }

//     return 0;
// }

/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2

No
Yes
Yes
No
No
*/