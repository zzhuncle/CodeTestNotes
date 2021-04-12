//(浙大) 最短路径问题 https://www.nowcoder.com/practice/e372b623d0874ce2915c663d881a3ff2
//注意两个节点之间可能有多条边，如果采用邻接矩阵可能更新错误，而采用邻接表则没有问题
#include<bits/stdc++.h>
#define MAXV 100001
#define INF 1e6

using namespace std;
struct edge {int to, len, cost;};//边结构体
typedef pair<int, int> P;        //点结构体

vector<edge> G[MAXV];            //邻接表实现的图
int d[MAXV];                     //源点到各点的距离
int cost[MAXV];                  //记录花费

void dijkstra(int s, int t)
{
    //通过指定greater<P>参数，堆按照first从小到大的顺序取出值
    priority_queue<P, vector<P>, greater<P> > que;
    d[s] = 0;
    cost[s] = 0;
    que.push(P(0, s));
    
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        for (int i = 0;i < G[v].size();i++) {
            edge e = G[v][i];
            if ((d[e.to] == d[v] + e.len && cost[e.to] > cost[v] + e.cost)||
                d[e.to] > d[v] + e.len) {
                d[e.to] = d[v] + e.len;
                cost[e.to] = cost[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    cout << d[t] << " " << cost[t] << endl;
    return;
}
int main()
{
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        
        //初始化操作
        for (int i = 1;i <= n;i++) //图初始化
            G[i].clear();
        fill(d + 1, d + n + 1, INF);      //距离初始化为无穷
        fill(cost + 1, cost + n + 1, INF);//花费初始化为无穷
        
        for (int i = 1;i <= m;i++) {
            int from, to, len, cost;
            cin >> from >> to >> len >> cost;
            G[from].emplace_back(edge{to, len, cost});
            G[to].emplace_back(edge{from, len, cost});
        }
        
        int s, t;
        cin >> s >> t;
        dijkstra(s, t);
    }
    return 0;
}