//23分，差2分


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int MAX_N = 10010, MAX_K = 110;

// int n,k;

// struct peo{
//     int comeTime;
//     int opTime;
//     peo(int comeTime,int opTime):comeTime(comeTime),opTime(opTime){}
//     peo():comeTime(0),opTime(0){}
// }waitPeos[MAX_N];

// bool finished[MAX_N];

// bool cmp(peo a, peo b){
//     return a.comeTime < b.comeTime;
// }

// struct window{
//     int endTime;
//     window():endTime(0){}
// }windows[MAX_K];

// int totalWait = 0;
// int countSize = 0;

// int main(){
//     cin>>n>>k;
//     fill(finished,finished+MAX_N,false);

//     int hour,min,sec,opTime;
//     for(int i=0;i<n;i++){
//         scanf("%d:%d:%d %d",&hour,&min,&sec,&opTime);
//         if(hour*60*60+min*60+sec-8*60*60 > 9 * 60 * 60){
//             continue;
//         }
//         waitPeos[countSize] = peo(hour*60*60+min*60+sec-8*60*60,opTime*60);
//         countSize++;
//     }
//     sort(waitPeos,waitPeos+countSize,cmp);

//     for(int time=0;time<=9*60*60;time++){
//         for(int i=0;i<k;i++){
//             if(windows[i].endTime <= time){
//                 for(int j=0;j<countSize;j++){
//                     if(!finished[j] && waitPeos[j].comeTime <= time){
//                         windows[i].endTime = time + waitPeos[j].opTime;
//                         totalWait += (time - waitPeos[j].comeTime);
//                         finished[j] = true;
//                         break;
//                     }
//                 }   
//             }
//         }
//     }
//     printf("%.1lf",totalWait/ 60.0 / countSize);

//     return 0;
// }

/*
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

8.2
*/