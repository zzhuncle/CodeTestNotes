//Piggy-Bank https://vjudge.net/problem/HDU-1114
//完全背包问题
#include<bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main()
{
    int N;
    cin >> N;
    for (int cnt = 0; cnt < N; cnt++) {
        int n, t1, t2;
        cin >> t1 >> t2;
        int weight = t2 - t1;
        cin >> n;
        vector<int> p(n, 0);
        vector<int> w(n, 0);
        vector<int> dp(weight + 1, INF);
        dp[0] = 0;//初始化
        for (int i = 0; i < n; i++)
            cin >> p[i] >> w[i];
        for (int i = 0; i < n; i++)
            for (int j = w[i]; j <= weight; j++)
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
        if (dp[weight] == INF)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[weight] << "." << endl;

    }
    return 0;
}
