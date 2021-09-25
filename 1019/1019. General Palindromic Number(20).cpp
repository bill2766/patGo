#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, b;

vector<int> tenToB(int N, int b){
    vector<int> out;
    while(N != 0){
        out.push_back(N % b);
        N /= b;
    }
    reverse(out.begin(),out.end());
    return out;
}

int main(){
    scanf("%d %d",&N,&b);

    if(N == 0){
        printf("Yes\n");
        printf("0");
        return 0;
    }

    vector<int> toB = tenToB(N,b);

    bool isPN = true;
    int i=0;
    int j = toB.size()-i-1;
    while(i <= toB.size() / 2){
        if(toB[i] == toB[j]){
            i++;
            j--;
            continue;
        }else{
            isPN = false;
            break;
        }
    }

    if(isPN){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    
    for(int i=0; i<toB.size();i++){
        cout<<toB[i];
        if(i != toB.size()-1){
            cout<<" ";
        }
    }
    return 0;
}

/*
27 2

Yes
1 1 0 1 1
*/

/*
121 5

No
4 4 1
*/