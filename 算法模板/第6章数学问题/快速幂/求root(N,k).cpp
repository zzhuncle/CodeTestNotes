/*
  1.首先是由于x^y可能很大，会超时，所以用快速幂算法。
如果y是偶数，那么指数减半底数平方；如果y是奇数，那么给最终的结果乘上x的一次方，这样能够求出x^y的结果res。
  2.再来看root（N，k），根据题意有N = a0 + a1*k + a2*k^2 +...
N' = a0 + a1 + a2+ ...
两式相减能够得到N-N'被k-1整除。
所以N' = N%(k-1)，但由于N'是在[0,k-1]之中，而N' = k-1这种情况会在N%(k-1)中算为0，所以加一个条件判断。
  3.quickpow 中还利用了数学上的定理(x * y) % k = (x % k) * (y % k) % k
*/
#include<bits/stdc++.h>
using namespace std;
long long quickpow(long long x, long long y, int k)
{
    long long ans = 1;
    while (y != 0) {
        if (y % 2) {
            ans *= x;
            ans %= (k - 1);
        }
        x *= x;
        x %= (k - 1);
        y /= 2;
    }
    return ans;
}
long long root(long long x, long long y, int k)
{
    long long ans = quickpow(x, y, k);
    return ans ? ans : k - 1;
}
int main()
{
    long long x, y;
    int k;
    while (cin >> x >> y >> k) {
        cout << root(x, y, k) << endl;
    }
    return 0;
}
