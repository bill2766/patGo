#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (string::iterator it = n.begin(); it != n.end(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}

long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    //dig的最大值+1为low
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    //进制的最大情况
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        //t<0时 溢出
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    // cout<<convert("110",2);
    return 0;
}