//最小生成树模版题
#include<bits/stdc++.h>
using namespace std;
#define INF 1e6
//Kruscal算法
int V;
struct edge {
    int from;
    int to;
    int cost;
    bool operator<(const edge& b) const {
        return cost < b.cost;
    }
};
int father[100];
int height[100];
edge edges[10001];
void Init(int n)
{
    for (int i = 1;i <= n;i++) {
        father[i] = i;
        height[i] = 1;
    }
}
int Find(int x)
{
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y])
            father[x] = y;
        else if (height[y] < height[x])
            father[y] = x;
        else {
            height[x]++;
            father[y] = x;
        }
    }
}
int Kruscal()
{
    Init(V);
    int res = 0;
    int n = V * (V - 1) / 2;
    sort(edges, edges + n);
    for (int i = 0;i < n;i++) {
        edge current = edges[i];
        if (Find(current.from) != Find(current.to)) {
            Union(current.from, current.to);
            res += current.cost;
        }
    }
    return res;
}
int main()
{
    while (cin >> V) {
        if (V == 0) break;
        Init(V);
        int n = V * (V - 1) / 2;
        for (int i = 0;i < n;i++)
            cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        cout << Kruscal() << endl;
    }
    return 0;
}