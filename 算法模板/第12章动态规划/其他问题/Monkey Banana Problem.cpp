//Monkey Banana Problem https://lightoj.com/problem/monkey-banana-problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int cnt = 1;cnt <= N;cnt++) {
        int n;
        cin >> n;
        vector<vector<int>> data(2 * n - 1, vector<int>(n, 0));
        vector<vector<int>> dp(2 * n - 1, vector<int>(n, 0));
        for (int i = 0;i < n;i++)
            for (int j = 0;j <= i;j++)
                cin >> data[i][j];
        for (int i = n;i < 2 * n - 1;i++)
            for (int j = 0;j <= 2 * (n -  1) - i;j++)
                cin >> data[i][j];
        for (int i = 2 * (n - 1);i >= n - 1;i--)
            for (int j = 0;j <= 2 * (n - 1) - i;j++) {
                if (i == 2 * (n - 1))
                    dp[i][j] = data[i][j];
                else if (j == 0)
                    dp[i][j] = data[i][j] + dp[i + 1][j];
                else if (j == 2 * (n - 1) - i)
                    dp[i][j] = data[i][j] + dp[i + 1][j - 1];
                else 
                    dp[i][j] = data[i][j] + max(dp[i + 1][j], dp[i + 1][j - 1]);
            }
        for (int i = n - 2;i >= 0;i--)
            for (int j = 0;j <= i;j++)
                dp[i][j] = data[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        cout << "Case " << cnt << ": " << dp[0][0] << endl;
    }
    return 0;
}