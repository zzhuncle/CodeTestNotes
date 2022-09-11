//线段树，普通动态规划会超时
class Solution {
    vector<int> tree;
public:
    //区间查询
    //[start, end] 查询区间 [l, r] 线段区间 
    int query(int idx, int start, int end, int l, int r) {
        if (r < start || end < l)  //查询区间和线段区间没有任何交集
            return 0;
        if (start <= l && r <= end)//查询区间比线段区间大，返回线段区间的值 
            return tree[idx];
        int mid = (l + r) >> 1;
        return max(query(2 * idx, start, end, l, mid), 
            query(2 * idx + 1, start, end, mid + 1, r));
    }
    //区间更新（没有lazy标记）
    void update(int idx, int val, int start, int end, int l, int r) {
        if (r < start || end < l)
            return;
        if (start <= l && r <= end) 
            tree[idx] = max(tree[idx], val); 
        else {
            int mid = (l + r) >> 1;
            if (l <= mid)
                update(2 * idx, val, start, end, l, mid);
            if (mid < r)
                update(2 * idx + 1, val, start, end, mid + 1, r);
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
        return;
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int mx = 0, ans = 0;
        for (int x : nums)
            mx = max(mx, x);
        int n = nums.size();
        //初始化线段树
        tree.resize(4 * mx);
        int x;
        for (int i = 0;i < n;i++) {
            if (nums[i] == 1)
                x = 1;
            else //区间查询
                x = query(1, max(1, nums[i] - k), nums[i] - 1, 1, mx) + 1;
            update(1, x, nums[i], nums[i], 1, mx); //单点更新 (也可以按照区间更新写)
            ans = max(ans, x);
        }
        return ans;
    }
};
