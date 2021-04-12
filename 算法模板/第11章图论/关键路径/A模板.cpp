//Instructions Arrangement http://acm.hdu.edu.cn/showproblem.php?pid=4109
//根据拓扑序列逐一求出每个活动的最早开始时间，再根据逆序列求出每个活动的最晚开始时间
#include<bits/stdc++.h>
using namespace std;

#define MAXV 1001
#define INF INT_MAX

struct e {
    int to;  //终点 
    int time;//距离 
};
vector<e> G[MAXV]; //图 
int early[MAXV];   //最早开始时间 
int late[MAXV];    //最晚开始时间 
int inDegree[MAXV];//入度 

void CriticalPath(int n, int m)
{
    vector<int> topology;//拓扑序列 
    queue<int> node;
    for (int i = 0;i < n;i++)
        if (inDegree[i] == 0) {
            node.push(i);
            early[i] = 1;
        }
    int totalTime = 0;
    while (!node.empty()) {
        int u = node.front(); node.pop();
        topology.push_back(u);
        for (int i = 0;i < G[u].size();i++) {
            int v = G[u][i].to;
            int time = G[u][i].time;
            early[v] = max(early[v], early[u] + time);
            totalTime = max(totalTime, early[v]);
            inDegree[v]--;
            if (inDegree[v] == 0)
                node.push(v);
        }
    }
    cout << totalTime << endl;
    for (int i = topology.size() - 1;i >= 0;i--) {
        int u = topology[i];
        if (G[u].size() == 0) 
            late[u] = totalTime;
        else
            late[u] = INF;
        for (int j = 0;j < G[u].size();j++) {
            int v = G[u][j].to;
            int time = G[u][j].time;
            late[u] = min(late[u], late[v] - time);
        }
    }
    return;
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        memset(G, 0, sizeof(G));
        memset(early, 0, sizeof(early));
        memset(late, 0, sizeof(late));
        memset(inDegree, 0, sizeof(inDegree));
        int from, to, time;
        for (int i = 1;i <= m;i++) {
            cin >> from >> to >> time;
            G[from].push_back(e{to, time}); 
            inDegree[to]++;
        }
        CriticalPath(n, m);
        getchar();
    }
    return 0;
}