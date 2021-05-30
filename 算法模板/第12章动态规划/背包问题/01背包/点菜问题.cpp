//点菜问题 http://t.cn/AiYOrkXr
//dp[i][j]表示前i个物品装进容量为j的背包能获得的最大价值
//dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i])
//仅与二维数组中本行的上一行有关
//dp[i][j] = max(dp[j],dp[j-w[i]]+v[i])
//为了保证状态正确转移，必须保证在每次更新中确定状态dp[j]时,
//   dp[j-w[i]]尚未被本次更新修改，因此需要倒序遍历j的所有值
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