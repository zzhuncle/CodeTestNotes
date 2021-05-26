//子串计算 https://www.nowcoder.com/practice/bcad754c91a54994be31a239996e7c11
#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            mp[str.substr(j, i - j)]++;
        }
    }
    for (auto it : mp) {
        if (it.second > 1)
            cout << it.first << " " << it.second << endl;
    }
    return 0;
}