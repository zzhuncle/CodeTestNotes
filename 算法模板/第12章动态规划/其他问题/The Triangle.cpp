//The Triangle http://poj.org/problem?id=1163
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > data(n, vector<int>(n, 0));
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int i = 0;i < n;i++)
        for (int j = 0;j <= i;j++)
            cin >> data[i][j];
    for (int i = n - 1;i >= 0;i--)
        for (int j = 0;j <= i;j++) {
            if (i == n - 1)
                dp[i][j] = data[i][j];
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    cout << dp[0][0] << endl;
    return 0;
}