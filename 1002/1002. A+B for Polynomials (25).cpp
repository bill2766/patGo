#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int,double> mp;

    int n; //数量
    //指数和系数
    int n_k;
    double a_nk;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>n_k>>a_nk;
        mp[n_k] = a_nk;
        // cout<<"n_k:"<<n_k<<" mp[n_k]"<<mp[n_k]<<endl;
    }

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>n_k>>a_nk;
        mp[n_k] += a_nk;
        //如果有0，消去
        if(mp[n_k] == 0){
            mp.erase(n_k);
        }
    }

    int totalNum = mp.size();
    cout<<totalNum;
    //如果为0则退出
    if(totalNum == 0){
        return 0;
    }else{
        cout<<" ";
    }

    //打印多项式
    for(map<int,double>::iterator it = --mp.end();;it--){
        printf("%d %.1f",it->first,it->second); //first键，second值
        if(it == mp.begin()){
            break;
        }else{
            printf(" ");
        }
    }

    return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/

//3 2 1.5 1 2.9 0 3.2