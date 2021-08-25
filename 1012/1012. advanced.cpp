#include <cstdio>
#include <algorithm>
using namespace std;

//学生结构体
struct node {
    int id, best;
    int score[4], rank[4];
}stu[2005];

int exist[1000000], flag = -1;

bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}

int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        //平均分
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
    }

    //利用全局变量flag，同时也让cmp1改变sort策略
    for(flag = 0; flag <= 3; flag++) {
        sort(stu, stu + n, cmp1);
        //分别对应的排名保存在rank中
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            stu[i].rank[flag] = i + 1;
            //如果与前面的成绩相同，则保持排名与前面的同学相同
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }

    //for循环-两用，一方面更新exist，另一方面找到最好排名
    for(int i = 0; i < n; i++) {
        //用exist数组保存当前id是否存在，这个id对应的stu结构体的下标是多少
        //这里使用i+1，确保它>=1，给后面61行的if(temp)作为bool使用
        exist[stu[i].id] = i + 1;
        //最厉害排名的下标best，初始化为0
        //minn最厉害的排名，初始化为ACME中A的排名
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        //更新最厉害的排名
        for(int j = 1; j <= 3; j++) {
            if(stu[i].rank[j] < minn) {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }

    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = exist[id];
        //如果存在
        if(temp) {
            //排名的下标 best，给rank[best]和c[best]用
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].rank[best], c[best]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}