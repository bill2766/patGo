////////////////////////////////////
//不知道为什么，这个代码在本机上运行不了//
////////////////////////////////////
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_N = 21;

int N;
struct Node{
    string data;
    int parent;
    int left_child;
    int right_child;
    Node():parent(-1){}
}nodes[MAX_N];
int parind;

string ans;
void inorder(int root){
    if(root == -1) return;
    int left = nodes[root].left_child;
    int right = nodes[root].right_child;

    if(right != -1){
        ans+="(";
    }
    inorder(left);
    ans+=nodes[root].data;
    inorder(right);
    if(right != -1){
        ans+=")";
    }
}

int main(){
    scanf("%d",&N);
    string da;
    int left, right;
    for(int i=1;i<=N;i++){
        cin>>da>>left>>right;
        nodes[i].data = da;
        nodes[i].left_child = left;
        nodes[i].right_child = right;
        nodes[left].parent = i;
        nodes[right].parent = i;
    }

    parind = 1;
    while(nodes[parind].parent != -1) parind = nodes[parind].parent;
 
    inorder(parind);
    
    if(ans[0] == '(') ans = ans.substr(1,ans.size()-2);
    cout<<ans;
    return 0;
}

/*
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1

(a+b)*(c*(-d))


8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1

(a*2.35)+(-(str%871))
*/