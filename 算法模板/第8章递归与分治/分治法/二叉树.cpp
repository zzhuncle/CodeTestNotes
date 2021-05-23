#include<bits/stdc++.h>
using namespace std;
int dfs(int m, int n)
{
    if (m > n)//递归出口
        return 0;
    if (m == n)//递归调用
        return 1;
    return 1 + dfs(2 * m, n) + dfs(2 * m + 1, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    while (cin >> m >> n) {//m是要求的结点 n是最后一个结点编号
        if (m == 0 && n == 0)
            return 0;
        cout << dfs(m , n) << endl;
    }
    return 0;
}
