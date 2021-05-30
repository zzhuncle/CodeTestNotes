//合唱队形 http://t.cn/AiYNyHPe
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int heights1[MAXN];
int heights2[MAXN];
int dp1[MAXN];//求出以每一个点结尾的从前往后最长递增子序列
int dp2[MAXN];//求出以每一个点结尾的从后往前最长递增子序列+

int main()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> heights1[i];
        heights2[n - i + 1] = heights1[i];
    }
    for (int i = 1;i <= n;i++) {
        dp1[i] = dp2[i] = 1;
        for (int j = 1;j < i;j++) {
            if (heights1[j] < heights1[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
            if (heights2[j] < heights2[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);            
        }
    }
    int maxn = INT_MIN;
    for (int i = 1;i <= n;i++) {
        dp1[i] += dp2[n - i + 1];
        maxn = max(maxn, dp1[i]);
    }
    cout << n - maxn + 1 << endl;
    return 0;
}
