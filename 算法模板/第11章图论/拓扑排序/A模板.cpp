//拓扑排序模板
#include<bits/stdc++.h>
using namespace std;

#define MAXV 501

vector<int> G[MAXV];
int inDegree[MAXV];

vector<int> TopologicalSort(int n)
{
    vector<int> answer;
    //按编号大小输出，所以使用优先队列
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 1;i <= n;i++)
        if (inDegree[i] == 0)
            que.push(i);
    while (!que.empty()) {
        int p = que.top(); que.pop();
        int v;
        answer.push_back(p);
        for (int i = 0;i < G[p].size();i++) {
            v = G[p][i];
            inDegree[v]--;
            if (inDegree[v] == 0)
                que.push(v);
        }
    }
    return answer;
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        int from, to;
        for (int i = 1;i <= m;i++) {
            cin >> from >> to;
            G[from].emplace_back(to);
            inDegree[to]++;
        }
        vector<int> answer = TopologicalSort(n);
        for (int i = 0;i < answer.size();i++) {
            cout << answer[i];
            if (i != n - 1) cout << " ";
        }
    }
    return 0;
}