#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

const int MAX_N = 100010;

struct Node
{
    int ind;
    int data;
    int next;
}nodes[MAX_N];

int head;
int N;

set<int> appeared;
vector<Node> res1;
vector<Node> res2;

int main(){
    scanf("%d %d", &head, &N);

    int now, data, next;
    for(int i=0; i<N; i++){
        scanf("%d %d %d",&now, &data, &next);
        nodes[now].ind = now;
        nodes[now].data = data;
        nodes[now].next = next;
    }
    
    int cur = head;
    while(cur != -1){
        if(appeared.find(abs(nodes[cur].data)) == appeared.end()){
            appeared.insert(abs(nodes[cur].data));
            res1.push_back(nodes[cur]);
        }else{
            res2.push_back(nodes[cur]);
        }
        cur = nodes[cur].next;
    }

    for(int i=1; i<=res1.size(); i++){
        if(i != res1.size()){
            printf("%05d %d %05d\n", res1[i-1].ind, res1[i-1].data,res1[i].ind);
        }else{
            printf("%05d %d -1\n", res1[i-1].ind, res1[i-1].data);
        }
    }

    for(int i=1; i<=res2.size(); i++){
        if(i != res2.size()){
            printf("%05d %d %05d\n", res2[i-1].ind, res2[i-1].data,res2[i].ind);
        }else{
            printf("%05d %d -1\n", res2[i-1].ind, res2[i-1].data);
        }
    }

    return 0;
}

/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854

00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/