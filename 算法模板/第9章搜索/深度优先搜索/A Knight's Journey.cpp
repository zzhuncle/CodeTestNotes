//A Knight's Journey http://poj.org/problem?id=2488
//dfs多使用递归实现
//注意遍历分支的顺序实现字典序，以及行列不要弄混
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define MAXN 31
//  A B C
//1
//2
//3
int p, q;                //棋盘的长和宽
// y从左到右, x从上到下进行变化，可以满足字典序
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
bool visited[MAXN][MAXN];//走过标志

bool dfs(int x, int y, int step, string res)
{
    if (step == p * q) {
        cout << res << endl;
        return true;
    }
    for (int i = 0;i < 8;i++) {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx < 0 || fx >= p || fy < 0 || fy >= q || visited[fx][fy])
            continue;
        visited[fx][fy] = true;
        char sx = '1' + fx, sy = 'A' + fy;
        if (dfs(fx, fy, step + 1, res + sy + sx))
            return true;
        visited[fx][fy] = false;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, caseNumber = 0;
    string res;
    cin >> n; 
    for (int i = 0;i < n;i++) {
        cout << "Scenario #" << ++caseNumber << ":" << endl;
        cin >> p >> q;
        memset(visited, false, sizeof(visited));
        visited[0][0] = true;
        res = "A1";
        if (!dfs(0, 0, 1, res))
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}
