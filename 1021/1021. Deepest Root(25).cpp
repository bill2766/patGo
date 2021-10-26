#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 10010;

int n;

struct Node{
    vector<int> conns;
}nodes[MAX_N];

int maxdeep = 0;
vector<int> temp;
set<int> res;

bool visited[MAX_N];

void dfs(int root, int deep){
    visited[root] = true;
    if(maxdeep < deep){
        maxdeep = deep;
        temp.clear();
        temp.push_back(root);
    }else if(maxdeep == deep){
        temp.push_back(root);
    }

    for(int i=0;i<nodes[root].conns.size();i++){
        if(visited[nodes[root].conns[i]] == false){
            dfs(nodes[root].conns[i],deep+1);
        }
    }
}


int main(){
    scanf("%d",&n);

    int v1, v2;
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&v1,&v2);
        nodes[v1].conns.push_back(v2);
        nodes[v2].conns.push_back(v1);
    }

    fill(visited,visited+n+1,false);
    int s1;
    int compon = 0;
    for(int v=1;v<=n;v++){
        if(visited[v] == false){
            compon++;
            dfs(v,1);
        }
    }
    
    if(compon >= 2){
        printf("Error: %d components",compon);
    }else{
        //将temp的第一个结点作为第二次dfs的起点（其实在temp任取一个都可以）
        // 为了重用temp，先将其中的所有元素加入到res中
        for(int i=0;i<temp.size();i++){
            res.insert(temp[i]);
        }
        s1 = temp[0];

        // 第二次遍历
        //为什么2次遍历？因为第一次遍历的主要目的是找到连通分量的个数，temp的结果可能是一部分点，
        //借助第二次遍历，可以利用这一部分点将边的另一边的点全部找到
        // 记得清空temp
        temp.clear();
        fill(visited,visited+n+1,false);
        dfs(s1,1);
        // 将第二次遍历的temp加入到res中
        for(int i=0;i<temp.size();i++){
            res.insert(temp[i]);
        }

        //输出结果
        for(set<int>::iterator it =res.begin();it!= res.end();it++){
            printf("%d",*it);
            if(it != --res.end()) printf("\n");
        }
    }


    return 0;
}

/*
5
1 2
1 3
1 4
2 5

3
4
5


5
1 3
1 4
2 5
3 4

Error: 2 components
*/