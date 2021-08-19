#include <iostream>
using namespace std;
int main() {
    //读取两个数
    int a, b;
    cin >> a >> b;

    //变成string
    string s = to_string(a + b);
    //获得长度
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    return 0;
}