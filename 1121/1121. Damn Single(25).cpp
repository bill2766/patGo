#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,m;
vector<int> couples(100000);
set<int> peos;

int main(){
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        couples[i] = -1;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        couples[a] = b;
        couples[b] = a;
    }

    scanf("%d",&m);
    int peo;
    for(int i=0;i<m;i++){
        scanf("%d",&peo);
        peos.insert(peo);
    }

    set<int> del;
    set<int>::iterator cc;
    for(set<int>::iterator it=peos.begin(); it!=peos.end(); it++){
        if(couples[*it] != -1){
            cc = peos.find(couples[*it]);
            //找到了couple
            if(cc != peos.end()){
                del.insert(*cc);
                del.insert(*it);
            }
        }
    }
    for(set<int>::iterator it=del.begin(); it!=del.end(); it++){
        peos.erase(*it);
    }

    cout<<peos.size()<<endl;
    for(set<int>::iterator it=peos.begin();it!=peos.end();it++){
        printf("%05d",*it);
        if(it != --peos.end()){
            cout<<" ";
        }
    }

    return 0;
}

/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

5
10000 23333 44444 55555 88888
*/

/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 33333 22222 11111 23333

3
10000 23333 55555
*/