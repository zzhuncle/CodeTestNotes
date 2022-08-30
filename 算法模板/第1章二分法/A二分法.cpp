//LeetCode 35.搜索插入位置
//1. 区间的选择：[l, r) 左开右闭
//2. 区间缩小的边界 l = mid + 1, r = mid
//3. 返回值：返回时 l == r, 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};
