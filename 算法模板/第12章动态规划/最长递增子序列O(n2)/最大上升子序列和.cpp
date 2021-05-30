//最大上升子序列和 http://t.cn/AiYNAGD3
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
    int maxn = 0;
    for (int i = 0;i < n;i++) {
        dp[i] = arr[i];
        for (int j = 0;j < i;j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[j] + arr[i], dp[i]);
        maxn = max(maxn, dp[i]);
    }
    cout << maxn << endl;
    return 0;
}