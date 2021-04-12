//(北大) I Wanna Go Home https://www.nowcoder.com/questionTerminal/0160bab3ce5d4ae0bb99dc605601e971

/*一开始没读懂题目，不明白那行1212之类的是干嘛的，后来才看见题目中有个最多只能转变1次阵营的限制
，由题意可知，M出发地是1号，目的地总是2号，从1-2必须转变一次阵营，所以就要求在这之前不能出现2-1的
情况，出现了就不符合题目的要求，所以就在Dijkstra中判断松弛条件的时候加一个判断语句就能求解了*/

#include<bits/stdc++.h>
using namespace std;
#define MAXV 601
#define INF 1e6

struct edge {int to, cost;};
typedef pair<int, int> P;

vector<edge> G[MAXV];
int leader[MAXV];
int d[MAXV];

int V;
void Kruscal(int s, int t)
{
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        for (int i = 0;i < G[v].size();i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost && (leader[v] != 2 || leader[e.to] != 1)) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    cout << (d[2] == INF ? -1 : d[2]) << endl;
    return; 
}

int main()
{
    int m;
    while (cin >> V) {
        if (V == 0)
            break;
        for (int i = 1;i <= V;i++)
            G[i].clear();
        fill(d + 1, d + V + 1, INF);
        cin >> m;
        int from, to, cost;
        for (int i = 1;i <= m;i++) {
            cin >> from >> to >> cost;
            G[from].emplace_back(edge{to, cost});
            G[to].emplace_back(edge{from, cost});
        }
        for (int i = 1;i <= V;i++) 
            cin >> leader[i];
        Kruscal(1, 2);
    }
    return 0;
}