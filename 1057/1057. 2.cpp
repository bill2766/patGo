#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int MAX_N = 100000;
const int SQRT_N = 317;
int table[MAX_N];
int block[SQRT_N];
stack<int> s;

void push(int val){
    s.push(val);
    table[val]++;
    block[val / SQRT_N]++;
}

int pop(){
    int out = s.top();
    s.pop();
    table[out]--;
    block[out / SQRT_N]--;
    return out;
}

int peekMedian(){
    //对奇偶数普遍
    int median = (s.size()+1) / 2;
    int i=0, curNum=0;

    //这里是提高查询速度的地方
    while(curNum + block[i] < median){
        curNum+=block[i];
        i++;
    }

    int j = i * SQRT_N;
    while(curNum + table[j] < median){
        curNum+=table[j];
        j++;
    }
    
    //curNum数目达到后，返回index（也就是答案）
    return j;
}

int main(){
    int N;
    cin>>N;
    string command;
    for(int i=0;i<N;i++){
        cin>>command;
        if(command[1] == 'u'){
            int val;
            cin>>val;
            push(val);
        }else if(command[1] == 'o'){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                cout<<pop()<<endl;
            }
        }else{
            if(s.empty()){
                printf("Invalid\n");
            }else{
                cout<<peekMedian()<<endl;
            }
        }
    }

    return 0;
}

/*
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/