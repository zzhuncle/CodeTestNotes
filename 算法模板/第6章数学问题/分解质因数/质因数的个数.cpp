//质因数的个数 https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
bool prime[MAX];
//素数筛法
bool judge(int n)
{
    bool flag = true;
    int MAX = sqrt(n);
    for (int i = 2;i < MAX + 1;i++)
        if (n % i == 0) {
            flag = false;
            break;
        }
    if (n == 1) 
        flag = false;//注意特例
    return flag;
}
int main()
{
    vector<int> pp;
    for (int i = 2;i < MAX;i++) {
        if (prime[i])
            continue;
        pp.push_back(i);
        for (int j = i * i;j < MAX;j += i)
            prime[j] = true;
    }
    int n, ans = 0;
    while (cin >> n) {
        int maxn = sqrt(n) + 1;
        for (int i = 0;i < pp.size() && pp[i] < maxn;i++) {
            while (n % pp[i] == 0) {
                n /= pp[i];
                ans++;
            }
        }
        if (n > 1)
            ans++;
        cout << ans << endl;
    }
    return 0;
}