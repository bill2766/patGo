#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1, i-1);

    int n = stoi(s.substr(i+1));

    if (s[0] == '-') cout << "-";

    if (n < 0) {
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        //当n>0时候表示向后移动，那么先输出第一个字符，然后将t中尽可能输出n个字符，
        //如果t已经输出到最后一个字符(j == t.length())那么就在后面补n-cnt个0，
        //否则就补充一个小数点,然后继续输出t剩余的没有输出的字符～
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}