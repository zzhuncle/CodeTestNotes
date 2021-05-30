//找到两个字符串的最长公共子串 https://www.nowcoder.com/practice/f38fc44b43cf44eaa1de407430b85e69
//设置一个二维数组dp[n][m],令dp[i][j]表示以s1[i]作为末尾和s2[j]作为末尾的最长公共子序列的长度
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    while (cin >> s1 >> s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));//二维数组
        for (int i = 0;i <= n1;i++) {
            for (int j = 0;j <= n2;j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    if (s1[i - 1] == s2[j - 1])
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    else 
                        dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        cout << dp[n1][n2] << endl;
    }
    return 0;
}
