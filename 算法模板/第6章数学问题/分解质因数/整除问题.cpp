//整除问题 https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
bool nprime[MAX] = { false };
int main()
{
    //首先使用素数筛法求出所有素数
    vector<int> pp;
    for (int i = 2;i < MAX;i++) {
        if (nprime[i])
            continue;
        pp.push_back(i);
        for (int j = i * i;j < MAX;j += i)
            nprime[j] = true;
    }
    int size = pp.size();
    int n, a;
    cin >> n >> a;
    map<int, int> ma, mn;
    //求整数a的质因数分解
    for (int i = 0;i < size && pp[i] <= a;i++) {
        while (a % pp[i] == 0) {
            a /= pp[i]; 
            ma[pp[i]]++;
        }
    }
    //求整数n的阶乘的质因数分解
    for (int i = 0;i < size && pp[i] <= n;i++) {
        int base = pp[i];
        while (n / base) {
            mn[pp[i]] += n / base;
            base *= pp[i];
        }
    }
    //计算最大的k
    int k = INT_MAX;
    for (auto iter = ma.begin();iter != ma.end();iter++) {
        int num = iter->first, cnt = iter->second;
        if (cnt > mn[num]) {
            cout << -1 << endl;
            return 0;
        }
        k = min(mn[num] / cnt, k);
    }
    cout << k << endl;
    return 0;
}
