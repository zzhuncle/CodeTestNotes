//1192. 查找集群内的「关键连接」
//Tarjan算法模板题
class Solution {
private:
    int num;
    vector<int> dfn;//时间戳
    vector<int> low;//回溯祖先
    vector<vector<int>> G;
    vector<vector<int>> res;
public:
    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++num;
        for (auto& v : G[u]) {
            if (v == fa)
                continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    res.push_back({u, v});
            }
            else 
                low[u] = min(low[u], dfn[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        num = 0;
        dfn.resize(n);
        low.resize(n);
        G.resize(n);
        for (auto& c : connections) {
            G[c[0]].push_back(c[1]);
            G[c[1]].push_back(c[0]);
        }
        tarjan(0, -1);
        return res;
    }
};
