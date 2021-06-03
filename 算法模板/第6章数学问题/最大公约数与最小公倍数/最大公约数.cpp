//最大公约数 https://www.nowcoder.com/practice/20216f2c84bc438eb5ef05e382536fd3
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int a, b;
    while (cin >> a >> b) {
        if (a < b) {
            int t = a;
            a = b;
            b = t;
        }
        cout << gcd(a, b);
    }
    return 0;
}