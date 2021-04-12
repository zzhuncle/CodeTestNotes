//最小生成树模版题
#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INF 1e6
//Prim算法
int cost[MAXN][MAXN];
int mincost[MAXN];
bool used[MAXN];
int V;
void Init(int n)
{
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cost[i][j] = INF;
        }
    }
    for (int i = 1;i <= n;i++)
        mincost[i] = INF;
    for (int i = 1;i <= n;i++)
        used[i] = false;
}
int Prim()
{
    mincost[1] = 0;
    int res = 0;
    while (1) {
        int v = 0;
        for (int u = 1;u <= V;u++)
            if (!used[u] && (v == 0 || mincost[u] < mincost[v]))
                v = u;
        if (v == 0) break;
        used[v] = true;
        res += mincost[v];
        for (int u = 1;u <= V;u++)
            mincost[u] = min(mincost[u], cost[v][u]);
    }
    return res;
}
int main()
{
    while (cin >> V) {
        if (V == 0) break;
        Init(V);
        for (int i = 0;i < V * (V - 1) / 2;i++) {
            int from, to, co;
            cin >> from >> to >> co;
            cost[from][to] = cost[to][from] = co;//注意是无向图，所以需要两个方向
        }
        cout << Prim() << endl;
    }
    return 0;
}