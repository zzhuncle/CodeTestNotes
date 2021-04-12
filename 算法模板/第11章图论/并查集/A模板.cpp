/* 并查集主要用来判断图是否为联通图，或用来求图的联通分量。 */
#include<iostream>
using namespace std;
#define MAXN 1000
int father[MAXN];
int height[MAXN];//只有根节点保留着高度信息

//初始化
void Initial(int n)
{
    for (int i = 0;i < n;i++) {
        father[i] = i;
        height[i] = 1;
    }
}

//查询
int Find(int x)
{
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

//合并
int Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (height[x] < height[y]) {
        father[x] = y;
    }
    else if (height[x] > height[y]) {
        father[y] = x;
    }
    else {
        father[y] = x;
        height[x]++;
    }
    return;
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        if (n == 0)
            break;
        Initial(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int ans = -1;
        for (int i = 1;i <= n;i++) {
            if (Find(i) == i) 
                ans++;
        }
        cout << ans << endl;
    }
}