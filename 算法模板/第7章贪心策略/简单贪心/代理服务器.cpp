// 代理服务器 https://www.nowcoder.com/practice/1284469ee94a4762848816a42281a9e0
/** 其实就是想要尽可能使用和要访问服务器没有交集的代理服务器。
如果要访问的服务器中没有和代理服务器 IP 相同的，返回 0
如果有相同的，那么每个代理服务器都在某一个位置相同，比如例子中的分别在 1、4、2 处相同，那么贪心策略取最远相同的，然后对剩下的再次进行判断即可。
因为服务器 IP 没有说明是否不重复，所以一个代理服务器 IP 可能在多个位置与要访问的服务器 IP 相同，所以取最远的位置其实是第一次相同时的最远位置。然后更新遍历 sever 的起始地址，直到遍历完全。
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<string>& agents,vector<string>& servers,int m)
{
    int j = 0, res = 0;
    while (j < m) {
        int maxn = 0, index = j;
        for (string &s1 : agents) {
            j = index;
            for (int k = index;k < m;k++) {
                if (servers[k] == s1)
                    break;
                j++;
            }
            maxn = max(maxn, j - index);
        }
        if (maxn == 0)
            return -1;
        res++;
        j = index + maxn;
    }
    return res - 1;
}
int main()
{
    int n, m;
    while (cin >> n) {
        vector<string> agents(n);
        for (int i = 0;i < n;i++)
            cin >> agents[i];
        cin >> m;
        vector<string> servers(m);
        for (int i = 0;i < m;i++)
            cin >> servers[i];
        cout << solve(agents, servers, m) << endl;
    }
    return 0;
}