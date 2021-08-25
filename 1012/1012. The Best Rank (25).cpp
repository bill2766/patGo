#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Stu{
    string ID;
    int C;
    int M;
    int E;
    int A; //可能是float

    int bestRank = -1;
    char bestCourse;
};

vector<Stu> stus;

bool cmp1(Stu stu1, Stu stu2){
    return stu1.A > stu2.A;
}

bool cmp2(Stu stu1, Stu stu2){
    return stu1.C > stu2.C;
}

bool cmp3(Stu stu1, Stu stu2){
    return stu1.M > stu2.M;
}

bool cmp4(Stu stu1, Stu stu2){
    return stu1.E > stu2.E;
}

void calRank(){
    sort(stus.begin(),stus.end(),cmp1);
    for(int i=0; i<stus.size(); i++){
        if(i != 0){
            if(stus[i].A != stus[i-1].A){
                stus[i].bestRank = i+1;
            }else{
                stus[i].bestRank = stus[i-1].bestRank;
            }
        }else{
            stus[i].bestRank = i+1;
        }
        stus[i].bestCourse = 'A';
    }

    int rank;
    sort(stus.begin(),stus.end(),cmp2);
    for(int i=0; i<stus.size(); i++){
        if(i != 0){
            if(stus[i].C != stus[i-1].C){
                rank = i+1;
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'C';
                }
            }else{
                //rank不变
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'C';
                }
            }
        }else{
            rank = i+1;
            if(stus[i].bestRank > rank){
                stus[i].bestRank = rank;
                stus[i].bestCourse = 'C';
            }
        }
    }
    rank = 1;

    sort(stus.begin(),stus.end(),cmp3);
        for(int i=0; i<stus.size(); i++){
        if(i != 0){
            if(stus[i].M != stus[i-1].M){
                rank = i+1;
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'M';
                }
            }else{
                //rank不变
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'M';
                }
            }
        }else{
            rank = i+1;
            if(stus[i].bestRank > rank){
                stus[i].bestRank = rank;
                stus[i].bestCourse = 'M';
            }
        }
    }
    rank = 1;

    sort(stus.begin(),stus.end(),cmp4);
    for(int i=0; i<stus.size(); i++){
        if(i != 0){
            if(stus[i].E != stus[i-1].E){
                rank = i+1;
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'E';
                }
            }else{
                //rank不变
                if(stus[i].bestRank > rank){
                    stus[i].bestRank = rank;
                    stus[i].bestCourse = 'E';
                }
            }
        }else{
            rank = i+1;
            if(stus[i].bestRank > rank){
                stus[i].bestRank = rank;
                stus[i].bestCourse = 'E';
            }
        }
    }
}


int main(){
    int N, M;
    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++){
        struct Stu newStu;
        cin>>newStu.ID>>newStu.C>>newStu.M>>newStu.E;
        newStu.A = (newStu.C+newStu.M+newStu.E) / 3.0 + 0.5;
        stus.push_back(newStu);
    }

    string ids[M];
    for(int i=0; i<M; i++){
        cin>>ids[i];
    }

    calRank();

    for(int i=0; i<M; i++){
        for(int j=0; j<stus.size(); j++){
            if(stus[j].ID == ids[i]){
                printf("%d %c\n",stus[j].bestRank,stus[j].bestCourse);
                break;
            }
            if(j == stus.size()-1){
                printf("N/A\n");
            }
        }
    }

    return 0;
}

/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
*/

/*
1 C
1 M
1 E
1 A
3 A
N/A
*/