//拦截导弹 http://t.cn/AiYCeV3m
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n , 0);
    vector<int> dp(n, 0);
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    int maxn = 1;
    for (int i = 0;i < n;i++) {
        dp[i] = 1;
        for (int j = 0;j < i;j++)
            if (arr[j] >= arr[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        maxn = max(maxn, dp[i]);
    }
    cout << maxn << endl;
    return 0;
}
