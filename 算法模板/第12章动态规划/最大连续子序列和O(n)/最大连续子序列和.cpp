//最大连续子序列和 http://t.cn/AiYSlQMU
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    while (cin >> n) {
        ll ans = INT_MIN;
        vector<ll> dp(n + 1, 0);
        for (int i = 1;i <= n;i++)
            cin >> dp[i];
        for (int i = 2;i <= n;i++) 
            dp[i] = max(dp[i], dp[i] + dp[i - 1]);
        for (int i = 1;i <= n;i++)
            ans = max(dp[i], ans);
        cout << ans << endl;
    }
    return 0;
}