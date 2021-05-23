//杨辉三角形 https://www.nowcoder.com/practice/ef7f264886a14fdf8a6ed3ac008a23c8
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int solve(int m, int n)
{
    if (dp[m][n] != 0)
        return dp[m][n];
    if (n == 0 || m == n)
        return dp[m][n] = 1;
    return dp[m][n] = dp[m - 1][n - 1] + dp[m - 1][n];
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1;i < n;i++) {
            for (int j = 0;j <= i;j++) {
                cout << solve(i, j) << " ";
                if (j == i)
                    cout << endl; 
            }
        }
    }
    return 0;
}