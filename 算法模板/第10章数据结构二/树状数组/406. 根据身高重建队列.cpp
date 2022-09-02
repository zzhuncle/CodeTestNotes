//406. 根据身高重建队列
class Solution {
private:
    int n;
    vector<int> tr;
public:
    int lowbit(int x) {
        return x & -x; 
    }
    void add(int x, int v) {
        for (int i = x;i <= n;i += lowbit(i))
            tr[i] += v;
    }
    int query(int x) {
        int ans = 0;
        for (int i = x;i > 0;i -= lowbit(i))
            ans += tr[i];
        return ans;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &a, auto& b) {
            if (a[0] != b[0]) 
                return a[0] < b[0];
            return b[1] < a[1];
        });
        n = people.size();
        tr = vector<int> (n + 1, 0);
        vector<vector<int>> ans(n, vector<int>(2, 0));
        
        for (auto& p : people) {
            int k = p[1];
            int l = 1, r = n;
            //快速找到 res中的 空白序列的第k个位置
            //树状数组代表位置的使用状况（1 的前缀和），0 即为该位置可以使用
            //空白序列的第k个位置 == 在树状数组中找到第一个位置 0 的个数大于等于 k + 1 即可
            //0 的个数 == （位置 - 此位置之前的被使用的位置数）
            while (l < r) {
                int mid = l + r >> 1;
                if (mid - query(mid) >= k + 1)
                    r = mid;
                else    
                    l = mid + 1;
            }
            ans[r - 1] = p;
            add(r, 1);
        }
        return ans;
    }
};
