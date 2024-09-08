#include<bits/stdc++.h>
using namespace std;
void adjust(vector<int>& nums, int cur, int r) {
	int num = nums[cur];
	// 在以cur为根的子树中从根到叶子循环
	for (int i = 2 * cur;i <= r;i *= 2) {
		if (i < r && nums[i] < nums[i + 1])
			i++;
		if (num >= nums[i])
			break;
		nums[cur] =  nums[i];
		cur = i; // 记录最终的位置 
	}
	nums[cur] = num;
}
int heapsort(vector<int>& nums) {
	int n = nums.size() - 1;
	// 初始化堆 
	for (int i = n / 2;i >= 1;i--) {
		adjust(nums, i, n);
	}
	// 调整堆
	for (int i = n;i > 1;i--) {
		swap(nums[i], nums[1]);
		adjust(nums, 1, i - 1);
	}
}  
int main() {
	vector<int> nums = {0, 8, 42, 16, 28, 53, 77, 30, 37};
	int n = nums.size() - 1;
	heapsort(nums);
	for (int i = 1;i <= n;i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
