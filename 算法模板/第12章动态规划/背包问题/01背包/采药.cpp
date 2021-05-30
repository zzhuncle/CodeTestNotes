//采药 https://www.nowcoder.com/practice/d7c03b114f0541dd8e32ce9987326c16
#include<bits/stdc++.h>
using namespace std;
int main()  
{
    int c, n;
    while (cin >> c >> n) {
        vector<int> v(n, 0);
        vector<int> p(n, 0);
        for (int i = 0;i < n;i++)
            cin >> p[i] >> v[i];
        vector<int> dp(c + 1, 0);
        for (int i = 1;i <= n;i++)
            for (int j = c;j >= p[i - 1];j--)
                dp[j] = max(dp[j], dp[j - p[i - 1]] + v[i - 1]);
        cout << dp[c] << endl;
    }
    return 0;
}