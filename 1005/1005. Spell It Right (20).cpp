#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

//---------------------------这个部分正确，可能是因为不能承受太大的数的原因

// string getEng(int n){
//     switch (n)
//     {
//     case 0:
//         return "zero";
//         break;
//     case 1:
//         return "one";
//         break;
//     case 2:
//         return "two";
//         break;
//     case 3:
//         return "three";
//         break;
//     case 4:
//         return "four";
//         break;
//     case 5:
//         return "five";
//         break;
//     case 6:
//         return "six";
//         break;
//     case 7:
//         return "seven";
//         break;
//     case 8:
//         return "eight";
//         break;
//     case 9:
//         return "night";
//         break;
//     default:
//         return "non";
//     }
// }

// int main(){
//     long long N = 0;
//     scanf("%d",&N);

//     int sum = 0;
//     while(N != 0){
//         sum += N%10;
//         N = (N - N % 10) / 10;
//     }

//     // printf("%d\n",sum);
//     stack<int> st;
//     if(sum == 0){
//         printf("zero");
//     }else{
//         while(sum != 0){
//             st.push(sum % 10);
//             sum = (sum - sum % 10) / 10;
//         }

//         while(!st.empty()){
//             cout<<getEng(st.top());
//             if(st.size() != 1){
//                 cout<<" ";
//             }
//             st.pop();
//         }
//     }

//     return 0;
// }

//12345

//one five

//这里使用优解
int main(){
    string num;
    cin>>num;

    int sum = 0;
    for(int i=0; i<num.length(); i++){
        sum+= (num[i]-'0');
    }

    string strSum = to_string(sum);
    string eng[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    cout<<eng[strSum[0]-'0'];
    for(int i=1; i<strSum.length(); i++){
        cout<<" "<<eng[strSum[i]-'0'];
    }
    return 0;
}