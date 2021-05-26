//开门人和关门人 https://www.nowcoder.com/practice/a4b37b53a44d454ab0834e1517983215
//取巧使用map的字典序和映射特性
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    map<string, string> open;
    map<string, string> close;
    string tmp1, tmp2, tmp3;
    int n, i;
    while (cin >> n) {
        for (i = 0; i < n; i++) {
            cin >> tmp1 >> tmp2 >> tmp3;
            open.insert({tmp2, tmp1});
            close.insert({tmp3, tmp1});
        }
        cout << open.begin()->second << ' ' << close.rbegin()->second;
  }
  return 0;
}