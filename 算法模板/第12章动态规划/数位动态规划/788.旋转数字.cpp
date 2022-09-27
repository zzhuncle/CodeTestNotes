//数位 DP 中，数的大小对复杂度的影响很小。
int diff[10] = {-1, -1, 1, 0, 0, 1, 1, 0, -1, 1};
class Solution {
public:
    int dp[6][2];
    int m;
    string s;
    int dfs(int pos, bool is_diff, bool is_limit) {//当前处理的数字位置、是否有旋转成对方的数字、是否有数字限制
        if (pos == m + 1)
            return is_diff;
        if (!is_limit && dp[pos][is_diff] != -1)
            return dp[pos][is_diff];
        int res = 0;
        int up = is_limit ? s[pos - 1] - '0' : 9;  
        for (int i = 0;i <= up;i++)
            if (diff[i])
                res += dfs(pos + 1, is_diff || (diff[i] == 1), is_limit && i == up);
        if (!is_limit)
            dp[pos][is_diff] = res;
        return res;
    }
    int rotatedDigits(int n) {
        s = to_string(n);
        m = s.size();
        memset(dp, -1, sizeof(dp));
        return dfs(1, false, true);
    }
};
