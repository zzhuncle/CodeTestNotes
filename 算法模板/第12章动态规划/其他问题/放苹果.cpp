//??? https://www.nowcoder.com/practice/4f0c1e21010e4d849bde5297148e81d9
//??? ???
// dp ???????????????????????????????????????
// dp[m][n] ??m?n???
// ?n>m?? dp[m][n]=dp[m][m]
// dp[i][j]=dp[i-j][j]+dp[i][j-1]
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int C = 1;
    for (int i = 0;i < C;i++) {
        int m, n;
        cin >> m >> n;//m??? n???
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //dp[0][j]=1 dp[i][0]=0 dp[0][0]=1 dp[i][1]=dp[i-1][1]+dp[i][0]
        dp[0][0] = 1;
        for (int j = 0;j <= m;j++)
            for (int k = 1;k <= n;k++) {
                if (j >= k)
                    dp[j][k] = dp[j - k][k] + dp[j][k - 1];
                else
                    dp[j][k] = dp[j][k - 1];
            }
        cout << dp[m][n] << endl;
    }
    return 0;
}
