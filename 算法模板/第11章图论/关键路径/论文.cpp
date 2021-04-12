//关键路径论文 (北大) http://www.noobdream.com/DreamJudge/Issue/page/1536/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e9
#define MAXV 100001
#define MOD 1000000007

ll early[MAXV];
ll late[MAXV];
int inDegree[MAXV] = { 0 };
ll times[MAXV];
vector<int> G[MAXV];//存储图

// 关键路径算法
int solve(int n, int m)
{
	vector<int> topology;//需要记录拓扑排序，用于计算最晚时间
	queue<int> que;
	for (int i = 1;i <= n;i++)
		if (inDegree[i] == 0) {         //源点
			que.push(i);
			early[i] = 0;
		}
	ll totalTime = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		topology.emplace_back(v);
		for (int i = 0;i < G[v].size();i++) {
			int u = G[v][i];
			early[u] = max(early[u], early[v] + times[v]);
			inDegree[u]--;
			if (inDegree[u] == 0) {
				que.push(u);
				totalTime = max(totalTime, early[u] + times[u]);
			}
		}
	}
	cout << totalTime << endl;
	for (int i = topology.size() - 1;i >= 0;i--) {
		int v = topology[i];
		if (G[v].size() == 0)           //汇点
			late[v] = totalTime - times[v];
		else 
			late[v] = INF;
		for (int j = 0;j < G[v].size();j++) {
			int u = G[v][j];
			late[v] = min(late[v], late[u] - times[v]);
		}
	}
	ll res = 1;
	for (int i = 1;i <= n;i++) {
		res *= late[i] - early[i] + 1;
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}

int main()
{
	int n, m;
    cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> times[i];
	int from, to;
	for (int i = 1;i <= m;i++) {
		cin >> from >> to;
		G[from].emplace_back(to);
		inDegree[to]++;
	}
	solve(n, m);
	return 0;
}