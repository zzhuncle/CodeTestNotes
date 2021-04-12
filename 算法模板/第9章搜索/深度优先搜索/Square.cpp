//(北大) Square http://poj.org/problem?id=2362
//必须排序增加剪枝环节，否则会超时
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int sticks[21];
bool visited[21];
int side;
int m;

bool cmp(int x, int y)
{
    return x > y;
}
//sum 当前拼凑的木棍长度
//number 已拼凑的边长的数量
//position 当前木棍的编号
bool dfs(int sum, int number, int position)
{
    if (number == 3)
        return true;
    int sample = 0;//已经失败的木棒
    for (int i = position;i < m;i++) {
        if (visited[i] || sum + sticks[i] > side || sticks[i] == sample)
            continue;
        visited[i] = true;
        if (sum + sticks[i] == side) {
            if (dfs(0, number + 1, 0))
                return true;
            else 
                sample = sticks[i];
        }
        else {
            if (dfs(sum + sticks[i], number, i + 1))
                return true;
            else 
                sample = sticks[i];
        }
        visited[i] = false;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int total = 0;
        cin >> m;
        memset(visited, false, sizeof(visited));
        for (int j = 0;j < m;j++) {
            cin >> sticks[j];
            total += sticks[j];    
        }
        if (total % 4) {
            cout << "no" << endl;
            continue;
        }
        side = total / 4;
        sort(sticks, sticks + m, cmp);
        if (sticks[0] > side) {
            cout << "no" << endl;
            continue;
        }
        cout << (dfs(0, 0, 0) ? "yes" : "no") << endl;
    }
    return 0;
}