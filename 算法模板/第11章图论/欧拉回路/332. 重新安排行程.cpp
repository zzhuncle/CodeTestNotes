//332. 重新安排行程
class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;

public:
    void dfs(string curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(tmp);
        }
        stk.emplace_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) 
            vec[it[0]].emplace(it[1]);
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return this->stk;
    }
};
