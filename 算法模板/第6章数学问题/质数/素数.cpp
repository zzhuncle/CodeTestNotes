//素数 https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
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
    while (cin >> n) {
        for (int i = 0;i < pp.size() && pp[i] < n;i++) {
            if (pp[i] % 10 == 1)
                cout << pp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}