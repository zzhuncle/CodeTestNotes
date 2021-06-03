//Prime Number https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415
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
    int n;
    while (cin >> n)
        cout << pp[n - 1] << endl;
    return 0;
}