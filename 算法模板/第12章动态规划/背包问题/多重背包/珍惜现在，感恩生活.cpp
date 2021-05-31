//珍惜现在，感恩生活 https://vjudge.net/problem/HDU-2191
//多重背包问题 将多重背包转化为01背包
#include<bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main()
{
    int N;
    cin >> N;
    for (int cnt = 0;cnt < N;cnt++) {
        int n, m;
        cin >> n >> m;
        int k = 0;
        vector<int> p;
        vector<int> w;
        int pp, ww, nn;
        for (int i = 0;i < m;i++) {
            cin >> pp >> ww >> nn;
            for (int j = 1;j <= nn;j << 1) {
                p.push_back(j * pp);
                w.push_back(j * ww);
                nn -= j;
            }
            if (nn > 0) {
                p.push_back(nn * pp);
                w.push_back(nn * ww);
            }
        }
        m = p.size();
        //dp[i][j] 前i种物品j元的最大重量
        //至此转化为01背包问题
        vector<int> dp(n + 1, 0);
        for (int i = 0;i < m;i++)
            for (int j = n;j >= p[i];j--) 
                dp[j] = max(dp[j], dp[j - p[i]] + w[i]);
        cout << dp[n] << endl;
    }
    return 0;
}