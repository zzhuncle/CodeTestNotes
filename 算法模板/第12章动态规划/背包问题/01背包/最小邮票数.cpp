//最小邮票数 https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1
// dp[i][j]表示只用前i种邮票能凑成总值M的最少邮票数，如果凑不成为INF
// dp[0][j] = INF
// dp[i][0] = 0
/*  
    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - p[i]] + 1)
*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main()  
{
    int M, n;
    while (cin >> M >> n) {
        vector<int> p(n, 0);
        for (int i = 0;i < n;i++)
            cin >> p[i];
        vector<int> dp(M + 1, INF);
        dp[0] = 0;
        for (int i = 0;i < n;i++)
            for (int j = M;j >= p[i];j--)
                dp[j] = min(dp[j], dp[j - p[i]] + 1);
        cout << (dp[M] == INF ? 0 : dp[M]) << endl;
    }
    return 0;
}