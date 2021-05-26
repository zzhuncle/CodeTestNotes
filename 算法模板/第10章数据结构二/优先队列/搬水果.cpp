//搬水果 https://www.nowcoder.com/practice/e4c775b0f3ee42a4bb72c26d2e1eef8a
//哈夫曼树
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0;i < n;i++) {
        cin >> temp;
        que.push(temp);
    }
    int res = 0;
    while (que.size() > 1) {
        int a = que.top();que.pop();
        int b = que.top();que.pop();
        que.push(a + b);
        res += a + b;
    }
    cout << res << endl;
    return 0;
}