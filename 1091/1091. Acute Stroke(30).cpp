#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_L = 61;
const int MAX_M = 1288;
const int MAX_N = 130;

int ss[6] = {1, 0, 0, -1, 0, 0};
int aa[6] = {0, 1, 0, 0, -1, 0};
int bb[6] = {0, 0, 1, 0, 0, -1};

int m,n,l,t;
int slices[MAX_L][MAX_M][MAX_N];
bool visited[MAX_L][MAX_M][MAX_N];

int sum = 0;

struct node{
    int slice;
    int a;
    int b;
    node(int slice,int a,int b):slice(slice),a(a),b(b){}
    node():slice(0),a(0),b(0){}
};

bool judge(int slice, int a, int b){
    if(slice<0 || slice>=l || a<0 || a>=m || b<0 || b>=n) return false;
    if(slices[slice][a][b] == 0 || visited[slice][a][b] == true) return false;
    return true;
}

//bfs
int getTotal(int slice, int a, int b){
    int out = 0;
    node* nodes;
    
    queue<node> q;
    q.push(node(slice,a,b));
    visited[slice][a][b] = true;

    node temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        out++;
        for(int i=0;i<6;i++){
            int tslice = temp.slice + ss[i];
            int ta = temp.a + aa[i];
            int tb = temp.b + bb[i];
            if(judge(tslice,ta,tb)){
                visited[tslice][ta][tb] = true;
                q.push(node(tslice,ta,tb));
            }
        }
        delete nodes;
    }
    if(out >= t){
        return out;
    }else{
        return 0;
    }
    
}

int main(){
    cin>>m>>n>>l>>t;

    //获得值
    for(int slice = 0; slice<l;slice++){
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                cin>>slices[slice][a][b];
            }
        }
    }

    for(int slice = 0; slice<l;slice++){
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                if(slices[slice][a][b] == 1 && visited[slice][a][b] == false){
                    sum += getTotal(slice,a,b);
                }
            }
        }
    }
    
    cout<<sum;
    return 0;
}


/*
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0

26
*/