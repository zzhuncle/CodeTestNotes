//谁是你的潜在朋友 https://www.nowcoder.com/practice/0177394fb25b42b48657bc2b1c6f9fcc
#include<bits/stdc++.h>
using namespace std;
map<int, int> stu;
map<int, int> book;
int main()
{
    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0;i < n;i++) {
        cin >> t;
        stu[i] = t;
        book[t]++;
    }
    for (int i = 0;i < n;i++) {
        if (book.find(stu[i]) != book.end()) {
            if (book[stu[i]] > 1)
                cout << book[stu[i]] - 1 << endl;
            else 
                cout << "BeiJu" << endl;
        }
        else
            cout << "BeiJu" << endl;
    }
    return 0;
}