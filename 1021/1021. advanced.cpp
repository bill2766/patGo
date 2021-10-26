#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define maxN 10001
using namespace std;

bool marked[maxN];
vector<int> graph[maxN];
int maxHeight = 0;
vector<int> depthestNodes;
// 使用set，避免加入重复元素
set<int> points;

void dfs(int v, int height){
    marked[v] = true;
    if(height > maxHeight){
        depthestNodes.clear();
        depthestNodes.push_back(v);
        maxHeight = height;
    }else if(height == maxHeight){
        depthestNodes.push_back(v);
    }
    for(auto lt = graph[v].cbegin(); lt != graph[v].cend(); lt++){
        if(marked[*lt] == false){
            dfs(*lt, height + 1);
        }
    }
}
using namespace std;
int main() {
    int n, u, v;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fill(marked, marked + maxN, false);
    int count = 0;
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(marked[i] == false){
            dfs(i, 1);
            count++;
        }
    }
    if(count > 1){
        printf("Error: %d components", count);
    }else{
        fill(marked, marked + maxN, false);
        maxHeight = 0;
        //将depthestNodes的第一个结点作为第二次dfs的起点（其实在depthestNodes任取一个都可以）
        // 为了重用depthestNodes，先将其中的所有元素加入到points中
        for(auto lt = depthestNodes.cbegin(); lt != depthestNodes.cend(); lt++){
            points.insert(*lt);
        }
        s = depthestNodes[0];
        
        // 第二次遍历
        // 记得清空depthestNodes
        depthestNodes.clear();
        dfs(s, 1);
        // 将第二次遍历的depthestNodes加入到points中
        for(auto lt = depthestNodes.cbegin(); lt != depthestNodes.cend(); lt++){
            points.insert(*lt);
        }
        
        // 输出结果
        for(auto lt = points.cbegin(); lt != points.cend(); lt++){
            printf("%d\n", *lt);
        }
    }
    
    return 0;
}
