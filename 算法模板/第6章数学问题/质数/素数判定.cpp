//素数判定 https://www.nowcoder.com/practice/5fd9c28b1ce746dd99287a04d8fa9002
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        bool flag = true;
        int MAX = sqrt(n);
        for (int i = 2;i < MAX + 1;i++)
            if (n % i == 0) {
                flag = false;
                break;
            }
        if (n == 1) flag = false;//注意特例
        cout << (flag ? "yes" : "no") << endl; 
    }
    return 0;
}
