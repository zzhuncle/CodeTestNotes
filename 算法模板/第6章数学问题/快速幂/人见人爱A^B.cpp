//人见人爱A^B https://vjudge.net/problem/HDU-2035
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000;
int FastFactor(int a, int b)
{
    int t = 1;//初始化为1
    while (b != 0) {//不断将b转化为二进制数
        if (b % 2 == 1) {//若当前位为1，累乘a的2^k次幂
            t *= a;
            t %= mod;//求后三位
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    return t;
}
int main()
{
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            return 0;
        cout << FastFactor(a, b) << endl;
    }
    return 0;
}
