//最简真分数 https://www.nowcoder.com/practice/1f1db273eeb745c6ac83e91ff14d2ec9
//注意最简真分数
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int n, ans;
    while (cin >> n) {
        ans = 0;
        if (n == 0)
            break;
        vector<int> arr(n, 0);
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (arr[i] < arr[j])
                    if (gcd(arr[j], arr[i]) == 1)
                        ans++;
        cout << ans << endl;
    }
    return 0;
}