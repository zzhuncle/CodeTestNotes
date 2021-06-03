//约数的个数 https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6
//穷举法
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    int ans;
    for (int k = 0;k < arr.size();k++) {
        int n = arr[k];
        ans = 0;
        int maxn = sqrt(n);
        if (maxn * maxn != n) maxn += 1;
        for (int i = 1;i < maxn;i++) {
            if (n % i == 0)
                ans += 2;
        }
        if (n % maxn == 0 && maxn * maxn == n)
            ans++;
        cout << ans << endl;
    }
    return 0;
}