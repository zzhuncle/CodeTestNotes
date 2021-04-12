//8皇后问题 https://www.nowcoder.com/practice/fbf428ecb0574236a2a0295e1fa854cb
//定义一个皇后串a与之对应，即a = b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数
//每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void dfs(int depth, string str)
{
    if (depth == 8) {
        ans.push_back(str);
        return;
    }
    for (int i = 1;i <= 8;i++) {
    	bool flag = true;
        for (int j = 0;j < depth;j++) //第j + 1行第str[j] - '0'列 //第depth + 1行第i列 
            if (i == str[j] - '0' || abs(j + 1 - (depth + 1)) == abs(str[j] - '0' - i)) {
                flag = false;
                break;
            }
    	if (flag)
        	dfs(depth + 1, str + char('0' + i));
    }
}
int main()
{
    int n, temp;
    string str = "";
    dfs(0, str);
    while (cin >> temp)
        cout << ans[temp - 1] << endl;
    return 0;
}