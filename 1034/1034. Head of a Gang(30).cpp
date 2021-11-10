//////////////////////////////
//只有22分，ac版见2.cpp
//////////////////////////////

// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// using namespace std;

// const int MAX_PEO = 2020;
// int N;
// int K;

// int father[MAX_PEO];

// void Init(){
//     for(int i=1;i<MAX_PEO;i++){
//         father[i] = i;
//     }
// }

// int findFather(int x){
//     int thex = x;
//     while(x != father[x]) x = father[x];

//     while(thex != father[thex]){
//         int temp = thex;
//         thex = father[thex];
//         father[temp] = x;
//     }
//     return x;
// }

// map<string,int> nameToId;
// int id = 1;
// int totalTime[MAX_PEO];
// int isRootNum[MAX_PEO];

// void Union(int a, int b){
//     int faA = findFather(a);
//     int faB = findFather(b);
//     if(faA != faB){
//         father[faA] = faB;
//         totalTime[faB] = totalTime[faA];
//         totalTime[faA] = 0;
//     }
// }

// int singleCallTime[MAX_PEO];

// string getNameById(int id){
//     for(map<string,int>::iterator it = nameToId.begin();it!=nameToId.end();it++){
//         if(it->second == id){
//             return it->first;
//         }
//     }
//     return "";
// }

// int main(){
//     Init();
//     cin>>N>>K;
//     string u1, u2;
//     int callTime;
//     for(int i=0;i<N;i++){
//         cin>>u1>>u2>>callTime;
//         if(nameToId.find(u1) == nameToId.end()){
//             nameToId[u1] = id;
//             id++;
//         }
//         if(nameToId.find(u2) == nameToId.end()){
//             nameToId[u2] = id;
//             id++;
//         }
//         singleCallTime[nameToId[u1]] += callTime;
//         singleCallTime[nameToId[u2]] += callTime;
//         Union(nameToId[u1],nameToId[u2]);
//         totalTime[findFather(nameToId[u1])] += callTime;
//     }

//     int gangNum = 0;
//     int resCallTime[MAX_PEO] = {0};

//     int maxCallTime[MAX_PEO] = {0};
//     int resUser[MAX_PEO] = {0};
    
//     for(int i=1;i<id;i++){
//         if(singleCallTime[i] > maxCallTime[findFather(i)]){
//             maxCallTime[findFather(i)] = singleCallTime[i];
//             resUser[findFather(i)] = i;
//         }
//         isRootNum[findFather(i)]++;
//     }

//     for(int i=1;i<id;i++){
//         if(isRootNum[i] > 2 && totalTime[i] > K){
//             gangNum++;
//             resCallTime[i] = totalTime[i];
//         }
//     }

//     cout<<gangNum<<endl;
//     for(int i=1;i<id;i++){
//         if(resCallTime[i] != 0){
//             cout<<getNameById(resUser[i])<<" "<<isRootNum[i]<<endl;
//         }
//     }

//     return 0;
// }

/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

2
AAA 3
GGG 3


8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

0
*/