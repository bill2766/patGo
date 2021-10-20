#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCard(int num){
    string out;
    switch ((num-1) / 13)
    {
    case 0:
        out+="S" + to_string((num-1)%13+1);
        break;
    case 1:
        out+="H" + to_string((num-1)%13+1);
        break;
    case 2:
        out+="C" + to_string((num-1)%13+1);
        break;
    case 3:
        out+="D" + to_string((num-1)%13+1);
        break;
    case 4:
        out+="J" + to_string((num-1)%13+1);
        break;
    }
    return out;
}

int main(){
    // cout<<getCard(54)<<endl;
    int k;
    cin>>k;

    int ord[55];
    string res[55];
    for(int i=1;i<=54;i++){
        res[i] = getCard(i);
    }
    string temp[55];
    for(int i=1;i<=54;i++){
        cin>>ord[i];
    }

    for(int i=0;i<k;i++){
        for(int j=1;j<=54;j++){
            temp[ord[j]] = res[j];
        }
        for(int m=1;m<=54;m++){
            res[m] = temp[m];
        }
    }

    for(int i=1;i<=54;i++){
        cout<<res[i];
        if(i != 54){
            cout<<" ";
        }
    }

    return 0;
}

/*
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47

S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
*/