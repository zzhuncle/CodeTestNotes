//快速幂 + 分治法
#include<bits/stdc++.h>
using namespace std;
int FastExp(int a, int b)
{
    int answer = 1;
    while (b != 0) {
        if (b % 2 == 1)
            answer *= a;
        b /= 2;
        a *= a;
    }
    return answer;
}
string dfs(int n)
{
    string ans = "";
    int i;
    if (n == 2)
        return "2";
    if (n == 0)
        return "0";
    while (n > 0) {
        for (i = 0;;i++)
            if (FastExp(2, i) >= n)
                break;
        if (FastExp(2, i) == n) {
            if (i == 1)
                ans += "2";
            else
                ans += "2(" + dfs(i) + ")";
            break;
        }
        else {
            if (i == 2)
                ans += "2+";
            else 
                ans += "2(" + dfs(i - 1) + ")+";
            n -= FastExp(2, i - 1);
        }
    }
    return ans;
}
int main()
{
    int num;
    while (cin >> num)
        cout << dfs(num) << endl;
    return 0;
}
