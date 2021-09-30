#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> num;

    string numStr;
    cin>>numStr;
    for(int i=0;i<numStr.length();i++){
        num.push_back(numStr[i] - '0');
    }

    // for(int i=0;i<num.size();i++){
    //     cout<<num[i];
    // }

    vector<int> dou;
    int temp = 0;
    int carry = 0;
    for(int i=num.size()-1;i>=0;i--){
        temp = num[i] * 2 + carry;
        if(temp >= 10){
            dou.push_back(temp - 10);
            carry=1;
        }else{
            dou.push_back(temp);
            carry=0;
        }
    }
    reverse(dou.begin(),dou.end());
    if(carry == 1){
        dou.insert(dou.begin(),1,1);
    }

    int dic[10] = {0};
    for(int i=0;i<num.size();i++){
        dic[num[i]]++;
    }
    for(int i=0;i<dou.size();i++){
        dic[dou[i]]--;
    }

    bool check = true;
    for(int i=0;i<10;i++){
        if(dic[i] != 0){
            check = false;
            break;
        }
    }
    
    if(check==true){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    for(int i=0;i<dou.size();i++){
        cout<<dou[i];
    }
    
    return 0;
}

/*
1234567899

Yes
2469135798
*/