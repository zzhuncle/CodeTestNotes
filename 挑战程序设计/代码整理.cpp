#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<iostream>
const double PI = 3.1415926;
#define INF 1000000
typedef long long ll;
using namespace std;
/*动态规划
int main()
{
	int i,j;
	int p[5] = { 3,4,3,5,5 };
	int g[5] = { 200,300,350,400,500 };
	int pregold[11] = { 0 };
	int gold[11] = { 0 };
	for (i = 0; i <= 10; i++) {
		if (i < g[0])
			gold[i] = 0;
		else
			gold[i] = g[0];
	}
	for (j = 0; j <= 10; j++)
		pregold[j] = gold[j];
	for (i = 1; i < 5; i++) {
		for (j = 1; j <= 10; j++)
			if (j < p[i])
				gold[j] = pregold[j];
			else
				gold[j] = max(pregold[j], pregold[j - p[i]] + g[i]);
		for (j = 0; j <= 10; j++)
			pregold[j] = gold[j];
	}
	cout << gold[10];
	return 0;
}*/
/*深度优先搜索
bool dfs(int i, int sum, const int k, const int n,const int* a)
{
	//if (sum > k)
	//	return false;剪枝
	if (i == n)
		return sum == k;
	if (dfs(i + 1, sum, k, n, a))
		return true;
	if (dfs(i + 1, sum + a[i], k, n, a))
		return true;
	return false;
}
int main()
{
	int a[] = { 1,2,4,7 };
	if (dfs(0, 0, 13, 4, a))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
void dfs(int x,int y,char map[][12])
{
	int dx, dy;
	map[x][y] = '.';
	for (dx = -1; dx <= 1; dx++)
		for (dy = -1; dy <= 1; dy++)
			if (x + dx >= 0 && x + dx < 10 && y + dy >= 0 && y + dy < 12 && map[x + dx][y + dy] == 'W')
				dfs(x + dx, y + dy, map);
}
int main()
{
	char map[10][12] = { 'W','.','.','.','.','.','.','.','.','W','W','.',
		'.','W','W','W','.','.','.','.','.','W','W','W',
		'.','.','.','.','W','W','.','.','.','W','W','.',
		'.','.','.','.','.','.','.','.','.','W','W','.',
		'.','.','.','.','.','.','.','.','.','W','.','.',
		'.','.','W','.','.','.','.','.','.','W','.','.',
		'.','W','.','W','.','.','.','.','.','W','W','.',
		'W','.','W','.','W','.','.','.','.','.','W','.',
		'.','W','.','W','.','.','.','.','.','.','W','.',
		'.','.','W','.','.','.','.','.','.','.','W','.'
	};
	int cnt = 0,i,j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 12; j++)
			if (map[i][j] == 'W') {
				cnt++;
				dfs(i, j, map);
			}
	cout << cnt;
	return 0;
}*/
/*宽度优先搜索//迷宫的最短路径
typedef pair<int, int> P;
const int INF = 10000000;
void bfs(char map[][10])
{
	queue<P> que;
	int i, j;
	int sx = 0, sy = 1;
	int gx = 9, gy = 8;
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	int d[10][10];
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			d[i][j]= INF;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	while (que.size()) {
		P p = que.front();
		que.pop();
		if (p.first == gx && p.second == gy)
			break;
		for (i = 0; i < 4; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10
				&& d[nx][ny] == INF && map[nx][ny] != '#') {
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	cout << d[gx][gy];
}
int main()
{
	char map[10][10];
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			cin >> map[i][j];
	bfs(map);
	return 0;
}*/
/*特殊状态的枚举
void permutation1(int pos, int n, bool used[10], int perm[10])//生成{0,1,2,3,4,...,n-1}的n!种排列
{
	int i;
	if (pos == n) {
		for (i = 0; i < n; i++)
			cout << perm[i] << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < n; i++) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = true;
			permutation1(pos + 1, n, used, perm);
			used[i] = false;
		}
	}
	return;
}
int main()
{
	bool used[10] = {false};
	int perm[10] = { 0 };
	permutation1(0, 10, used, perm);
	return 0;
	//next_permutation(a,a+a.length) C++标准库函数，生成数组的全排列
}*/
//贪心法
/*区间调度问题//目标：参与更多的工作？算法：在每次可选的工作中，选择结束时间最早的
int main()
{
	int n = 5, i, j = 0, ans = 0;
	int s[5] = { 1,2,4,6,8 };
	int t[5] = { 3,5,7,9,10 };
	pair<int, int> st[5];
	for (i = 0; i < 5; i++) {
		st[i].first = t[i];
		st[i].second = s[i];
	}
	sort(st, st + 5);//按字典序排序
	for (i = 0; i < 5; i++) {
		if (st[i].second > j) {
			ans++;
			j = st[i].first;
		}
	}
	cout << ans;
	return 0;
}*/
/*字典序最小问题//字典序比较类的问题经常能用得上贪心法
int main()
{
	char S[7] = "ACDBCB";
	char T[7];
	bool left = false;
	int a = 0, b = 5;
	for (int j = 0; j < 6; j++) {
		for (int i = 0; a + i < 6; i++) {
			if (S[a + i] < S[b - i]) {
				left = true;
				break;
			}
			if (S[a + i] > S[b - i]) {
				left = false;
				break;
			}
		}
		if (left)
			T[j] = S[a++];
		else
			T[j] = S[b--];
	}
	T[6] = '\0';
	cout << T;
	return 0;
}*/
/*Saruman's Army
int main()
{
	int n = 6, R = 10, X[6] = { 1,7,15,20,30,50 };
	int i = 0, ans = 0, a = 0, b;
	while (i < n) {
		while (X[i] < X[a] + R && i < n)
			i++;
		b = i;
		while (X[i] < X[b - 1] + R && i < n)
			i++;
		a = i;
		if (a < 6)
			ans++;
	}
	cout << ans;
	return 0;
}*/
/*修理栅栏//霍夫曼编码
int main()
{
	int N = 5;
	int L[5] = { 1,4,5,2,3 };
	int ans = 0;
	//直到计算到木板为1块时为止
	while (N > 1) {
		int mii1 = 0, mii2 = 1, i, t;
		//求出最短的木块mii1和第二短的木块mii2
		if (L[mii1] > L[mii2])
			swap(mii1, mii2);
		for (i = 2; i < N; i++) {
			if (L[i] < L[mii1]) {
				mii2 = mii1;
				mii1 =  i;
			}
			if (L[i] < L[mii2])
				mii2 = i;
		}
		//将两块板拼合
		t = L[mii1] + L[mii2];
		ans += t;
		if (mii2 == N - 1)
			swap(mii1, mii2);
		L[mii2] = t;
		L[mii1] = L[N - 1];
		N--;
	}
	cout << ans;
	return 0;
}*/
//记录结果再利用的“动态规划”
/*01背包问题
const int n = 4;
const int W = 5;
const int w[4] = { 2,1,3,2 }, v[4] = { 3,2,4,2 };
//从第i个物品开始挑选总重小于j的部分
int rec1(int i, int j)
{
	int res;
	if (i == n)//已经没有剩余物品了
		res = 0;
	else if (w[i] > j)//无法挑选这个物品
		res = rec1(i + 1, j);
	else//挑选和不挑选的情况都尝试一下
		res = max(rec1(i + 1, j), rec1(i + 1, j - w[i]) + v[i]);
	return res;
}
void solve1()
{
	cout << rec1(0, W) << endl;
}
//目前选择的物品价值总和是sum，从第i个物品之后的物品中挑选重量总和小于j的物品
int rec2(int i, int j, int sum)
{
	int res;
	if (i == n)//已经没有剩余物品了
		res = sum;
	else if (w[i] > j)//无法挑选这个物品
		res = rec2(i + 1, j, sum);
	else//挑选和不挑选的情况都尝试一下
		res = max(rec2(i + 1, j, sum), rec2(i + 1, j - w[i], sum + v[i]));
	return res;
}
void solve2()
{
	cout << rec2(0, W, 0) << endl;
}
int dp[n + 1][W + 1];//记忆化数组
int rec3(int i, int j)
{
	if (dp[i][j] != -1)
		return dp[i][j];
	int res;
	if (i == n)//已经没有剩余物品了
		res = 0;
	else if (w[i] > j)//无法挑选这个物品
		res = rec3(i + 1, j);
	else//挑选和不挑选的情况都尝试一下
		res = max(rec3(i + 1, j), rec3(i + 1, j - w[i]) + v[i]);
	return dp[i][j] = res;
}
void solve3()
{
	memset(dp, -1, sizeof(dp));
	cout << rec3(0, W) << endl;
}
void solve4()//利用递推关系的DP（Dynamic Programming）动态规划
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; i++)//这里没有等号
		for (j = 0; j <= W; j++) {//这里存在等号
			if (j < w[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
		}
	cout << dp[n][W] << endl;
}
void solve5()//利用状态转移的动态规划
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; i++)//这里没有等号
		for (j = 0; j <= W; j++) {//这里存在等号
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + w[i] <= W)//这里有等号
				dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
		}
	cout << dp[n][W] << endl;
}
int main()
{
	solve1();
	solve2();
	solve3();
	solve4();
	solve5();
	return 0;
}*/
/*最长公共子序列问题
const int n = 4;
const int m = 4;
const char s[4] = { 'a','b','c','d' };
const char t[4] = { 'b','e','c','d' };
int dp[5][5];
int main()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (s[i] == t[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	cout << dp[n][m];
	return 0;
}*/
/*完全背包问题
const int n = 3;
const int W = 7;
const int w[3] = { 3, 4, 2 }, v[4] = { 4, 5, 3 };
int dp[n + 1][W + 1];
void solve()//利用递推关系的DP（Dynamic Programming）动态规划
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; i++)//这里没有等号
		for (j = 0; j <= W; j++) {//这里存在等号
			if (j < w[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);//此行i变为i+1
		}
	cout << dp[n][W] << endl;
}*/
/*01背包问题和完全背包问题都可以通过不断重复利用一个数组来实现
//01背包问题
void solve01()
{
	int dp[W + 1] = { 0 };
	int i, j;
	for (i = 0; i < n; i++)
		for (j = W; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W];
}
//完全背包问题
void solven()
{
	int dp[W + 1] = { 0 };
	int i, j;
	for (i = 0; i < n; i++)
		for (j = w[i]; j <= W; j++)//只是方向有变化
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W];
}
int main()
{
	solve01();
	return 0;
}*/
/*01背包问题2//根据问题的规模来改变算法
const int n = 4;
const int W = 5;
const int INF = 1000000;
const int w[4] = { 2,1,3,2 }, v[4] = { 3,2,4,2 };
int dp[n + 1][n * W + 1];
void solve()
{
	fill(dp[0], dp[0] + n * W + 1, INF);
	dp[0][0] = 0;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j <= n * W; j++) {
			if (j < v[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
		}
	int res = 0;
	for (i = 0; i <= n * W; i++)
		if (dp[n][i] < W)
			res = i;
	cout << res << endl;
}*/
/*多重部分和问题
const int n = 3;
const int a[3] = { 3,5,8 };
const int m[3] = { 3,2,2 };
const int K = 17;
//递推关系：dp[i+1][j]:=用前i种数字是否能加和成j
void solve0()
{
	bool dp[n + 1][K + 1] = { false };
	dp[0][0] = true;
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j <= K; j++)
			for (k = 0; k * a[i] <= j && k <= m[i]; k++)
				dp[i + 1][j] |= dp[i][j - k * a[i]];
	if (dp[n][K])
		cout << "Yes";
}
//递推关系：dp[i+1][j]:=如果用前i种数字能加和成j，为a[i]剩下的个数，否则为-1
void solve()
{
	int dp[K + 1];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j <= K; j++) {
			if (dp[j] >= 0)
				dp[j] = m[i];
			else if (j < a[i] || dp[j - a[i]] <= 0)
				dp[j] = -1;
			else
				dp[j] = dp[j - a[i]] - 1;
		}
	if (dp[K] >= 0)
		cout << "Yes";
}
int main()
{
	solve();
	return 0;
}*/
/*最长上升子序列问题
const int n = 5;
const int a[5] = { 4,2,3,1,5 };
int main()
{
	int i, j;
	int dp[n + 1] = { 0 };
	for (i = 0; i < n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << dp[n];
	return 0;
}*/
//DP对求解最优问题，各种排列组合的个数，概率或者期望之类的计算有效
/*划分数：有n个无区别的物品，将它们划分成不超过m组，求出划分方法数
//dp[i][j]=j的i划分总数(不超过i组) dp[i][j]=dp[i][j-i]+dp[i-1][j]
const int n = 4;
const int m = 3;
int dp[m + 1][n + 1];
int main()
{
	dp[0][0] = 1;
	int i, j;
	for (i = 1; i <= m; i++)
		for (j = 0; j <= n; j++) {
			if (j >= i)
				dp[i][j] = dp[i][j - i] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	cout << dp[m][n] <<endl;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}*/
/*多重集组合数
const int n = 3;
const int m = 3;
const int a[3] = { 1,2,3 };
//dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]
int main()
{
	int dp[n + 1][m + 1] = { 0 };
	int i, j;
	for (i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (i = 0; i < n; i++)
		for (j = 1; j <= m; j++) {
			if (j - 1 >= a[i])
				dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]];
			else
				dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j];
		}
	cout << dp[n][m];
	return 0;
}*/
//优先队列和堆
/*优先队列（利用二叉树堆）的实现
int heap[1000], sz = 0;
void push(int x)//入队列
{
	int i = sz++;
	while (i > 0) {
		int p = (i - 1) / 2;
		//调整完毕，可以退出
		if (heap[p] <= x)
			break;
		//将父结点放下去
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}
int pop()//最小值出队列
{
	int ret = heap[0];//最小值
	int x = heap[--sz];//要提到根的数值
	//从根开始向下交换
	int i = 0;
	while (2 * i + 1 < sz) {
		//比较儿子的值
		int a = 2 * i + 1, b = 2 * i + 2;
		if (b < sz && heap[b] < heap[a])
			a = b;
		//调整完毕，可以退出
		if (x <= heap[a])
			break;
		//将结点上提
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}*/
/*STL里面priority_queue的实现 取出的是最大值
#include<queue>
#include<cstdio>
priority_queue<int> pque;
*/
//卡车加油问题：思路较直接
/*二叉查找树的实现
struct node {
	int val;
	node *lch, *rch;
};
node *insert(node *p, int x)
{
	if (p == NULL) {
		node *q = new node;
		q->val = x;
		q->lch = q->rch = NULL;
		return q;
	}
	else {
		if (x < p->val)
			p->lch = insert(p->lch, x);
		else
			p->rch = insert(p->rch, x);
		return p;
	}
}
bool find(node *p, int x)
{
	if (p == NULL)
		return false;
	else if (p->val == x)
		return true;
	else if (x < p->val)
		return find(p->lch, x);
	else
		return find(p->rch, x);
}
node *remove(node *p, int x)
{
	if (p == NULL)
		return NULL;
	else if (x < p->val)
		p->lch = remove(p->lch, x);
	else if (x > p->val)
		p->rch = remove(p->rch, x);
	//只考虑左子树
	//需要删除的结点没有左儿子，就把右儿子提上去
	else if (p->lch == NULL) {
		node *q = p->rch;
		delete p;
		return q;
	}
	//需要删除的结点的左儿子没有右儿子，就把左儿子提上去
	else if (p->lch->rch == NULL) {
		node *q = p->lch;
		q->rch = p->rch;
		delete p;
		return q;
	}
	//以上两种情况都不满足，就把左儿子的子孙中的最大结点提到需要删除的结点上
	else {
		node *q;
		for (q = p->lch; q->rch->rch != NULL; q = q->rch)
			;
		node *r = q->rch;
		q->rch = r->lch;
		r->lch = p->lch;
		r->rch = p->rch;
		return r;
	}
	return p;
}*/
/*STL中set（使用二叉搜索树维护集合的容器）和map（维护键和键对应的值的容器）的例子
#include<cstdio>
#include<set>
#include<map>
#include<string>
int main()
{
	{
		set<int> s;
		//插入
		s.insert(1);
		s.insert(3);
		s.insert(5);
		//查找
		set<int>::iterator ite;
		ite = s.find(1);
		if (ite == s.end())
			cout << "Not found" << endl;
		else
			cout << "Found" << endl;
		if (s.count(2) == 0)
			cout << "Not found" << endl;
		else
			cout << "Found" << endl;
		//删除
		s.erase(3);
		//遍历
		for (ite = s.begin(); ite != s.end(); ite++)
			cout << *ite << " ";
	}
	{
		map<int, const char*> m;//<键,值>
		//插入
		m.insert(make_pair(1, "ONE"));
		m.insert(make_pair(10, "TEN"));
		m[100] = "HUNDRED";//其他的写法
		//查找
		map<int, const char*>::iterator ite;
		ite = m.find(2);
		if (ite == m.end())
			cout << "Not found" << endl;
		else
			cout << "Found " << ite->second << endl;
		cout << m[10] << endl;
		//删除
		m.erase(10);
	}
	return 0;
}*/
/*并查集的实现
//1.查询a,b是否属于同一组
//2.合并a,b所在的组*/
/*int rankn[10000];//树的高度//集合的大小
int par[10000];//父亲
//初始化n个元素
void init(int n)
{
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rankn[i] = 0;
	}
}
//查询树的根
int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}
//合并x和y所属的集合
void unit(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rankn[x] < rankn[y])
		par[x] = y;
	else {
		par[y] = x;
		if (rankn[x] == rankn[y])
			rankn[x]++;
	}
}
//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x) == find(y);
}*/
/*const int N = 100;
const int K = 7;
const int T[K] = { 1,2,2,2,1,2,1 };
const int X[K] = { 101,1,2,3,1,3,5 };
const int Y[K] = { 1,2,3,3,3,1,5 };
//食物链
int main()
{
	int i, j, x, y, t, ans = 0;
	init(N * 3);
	for (i = 0; i < K; i++) {
		x = X[i] - 1;
		y = Y[i] - 1;
		t = T[i];
		if (x < 0 || x >= N || y < 0 || y >= N) {
			ans++;
			continue;
		}
		if (t == 1) {
			if (same(x, y + N) || same(x, y + 2 * N)) {
				ans++;
				continue;
			}
			else {
				unit(x, y);
				unit(x + N, y + N);
				unit(x + 2 * N, y + 2 * N);
			}
		}
		else {
			if (same(x, y) || same(x, y + 2 * N)) {
				ans++;
				continue;
			}
			else {
				unit(x, y + N);
				unit(x + N, y + 2 * N);
				unit(x + 2 * N, y);
			}
		}
	}
	cout << ans << endl;
	return 0;
}*/
//图
//实现邻接表的方式
//1.vector<int> G[1000];
//  G[s].push_back(t);
//2.struct vertex {
//	  vector<vertex*> edge;
//  };
//  vertex G[1000];
//  G[s].edge.push_back(&G[t]);
//把相邻顶点染成不同颜色的问题叫做图着色问题，对图进行染色所需要的最小颜色数称为最小着色数，最小着色数为2的图称作二分图
/*二分图判定
vector<int> G[1000];//图
int V;              //顶点数
int color[1000];          //顶点i的颜色（-1或1）
//把顶点染成1或-1
bool dfs(int v, int c)
{
	color[v] = c;
	for (int i = 0; i < G[v].size(); i++) {
		//相邻的顶点同色
		if (color[G[v][i]] == c)
			return false;
		//相邻的顶点还没被染色，则染成-c
		else if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))
			return false;
	}
	//所有的顶点都染过色，返回true
	return true;
}
void solve()
{
	for (int i = 0; i < V; i++)
		if (!color[i])
			if (!dfs(i, 1)) {
				cout << "No" << endl;
				return;
			}
	cout << "Yes" << endl;
}*/
//最短路径问题
//#define N 1000
/*Bellman-ford算法：适用于边权值为负的情况
//O ( |V||E| )
struct edge { int from, to, cost; };
edge es[1000];//边
int d[1000];//最短距离
int V, E;//V顶点数，E边数
//求解从顶点s出发到所有点的最短距离
void shortest_path(int s)
{
	fill(d, d + V, INF);
	d[s] = 0;
	edge e;
	while (1) {
		bool update = false;
		for (int i = 0; i < E; i++) {
			e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)
			break;
	}
}
//检查负圈
bool find_negative_loop()
{
	fill(d, d + V, 0);
	edge e;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			e = es[j];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				//如果第n次仍然更新，则存在负圈
				if (i == V - 1)
					return true;
			}
		}
	}
	return false;
}*/
/*Dijkstra算法
//O( |V|2 )
int cost[N][N];
bool used[N];
int d[N];
int V;//顶点数
void dijkstra(int s)
{
	int i, v;
	fill(used, used + V, false);
	fill(d, d + V, INF);
	d[s] = 0;
	while (1) {
		v = -1;
		//从未使用过的顶点中选择一个距离最小的顶点
		for (i = 0; i < V; i++)
			if (!used[i] && (v == -1 || d[i] < d[v]))
				v = i;
		if (v == -1)
			break;
		used[v] = true;
		for (i = 0; i < V; i++)
			if (!used[i] && (d[i] > cost[v][i] + d[v]))
				d[i] = cost[v][i] + d[v];
	}
}
//O( |E|log|V| )
struct edge { int to, cost; };
typedef pair<int, int> P;//first是最短距离，second是顶点的编号
int V;
vector<edge> G[1000];
int d[1000];
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P>> que;//从小到大取值
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));
	while (que.size()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)//???
			continue;//???
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > e.cost + d[v]) {
				d[e.to] = e.cost + d[v];
				que.push(P(d[e.to], e.to));
			}
		}
	}
}*/
/*Floyd-Warshall算法
int d[1000][1000];
int V;
void warshall_floyd()
{
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}*/
/*路径还原
int prev[1000];
void dijkstra(int s)
{
	int i, v;
	fill(used, used + V, false);
	fill(d, d + V, INF);
	fill(prev, prev + V, -1);
	d[s] = 0;
	while (1) {
		v = -1;
		//从未使用过的顶点中选择一个距离最小的顶点
		for (i = 0; i < V; i++)
			if (!used[i] && (v == -1 || d[i] < d[v]))
				v = i;
		if (v == -1)
			break;
		used[v] = true;
		for (i = 0; i < V; i++)
			if (!used[i] && (d[i] > cost[v][i] + d[v])) {
				d[i] = cost[v][i] + d[v];
				prev[i] = v;
			}
	}
}
vector<int> get_path(int t)
{
	vector<int> path;
	for (; t != -1; t = prev[t])
		path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}*/
//最小生成树
/*Prim算法 O(|V|2)
int cost[1000][1000];//cost[u][v]表示边e=(u,v)的权值
int mincost[1000];   //从集合X出发的边到每个顶点的最小权值
bool used[1000];     //顶点i是否包含在集合X 中
int V;               //顶点数
int prim()
{
	int i, v, ans = 0;
	fill(mincost, mincost + V, INF);
	fill(used, used + V, false);
	mincost[0] = 0;
	while (1) {
		v = -1;
		for (i = 0; i < V; i++)
			if (!used[i] && (v == -1 || mincost[i] < mincost[v]))
				v = i;
		if (v == -1)
			break;
		used[i] = true;
		ans += mincost[i];
		for (i = 0; i < V; i++)
			mincost[i] = min(mincost[i], cost[v][i]);
	}
	return ans;
}*/
/*Kruskal算法 O(||)
struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}
edge es[1000];
int V, E;
int kruskal()
{
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unit(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}*/
/*Roadblocks//求解次短路径
struct edge { int to, cost; };
typedef pair<int, int> P;//first是最短距离，second是顶点的编号
int N, R;
vector<edge> G[1000];
int dist[1000];
int dist2[1000];
void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P>> que;
	fill(dist, dist + N, INF);
	fill(dist2, dist2 + N, INF);
	dist[s] = 0;
	que.push(P(s, 0));

	while (que.size()){
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first, d2;
		if (d > dist2[v])//到某个顶点v的次短路要么是到其他某个顶点的最短路再加上u->v的边，要么是到u的次短路再加上u->v的边
			continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			d2 = e.cost + d;//到某个顶点v的次短路要么是到其他某个顶点的最短路再加上u->v的边，要么是到u的次短路再加上u->v的边
			if (dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}
			if (dist[e.to] < d2 && dist2[e.to] > d2) {
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
	cout << dist2[N - 1] << endl;
}*/
/*Layout 养牛问题
//d(v)-d(s)的最大值就是从s到v的最短距离
int N，ML, MD;
int AL[1000], BL[1000], DL[1000];
int AD[1000], BD[1000], DD[1000];
int d[1000];//最短距离
void solve()
{
	int i, j;
	fill(d, d + N, INF);
	d[0] = 0;
	//用Bellman-ford算法计算d
	for (i = 0; i < N; i++) {
		//从i到i+1的权值为0
		for (j = 0; j + 1 < N; i++)
			if (d[i+1] != INF)
				d[i] = min(d[i], d[i + 1]);
		//从AL到BL的权值为DL
		for (j = 0; j < ML; j++)
			if (d[AL[i]-1] != INF)
				d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
		//从BD到AD的权值为-DD
		for (j = 0; j < MD; j++)
			if (d[BD[i] - 1] != INF)
				d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
	}
	int res = d[N - 1];
	if (d[0] < 0)//存在负圈无解
		res = -1;
	else if (res == INF)
		res = -2;
	cout << res << endl;
}*/
//数学问题的解题窍门
/*辗转相除法
//求最大公约数//复杂度在O( logmax(a,b))以内 )
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
//扩展欧几里得算法
//双六
//ax+by=gac(a,b) 求x,y
//可以证明：|x|<=b且|y|<=a
int extgcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int ans = extgcd(b, a % b, x, y);
	int temp = x;
	x = y;
	y = temp - (a / b) * x;
	return ans;
}*/
/*假设输入都是正数
//素性测试 ((O(根号n))
bool is_prime(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return n != 1;//1是例外
}
//约数枚举 ((O(根号n))
vector<int> divisor(int n)
{
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (n / i != i)
				res.push_back(n / i);
		}
	}
	return res;
}*/
/*埃式筛法 O(loglogn)
//枚举n以内的素数
int prime[1000];//第i个素数
bool is_prime[1001];//is_prime[i]为true表示i是素数
//返回n以内素数的个数
int sieve(int n)
{
	int p = 0;
	fill(is_prime, is_prime + 1001, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return p;
}*/
//区间筛法
/*((a+i-1)/i)*i
typedef long long ll;
bool is_prime[1000];
bool is_prime_small[1000];
对区间[a,b)内的整数进行筛法。is_prime[i-a]=true i是素数
void segment_sieve(ll a, ll b)
{
	int i;
	for (i = 0; (ll)i * i < b; i++)
		is_prime_small[i] = true;
	for (i = 0; i < b - a; i++)
		is_prime[i] = true;

	is_prime_small[0] = is_prime_small[1] = false;
	for (i = 2; (ll)i * i < b; i++) {
		if (is_prime_small[i]) {
			for (int j = 2 * i; (ll)j * j < b; j += i)
				is_prime_small[j] = false;
			for (int j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
				is_prime[j - a] = false;
		}
	}
}*/
/*模运算
//快速幂运算
typedef long long ll;
ll mod_pow(int x, int n, int mod)
{
	if (n == 0)
		return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1)
		res = res * x % mod;
	return res;
}*/
/*二分搜索
int n = 5;
int a[5] = { 2,3,3,5,6 };
int k = 3;
void solve()
{
	int lb = -1, ub = 5;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if (a[mid] >= k)
			ub = mid;
		else
			lb = mid;
	}
	cout << ub << endl;
}*/
/*假设一个解，并判断是否可行
int N, K;
double L[1000];
//判断是否满足条件
bool C(double x)
{
	int num = 0;
	for (int i = 0; i < N; i++) {
		num += int(L[i] / x);
	}
	return num >= K;
}
void solve()
{
	//初始化解的范围
	double lb = 0, ub = INF;
	for (int i = 0; i < 100; i++) {
		double mid = (lb + ub) / 2;
		if (C(mid))
			lb = mid;
		else
			ub = mid;
	}
}*/
/*最大化最小值
int N, M;
int x[1000];
bool C(int d)
{
	int last = 0;
	for (int i = 1; i < M; i++) {
		int crt = last + 1;
		while (crt < N && x[crt] - x[last] < d) {
			crt++;
		}
		if (crt == N)
			return false;
		last = crt;
	}
	return true;
}
void solve()
{
	sort(x, x + N);
	int lb = 0, ub = INF, mid;
	while (ub - lb > 1) {
		mid = (lb + ub) / 2;
		if (C(mid))
			lb = mid;
		else
			ub = mid;
	}
	cout << lb << endl;
}*/
/*最大化平均值
//输入
int n, k;
int w[1000], v[1000];
double y[1000];
bool C(double x)
{
	int i;
	for (i = 0; i < n; i++) {
		y[i] = v[i] - x * w[i];
	}
	sort(y, y + n);

	double sum = 0;
	for (i = 0; i < k; i++)
		sum += y[n - i - 1];
	return sum >= 0;
}
void solve()
{
	int lb = 0, ub = INF;
	double mid;
	for (int i = 0; i < 100; i++) {
		mid = (lb + ub) / 2;
		if (C(mid))
			lb = mid;
		else
			ub = mid;
	}
	cout << ub << endl;
}*/
//常用技巧精选
//尺取法 //通常指对数组保存一对下标(起点,终点),然后根据实际情况交替推进两个端点直到得出答案的方法
		 //反复地推进区间的开头和末尾,来求取满足条件的最小区间的方法
/*int n = 10;
int S = 15;
int a[10] = { 5,1,3,5,10,7,4,9,2,8 };
int sum[11];
void solve()
{
	//复杂度：O(nlogn)
	int i, s, res = n;
	for (i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	if (sum[n] < S) {
		cout << 0 << endl;
		return;
	}
	for (s = 0; sum[s] + S <= sum[n]; s++) {
		//利用二分搜索求出t
		int t = lower_bound(sum + s, sum + n, S + sum[s]) - sum;//>=key的第一个值的位置
		res = min(res, t - s);
	}
	cout << res << endl;
}
void solve()
{
	//复杂度：O(n)
	int res = n + 1;
	for (int s = 0, t = 0, sum = 0; ; )
	{
		while (t < n && sum < S)
			sum += a[t++];
		if (sum < S)
			break;
		res = min(res, t - s);
		sum -= a[s++];
	}
	if (res > n)
		res = 0;
	cout << res << endl;
}*/
/*int P = 5;
int a[5] = { 1,8,8,8,1 };
void solve()
{
	set<int> all;
	for (int i = 0; i < P; i++)
		all.insert(a[i]);
	int n = all.size();

	//利用尺取法来求解
	map<int, int> cnt;
	int s = 0, t = 0, num = 0;
	int res = P;
	for (;;) {
		while (t < P && num < n)
			if (cnt[a[t++]]++ == 0) {
				//出现新的知识点
				num++;
			}
		if (num < n)
			break;
		res = min(res, t - s);
		if (--cnt[a[s++]] == 0)
			num--;
	}
	cout << res << endl;
}*/
/*反转(开关问题)
int N = 7;
int dir[7] = { 1,1,0,1,0,1,1 };
//固定K,求对应的最小操作回数
//无解的话返回-1
int calc(int K)
{
	int f[1000];
	fill(f, f + N , 0);
	int i, sum = 0, res = 0;
	for (i = 0; i + K <= N; i++) {
		//计算区间[i,i+K-1]
		if ((dir[i] + sum) % 2 != 0) {
			//前端的牛面朝后方
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - K + 1 >= 0)
			sum -= f[i - K + 1];
	}
	for (i = N - K + 1; i < N; i++) {
		if ((dir[i] + sum) % 2 != 0)
			return -1;
		if (i - K + 1 >= 0)
			sum -= f[i - K + 1];
	}
	return res;
}
void solve()
{
	int K = 1, M = N;
	for (int k = 1; k <= N; k++) {
		int m = calc(k);
		if (m >= 0 && M > m) {
			M = m;
			K = k;
		}
	}
	cout << K << " " << M << endl;
}*/
/*Fliptile
按递增顺序生成所有n位二进制数
int flip[100][100];
void binary(int n)
{
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			flip[i][n - j - 1] = i >> j & 1;
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < n; j++)
			cout << flip[i][j];
		cout << endl;
	}
}
const int dx[5] = { 0,0,0,1,-1 };
const int dy[5] = { 1,-1,0,0,0 };
int M = 4, N = 4;
int tile[4][4] = {
	1,0,0,1,
	0,1,1,0,
	0,1,1,0,
	1,0,0,1
};
int opt[4][4];//保存最优解
int flip[4][4];//保存中间解
int get(int x, int y)
{
	int tx, ty, res = tile[x][y];
	for (int i = 0; i < 5; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < M && ty >= 0 && ty < N)
			res += flip[tx][ty];
	}
	return res % 2;
}
int calc()
{
	for (int i = 1; i < M - 1; i++)
		for (int j = 0; j < N; j++)
			if (get(i - 1, j) != 0)
				flip[i][j] = 1;
	for (int j = 0; j < N; j++)
		if (get(M - 1, j) != 0)
			return -1;
	// 统计翻转的次数
	int res = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			res += flip[i][j];
	return res;
}
void solve()
{
	int res = -1;
	for (int i = 0; i < 1 << N; i++) {
		memset(flip, 0, sizeof(flip));
		for (int j = 0; j < N; j++) {
			flip[0][N - j - 1] = i >> j & 1;
		}
		int num = calc();
		if (num > 0 && (res<0 || res>num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}
	if (res < 0)
		cout << "IMPOSSIBLE" << endl;
	else {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cout << opt[i][j] << (j + 1 == N ? '\n' : ' ');
	}
}*/
/*集合的整数表示
//空集：.......................................................0
//只含有第i个元素的集合{ i }：.................................1<<i
//含有全部n个元素的集合{0,1,…,n1}：.........................(1<<n)-1
//判断第i个元素是否属于集合S：.................................if (S>>i&1)
//向集合中加入第i个元素S { ∪ i}：.......................... ..S|1<<i
//从集合中去除第i个元素S\{i}：.................................S&~(1<<i)
//集合S和T的并集S∪T： ........................................S|T
//集合S和T的交集S∩T：.........................................S&T
void solve1(int sup)
{
	//枚举某个集合 sup 的子集
	int sub = sup;
	do {
		// 对子集的处理
		sub = (sub - 1) & sup;
	} while (sub != sup); // 处理完 0 之后，会有 -1 & sup = sup
}
void solve2(int k,int n)
{
	//枚举{0,1,…,n1}所包含的所有大小为 k的子集的方法
	int comb = (1 << k) - 1;
	while (comb < 1 << n) {
		// 这里进行针对组合的处理
		int x = comb & -comb, y = comb + x;
		comb = ((comb & ~y) / x >> 1) | y;
	}
}*/
/*弹性碰撞
int N = 2;
int H = 10;
int R = 10;
int T = 100;
const double g = 10.0;
double y[1000];//球的最终位置
double calc(int T)
{
	if (T < 0)
		return H;
	double t = sqrt(2 * H / g);
	int k = T / t;
	if (k % 2) {
		double d = k * t + t - T;
		return H - g * d * d / 2;
	}
	else {
		double d = k * t - T;
		return H - g * d * d / 2;
	}
}
void solve()
{
	for (int i = 0; i < N; i++)
		y[i] = calc(T - i);
	sort(y, y + N);
	for (int i = 0; i < N; i++)
		printf("%.2f%c", y[i] + 2 * R * i / 100.0, i + 1 == N ? '\n' : ' ');
}*/
//折半枚举(双向搜索)
/*有时候，问题的规模较大，无法枚举所有元素的组合，但能够枚举一半元素的组合。此时，将问题拆成两半后分别枚举，再合并它们的结果这一方法往往非常有效。
int n = 6;
int A[6] = { -45, -41, -36, -36, 26, -32 };
int B[6] = { 22, -27, 53, 30, -38, -54 };
int C[6] = { 42, 56, -37, -75, -10, -6 };
int D[6] = { -16, 30, 77, -46, 62, 45 };
int CD[36];
void solve()
{
	int cd, res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			CD[i * n + j] = C[i] + D[j];
	sort(CD, CD + n * n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cd = -(A[i] + B[j]);
			res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
		}
	cout << res << endl;
}*/
//超大背包问题
//这个问题是第二章介绍过的背包问题。不过这次价值和重量都可以是非常大的数值，相比之下n
//比较小。使用DP求解背包问题的复杂度是O(nW)，因此不能用来解决这里的问题。此时我们应该
//利用n比较小的特点来寻找其他办法。
/*typedef long long ll;
int n = 4;
ll w[4] = { 2,1,3,2 }, v[4] = { 3,2,4,2 };
ll W = 5;
pair<ll, ll> ps[1000];
void solve()
{
	//枚举前半部分
	int n2 = n / 2;
	for (int i = 0; i < 1 << n2; i++) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < n2; j++) {
			if (i >> j & 1) {
				sw += w[j];
				sv += v[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}
	//去除多余的元素
	sort(ps, ps + (1 << n2));//
	int m = 1;
	for (int i = 1; i < 1 << n2; i++)
		if (ps[m - 1].second < ps[i].second)//
			ps[m++] = ps[i];
	//枚举后半部分并求解
	ll res = 0;
	for (int i = 0; i < 1 << (n - n2); i++) {
		ll sw = 0, sv = 0;
		for (int j = 0; j < n - n2; j++) {
			if (i >> j & 1) {
				sw += w[n2 + j];
				sv += v[n2 + j];
			}
		}
		if (sw <= W) {
			ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;
			res = max(res, sv + tv);
		}
	}
	cout << res << endl;
}*/
/*坐标离散化
//w×h的格子上画了n条或垂直或水平的宽度为1的直线。求出这些线将格子划分成了多少个区域
//1 ≤ w, h ≤ 1000000
//1 ≤ n ≤ 500
//输入
int w = 10, h = 10, n = 5;
int X1[5] = { 1, 1, 4, 9, 10 };
int X2[5] = { 6, 10, 4, 9, 10 };
int Y1[5] = { 4, 8, 1, 1, 6 };
int Y2[5] = { 4, 8, 10, 5, 10 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
//填充用
bool fld[5 * 6][5 * 6];
// 对X1和X2进行坐标离散化，并返回离散化之后的宽度
int compress(int *X1, int *X2, int w)
{
	vector<int> vec;
	for (int i = 0; i < w; i++)
		for (int dx = -1; dx <= 1; dx++) {
			int tx1 = X1[i] + dx, tx2 = X2[i] + dx;
			if (0 <= tx1 && tx1 < w)
				vec.push_back(tx1);
			if (0 <= tx2 && tx2 < w)
				vec.push_back(tx2);
		}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < n; i++) {
		X1[i] = find(vec.begin(), vec.end(), X1[i]) - vec.begin();
		X2[i] = find(vec.begin(), vec.end(), X2[i]) - vec.begin();
	}
	return vec.size();
}
void solve()
{
	//坐标离散化
	w = compress(X1, X2, w);
	h = compress(Y1, Y2, h);
	//填充有直线的部分
	memset(fld, 0, sizeof(fld));
	for (int i = 0; i < n; i++)
		for (int x = X1[i]; x <= X2[i]; x++)
			for (int y = Y1[i]; y <= Y2[i]; y++)
				fld[x][y] = true;
	//求区域的个数
	int ans = 0;
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++) {
			if (fld[x][y])
				continue;
			fld[x][y] = true;
			ans++;
			//宽度优先搜索
			queue<pair<int, int>> que;
			que.push(make_pair(x, y));
			while (que.size()) {
				pair<int, int> p = que.front();
				que.pop();
				for (int i = 0; i < 4; i++) {
					int tx = p.first + dx[i], ty = p.second + dy[i];
					if (tx < 0 || tx >= w || ty < 0 || ty >= h || fld[tx][ty])
						continue;
					que.push(make_pair(tx, ty));
					fld[tx][ty] = true;
				}
			}
		}
	cout << ans << endl;
}*/
//活用各种数据结构
//线段树//完美二叉树//segment tree  //树状数组//binary indexed tree
//n个元素的线段树的初始化的时间复杂度和总的空间复杂度都是O(n),因为 节点 数是n+n/2+n/4+...=2n
/*const int MAX_N = 1 << 17;
//存储线段树的全局数组
int n, dat[2 * MAX_N - 1];
//基于线段树的RMQ实现
//初始化
void init(int n_)
{
	//为了简单起见，把元素个数扩大到2的幂
	int n = 1;
	while (n < n_)
		n *= 2;
	//把所有的值都设为INT_MAX
	for (int i = 0; i < 2 * n - 1; i++)
		dat[i] = INT_MAX;
}
//把第k个值(0-indexed)更新为a
void update(int k, int a)
{
	//叶子结点
	k += n - 1;
	dat[k] = a;
	//向上更新
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
	}
}
//求[a,b)的最小值
//后面的参数是为了计算方便而传入的
//k是结点的编号,l,r表示这个节点对应的是[l,r)区间
//在外部调用时，用query(a,b,0,0,n)
int query(int a, int b, int k, int l, int r)
{
	//如果[a,b)和[l,r)不相交,则返回INT_MAX
	if (r <= a || b <= l)
		return INT_MAX;
	//如果[a,b)完全包含[l,r),则返回当前节点的值
	if (a <= l && r <= b)
		return dat[k];
	else {
		//否则返回两个儿子中值的较小值
		int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}*/
/*const int ST_SIZE = (1 << 6) - 1;
//输入
int N = 3, C = 2;
int L[3] = { 5,5,5 };
int S[2] = { 1,2 };
int A[2] = { 270,90	 };
//线段树所维护的数据
double vx[ST_SIZE], vy[ST_SIZE];//各节点的向量
double ang[ST_SIZE];//各节点的角度
//为了查询角度的变化而保存当前角度的数组
double prv[ST_SIZE];
//初始化
void init(int k,int l,int r)
{
	vx[k] = ang	[k] = 0.0;
	if (r - l == 1)
		vy[k] = L[l];
	else {
		init(2 * k + 1, l, (l + r) / 2);
		init(2 * k + 2, (l + r) / 2, r);
		vy[k] = vy[2 * k + 1] + vy[2 * k + 2];
	}
}
//把s和s+1的角度变为a
//v是节点的编号,l,r表示当前节点对应的是[l,r)区间
void change(int s, double a, int v, int l, int r)
{
	if (s <= l)
		return;
	else if (s < r) {
		change(s, a, 2 * v + 1, l, (l + r) / 2);
		change(s, a, 2 * v + 2, (l + r) / 2, r);
		if (s <= (l + r) / 2)
			ang[v] += a;
		double s = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[2 * v + 1] + (c * vx[2 * v + 2] - s * vy[2 * v + 2]);
		vy[v] = vy[2 * v + 1] + (s * vx[2 * v + 2] + c * vy[2 * v + 2]);
	}
}
void solve()
{
	init(0, 0, N);
	for (int i = 1; i < N; i++)
		prv[i] = PI;
	for (int i = 0; i < C; i++) {
		int s = S[i];
		double a = A[i] * PI / 180.0;
		change(s, a - prv[s], 0, 0, N);
		prv[s] = a;
		cout << vx[0] << " " << vy[0] << endl;
	}
}*/
/*树状数组(BIT)
//给一个初始值全为0的数列a1,a2,..an
//给定i和x,执行ai+=x
//BIT的复杂度 O(logn)
//[1,n]
int bit[1000],N = 4;
int sum(int i)
{
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x)
{
	while (i <= N) {
		bit[i] += x;
		i += i & -i;
	}
}
//冒泡排序的交换次数
int n = 4;
int a[4] = { 3,1,4,2 };
void solve()
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i - sum(a[i]);
		add(a[i], 1);
	}
	cout << ans << endl;
}*/
//const int DAT_SIZE = 1 << 18 - 1;
/*输入
int N, Q;
int A[1000];
char T[1000];
int L[1000], R[1000], X[1000];
线段树的做法
ll dat[1000], datb[1000];
//对区间[a,b)同时加x
//k是节点的编号,对应的区间是[l,r)
void add(int a, int b, int x, int k, int l, int r)
{
	if (b <= l || r <= a)
		return;
	if (a <= l && r <= b)
		dat[k] += x;
	else if (l < b && a < r) {
		datb[k] += (min(b, r) - max(a, l)) * x;
		add(a, b, x, k, l, (l + r) / 2);
		add(a, b, x, k, (l + r) / 2, r);
	}
}
//计算[a,b)的和
//k是节点的编号,对应的区间是[l,r)
ll sum(int a, int b, int k, int l, int r)
{
	if (b <= l || r <= a)
		return 0;
	if (a <= l && r <= b)
		return dat[k] * (r - l) + datb[k];
	else {
		ll res = (min(r, b) - max(l, a)) * dat[k];
		res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
		res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
		return res;
	}
}
void solve()
{
	for (int i = 0; i < N; i++)
		add(i, i + 1, A[i], 0, 0, N);
	for (int i = 0; i < Q; i++) {
		if (T[i] == 'C')
			add(L[i], R[i] + 1, X[i], 0, 0, N);
		else
			cout << sum(L[i], R[i] + 1, 0, 0, N) << endl;
	}
}*/
/*树状数组的做法//前缀和的增加量
//如果操作得到的结果可以用i的n次多项式表示，那么可以用n+1个树状数组来进行维护
//输入
int N, Q;
int A[1000];
char T[1000];
int L[1000], R[1000], X[1000];
//BIT
ll bit0[1001], bit1[1001];
ll sum(ll *b, ll i)
{
	ll s = 0;
	while (i > 0) {
		s += b[i];
		i -= i & -i;
	}
	return s;
}
void add(ll *b, int i, int v)
{
	while (i <= N) {
		b[i] += v;
		i += i & -i;
	}
}
void solve()
{
	for (int i = 1; i <= N; i++)
		add(bit0, i, A[i]);
	for (int i = 0; i < Q; i++) {
		if (T[i] == 'C') {
			add(bit0, L[i], -X[i] * (L[i] - 1));
			add(bit1, L[i], X[i]);
			add(bit0, R[i] + 1, X[i] * R[i]);
			add(bit1, R[i] + 1, -X[i]);
		}
		else {
			ll res = 0;
			res += sum(bit0, R[i]) + sum(bitint 1, R[i]) * R[i];
			res -= sum(bit0, L[i] - 1) + sum(bit1, L[i] - 1) * (L[i] - 1);
			cout << res << endl;
		}
	}
}*/
/*分桶法和平方分割
//第k个数
const int ST_SIZE = (1 << 18) - 1;
const int MAX_N = 100000;
const int MAX_M = 5000;
const int B = 1000;//桶的大小
//输入
int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];*/
/*平方分割
int nums[MAX_N];//对A排序后的结果
vector<int> bucket[MAX_N / B];//每个桶排序后的结果
void solve()
{
	for (int i = 0; i < N; i++) {
		bucket[i / B].push_back(A[i]);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	for (int i = 0; i < N / B; i++)
		sort(bucket[i].begin(), bucket[i].end());
	for (int i = 0; i < M; i++) {
		int l = I[i], r = J[i] + 1, k = K[i];
		int lb = -1, ub = N - 1;
		while (ub - lb > 1) {
			int md = (lb + ub) / 2;
			int x = nums[md];
			int tl = l, tr = r, c = 0;
			//区间两端多出的部分
			while (tl < tr && tl % B != 0)
				if (A[tl++] <= x)
					c++;
			while (tl < tr && tr % B != 0)
				if (A[--tr] <= x)
					c++;
			//对每一个桶计算
			while (tl < tr) {
				int b = tl / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;
			}
			if (c >= k)
				ub = md;
			else
				lb = md;
		}
		cout << nums[ub] << endl;
	}
}*/
/*线段树
int nums[MAX_N];
vector<int> dat[ST_SIZE];
//构建线段树
//k是节点的编号,和区间[l,r)对应
void init(int k, int l, int r)
{
	if (r - l == 1)
		dat[k].push_back(A[l]);
	else {
		init(2 * k + 1, l, (l + r) / 2);
		init(2 * k + 2, (l + r) / 2, r);
		dat[k].resize(r - l);
		merge(dat[2 * k + 1].begin(), dat[2 * k + 1].end(), dat[2 * k + 2].begin(), dat[2 * k + 2].end(), dat[k].begin());
	}
}
//计算[i,j)中不超过x的数的个数
//k是节点的编号，和区间[l,r)相对应
int query(int i, int j, int x, int k, int l, int r)
{
	if (j <= l || r <= i)
		return 0;
	if (i <= l && r <= j)
		return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	else {
		int lc = query(i, j, x, 2 * k + 1, l, (l + r) / 2);
		int rc = query(i, j, x, 2 * k + 2, (l + r) / 2, r);
		return lc + rc;
	}
}
void solve()
{
	for (int i = 0; i < N; i++)
		nums[i] = A[i];
	sort(nums, nums + N);
	init(0, 0, N);
	for (int i = 0; i < M; i++) {
		int l = I[i], r = J[i], k = K[i];
		int lb = -1, ub = N - 1;
		while (ub - lb > 1) {
			int md = (lb + ub) / 2;
			int c = query(l, r, nums[md], 0, 0, N);
			if (c >= k)
				ub = md;
			else
				lb = md;
		}
		cout << nums[ub] << endl;
	}
}*/
//熟练掌握动态规划
//TSP(Travelling Saleman Problem)旅行商问题//NP问题
//针对集合的DP:状态压缩DP
/*int n;
int d[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];*/
//判断第i个元素是否属于集合S：.................................if (S>>i&1)
//向集合中加入第i个元素S { ∪ i}：.......................... ..S|1<<i
/*已经访问过的节点集合为S,当前位置为v
int rec(int S, int v)//O(2^n*n^2)
{
	if (dp[S][v] >= 0)
		return dp[S][v];
	if (S == (1 << n) - 1 && v == 0)//已访问过所有节点并回到0节点
		return 0;
	int res = INF;
	for (int u = 0; u < n; u++)
		if (!(S >> u & 1))//下一步移动到节点u
			res = min(res, rec(S | 1 << u, u) + d[v][u]);
	return dp[S][v] = res;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0) << endl;
}*/
/*void solve()
{
	//用足够大的数初始化数组
	for (int S = 0; S < (1 << n); S++)
		fill(dp[S], dp[S] + n, INF);
	dp[(1 << n) - 1][0] = 0;
	//根据递推式依次计算
	for (int S = (1 << n) - 2; S >= 0; S--)
		for (int v = 0; v < n; v++)
			for (int u = 0; u < n; u++)
				if (!(S >> u & 1))
					dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u]);
	cout << dp[0][0] << endl;
}*/
/*输入
int n, m, a, b;//n张车票,m个城市,从城市a到城市b
int t[1000];
int d[1000][1000];//图的邻接矩阵表示(-1表示没有边)
double dp[1 << MAX_N][MAX_N];
//dp[S][v]:到达剩下的车票集合为S并且现在在城市v的状态所需要的最小花费
//从集合中去除第i个元素S\{i}：.................................S&~(1<<i)
void solve()
{
	for (int S = 0; S < (1 << n); S++)
		fill(dp[S], dp[S] + m, INF);
	dp[(1 << n) - 1][a - 1] = 0;
	double res = INF;
	for (int S = (1 << n) - 1; S >= 0; S--) {
		res = min(res, dp[S][b - 1]);
		for (int v = 0; v < m; v++) {
			for (int i = 0; i < n; i++) {
				if (S >> i & 1) {
					for (int u = 0; u < m; u++) {
						if (d[v][u] >= 0) {
							//使用车票i,从v移动到u
							dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + double(d[v][u]) / t[i]);
						}
					}
				}
			}
		}
	}
	if (res == INF)
		cout << "Impossible" << endl;
	else
		cout << res << endl;
}*/
/*铺砖问题
int n, m;
bool color[15][15];//false:白 true:黑
int rec(int i, int j, bool used[15][15])//O(nm2^(nm))
{
	if (j == m)//下一行
		return rec(i + 1, 0, used);
	if (i == n)//已经覆盖了所有的空格
		return 1;
	if (used[i][j] || color[i][j])//不需要放置方块
		return rec(i, j + 1, used);
	//尝试两种放法
	int res = 0;
	used[i][j] = true;
	//横着放
	if (j + 1 < m && !used[i][j + 1] && !color[i][j + 1]) {
		used[i][j + 1] = true;
		res += rec(i, j + 1, used);//
		used[i][j + 1] = false;
	}
	//竖着放
	if (i + 1 < n && !used[i + 1][j] && !color[i + 1][j]) {
		used[i + 1][j] = true;
		res += rec(i, j + 1, used);//不变
		used[i + 1][j] = false;
	}
	used[i][j] = false;
	return res;
}
void solve()
{
	bool used[15][15];
	memset(used, 0, sizeof(used));
	cout << rec(0, 0, used) << endl;
}*/
//平面图的完美匹配的个数可以在多项式时间内求解，这个问题可以高效地求解

//判断第i个元素是否属于集合S：.................................if (S>>i&1)
//向集合中加入第i个元素S { ∪ i}：.......................... ..S|1<<i
//从集合中去除第i个元素S\{i}：.................................S&~(1<<i)
/*
int dp[2][1 << MAX_N];//DP数组(滚动循环数组)
void solve()//???????????wsmwsmwsmwsm
{
	int *crt = dp[0], *next = dp[1];
	crt[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			for (int used = 0; used < 1 << m; used++) {
				if ((used >> j & 1) || color[i][j]) {
					//不需要在(i,j)放置砖块
					next[used] = crt[used & ~(1 << j)];
				}
				else {//尝试两种方法
					int res = 0;
					//横着放
					if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j + 1]) {
						res += crt[used | 1 << (j + 1)];
					}
					//竖着放
					if (i + 1 < n && !color[i + 1][j]) {
						res += crt[used | 1 << j];
					}
					next[used] = res;
				}
			}
			swap(crt, next);
		}
	}
	cout << crt[0] << endl;
}*/
/*用二维vector来表示矩阵
typedef vector<int> vec;
typedef vector<vec> mat;
const int M = 10000;
//计算A*B
mat mul(mat &A, mat &B)
{
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++) {
		for (int k = 0; k < B.size(); k++) {
			for (int j = 0; j < B[0].size(); j++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}
mat pow(mat A, ll n)
{
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); i++)
		B[i][i] = 1;
	while (n > 0) {
		if (n & 1)
			B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
ll n;
void solve()
{
	mat A(2, vec(2));
	A[0][0] = 1; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 0;
	A = pow(A, n);
	cout << A[1][0];
}
//S=A+A^2+A^3+...+A^k
//求矩阵A的幂的和//分块矩阵*/
/*利用数据结构高效求解//线段树
int m = 6, n_ = 40;
int s[1000] = { 20,1,10,20,15,30 }, t[1000] = { 30,10,20,30,25,40 };
int dp[1001];//DP数组
const int MAX_N = 1 << 17;
//存储线段树的全局数组
int n, dat[2 * MAX_N - 1];
//基于线段树的RMQ实现
//初始化
void init(int n_)
{
	//为了简单起见，把元素个数扩大到2的幂
	n = 1;
	while (n < n_)
		n *= 2;
	//把所有的值都设为INT_MAX
	for (int i = 0; i < 2 * n - 1; i++)
		dat[i] = INF;
}
//把第k个值(0-indexed)更新为a
void update(int k, int a)
{
	//叶子结点
	k += n - 1;
	dat[k] = a;
	//向上更新
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
	}
}
//求[a,b)的最小值
//后面的参数是为了计算方便而传入的
//k是结点的编号,l,r表示这个节点对应的是[l,r)区间
//在外部调用时，用query(a,b,0,0,n)
int query(int a, int b, int k, int l, int r)
{
	//如果[a,b)和[l,r)不相交,则返回INT_MAX
	if (r <= a || b <= l)
		return INF;
	//如果[a,b)完全包含[l,r),则返回当前节点的值
	if (a <= l && r <= b)
		return dat[k];
	else {
		//否则返回两个儿子中值的较小值
		int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}
void solve()
{
	init(n_);
	fill(dp, dp + n_, INF);
	dp[0] = 0;
	for (int i = 0; i < n_; i++)
		update(i, dp[i]);
	for (int i = 0; i < m; i++) {
		dp[t[i] - 1] = min(dp[t[i] - 1], query(s[i] - 1, t[i], 0, 0, n) + 1);
		update(t[i] - 1,dp[t[i] - 1]);
	}
	cout << dp[n_ - 1] << endl;
}*/
//利用水流解决问题的网络流
//最大流最小割定理：最大流等于最小割
//如果所有边的容量都是整数，那么最大流和最小割也是整数
/*最大流问题与Ford-Fulkerson算法//用于表示边的结构体(终点、容量、反向边)
struct edge { int to, cap, rev; };
vector<edge> G[100];//图的邻接表表示
bool used[100];//DFS中用到的访问标记
//向图中增加一条从s到t容量为cap的边
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge{ to,cap,(int)G[to].size() });
	G[to].push_back(edge{ from,0,(int)G[from].size() - 1 });
}
//通过dfs寻找增广路
int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		//注意这个&是别名的意思,对e操作就是对G[v][i]进行操作
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
//求解s到t的最大流
int max_flow(int s,int t)
{
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
			return flow;
		flow += f;
	}
}
int main()
{
	add_edge(0, 1, 10);
	add_edge(1, 3, 6);
	add_edge(0, 2, 2);
	add_edge(1, 2, 6);
	add_edge(3, 2, 3);
	add_edge(2, 4, 5);
	add_edge(3, 4, 8);
	cout << max_flow(0, 4);
	return 0;
}*/
/*dinic算法//Ford-Fulkerson算法的优化
struct edge { int to, cap, rev; };
vector<edge> G[1000];
int level[1000];
int iter[1000];
//向图中增加一条从s到t容量为cap的边
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge{ to,cap,(int)G[to].size() });
	G[to].push_back(edge{ from,0,(int)G[from].size() - 1 });
}
//通过BFS计算从源点出发的距离标号
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (level[e.to] < 0 && e.cap>0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
//通过dfs寻找增广路
int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	for (int &i = iter[v]; i < G[v].size(); i++) {
		edge &e = G[v][i];
		//注意这个&是别名的意思,对e操作就是对G[v][i]进行操作
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
//求解s到t的最大流
int max_flow(int s, int t)
{
	int flow = 0;
	for (;;) {
		bfs(s);
		if (level[t] < 0)
			return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF))	 > 0) {
			flow += f;
		}
	}
}
int main()
{
	add_edge(0, 1, 10);
	add_edge(1, 3, 6);
	add_edge(0, 2, 2);
	add_edge(1, 2, 6);
	add_edge(3, 2, 3);
	add_edge(2, 4, 5);
	add_edge(3, 4, 8);
	cout << max_flow(0, 4);
	return 0;
}*/
/*二分图匹配 1.最大流问题 2.匈牙利算法
//指派问题,最大匹配,二分图匹配//最大流问题的一种特殊情况
//利用所有的边的容量都是1以及二分图的性质,可以将二分图最大匹配算法更简洁实现
int V;//顶点数
vector<int> G[1000];//图的邻接表表示
int match[1000];//所匹配的顶点
bool used[1000];//DFS中用到的访问标记
//向图中增加一条从s到t容量为cap的边
void add_edge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i], w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {//u未匹配过或者u和w匹配过但没有尝试过给w重新匹配就尝试给w匹配
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
//求解二分图的最大匹配
int bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; v++)
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v))
				res++;
		}
	return res;
}*/
/*一般图匹配//结对子//Edmonds算法等高效的算法实现比较复杂
//匹配、边覆盖、独立集、顶点覆盖
//(1)对于不存在孤立点的图,|最大匹配|+|最小边覆盖|=顶点数
//(2)|最大独立集|+|最小顶点覆盖|=定点数
//(3)对于二分图而言,|最大匹配|=|最小顶点覆盖|
*/
//最小费用流
//Bellman-Ford算法
/*用于表示边的结构体
struct edge { int to, cap, cost, rev; };
int V;//顶点数
vector<edge> G[1000];//图的邻接表表示
int dist[1000];//最短距离
int prevv[1000], preve[1000];//最短路中的前驱节点和对应的边
//向图中增加一条从s到t容量为cap费用为cost的边
void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back(edge{ to,cap,cost,(int)G[to].size() });
	G[to].push_back(edge{ from,0,-cost,(int)G[from].size() - 1 });
}
//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s, int t, int f)
{
	int res = 0;
	while (f > 0) {
		//利用Bellman-Ford算法求从s到t的最短路
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; v++) {
				if (dist[v] == INF)
					continue;
				for (int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] < dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}

		if (dist[t] == INF)//不能再增广
			return -1;

		//沿s到t的最短路尽量增广
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += d * dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}*/
/*Dijkstra算法
//在该顶点的势中h[v]是上一次s到v顶点的最短路
typedef pair<int, int> P;//first保存最短距离,second保存顶点编号
//用于表示边的结构体
struct edge { int to, cap, cost, rev; };
int V;//顶点数
vector<edge> G[1000];//图的邻接表表示
int h[1000];//顶点的势
int dist[1000];//最短距离
int prevv[1000], preve[1000];//最短路中的前驱节点和对应的边
//向图中增加一条从s到t容量为cap费用为cost的边
void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back(edge{ to,cap,cost,(int)G[to].size() });
	G[to].push_back(edge{ from,0,-cost,(int)G[from].size() - 1 });
}
//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s, int t, int f)
{
	int res = 0;
	fill(h, h + V, 0);
	while (f > 0) {
		//利用Dijkstra算法更新h
		priority_queue<P, vector<P>, greater<P>> que;
		fill(dist, dist + V, INF);
		dist[s] = 0;
		que.push(P(0, s));
		while (que.size()) {
			P p = que.top; que.pop();
			int v = p.second;
			if (dist[v] < p.first)
				continue;
			for (int i = 0; i < G[v].size(); i++) {
				edge &e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + h[v] - h[e.to] + e.cost) {//注意条件的判断
					dist[e.to] = dist[v] + h[v] - h[e.to] + e.cost;               //注意上一行注释
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(P(dist[e.to], e.to));
				}
			}
		}

		if (dist[t] == INF)//不能再增广
			return -1;
		for (int v = 0; v < V; v++)//更新h[v]
			h[v] += dist[v];

		//沿s到t的最短路尽量增广
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += d * h[t];//h[t]
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}*/
//更加复杂的数学世界
//矩阵
//线性方程组
const double EPS = 1E-8;
typedef vector<double> vec;
typedef vector<vec> mat;
/*求解Ax=b,其中A是方阵
//当方程组无解或者有无穷多解时，返回一个长度为0的数组 //高斯消元法 O(n^3)
vec gauss_jordan(const mat& A, const vec& b)
{
	int n = A.size();
	mat B(n, vec(n + 1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			B[i][j] = A[i][j];
	//把b放在A的右边方便一起处理
	for (int i = 0; i < n; i++)
		B[i][n] = b[i];
	for (int i = 0; i < n; i++) {
		//把正在处理的未知数系数对的绝对值最大的式子换到第i行
		int pivot = i;
		for (int j = i; j < n; j++)
			if (abs(B[j][i]) > abs(B[pivot][i]))
				pivot = j;
		swap(B[i], B[pivot]);
		//无解或者有无穷多组解
		if (abs(B[i][i]) < EPS)
			return vec();
		//把正在处理的未知数的系数变为1
		for (int j = i + 1; j <= n; j++)
			B[i][j] /= B[i][i];
		B[i][i] = 1;
		for (int j = 0; j < n; j++)
			if (j != i) {
				for (int k = i + 1; k <= n; k++)
					B[j][k] -= B[j][i] * B[i][k];
				B[j][i] = 0;
			}
	}
	vec x(n);
	//存放在右边的b就是答案
	for (int i = 0; i < n; i++)
		x[i] = B[i][n];
	return x;
}*/
/*int main()
{
	mat A = { vec({1,1,1}),vec({1,2,4}),vec({1,3,9}) };
	vec b = { 3,7,13 };
	vec c = gauss_jordan(A, b);
	for (auto it = c.begin(); it != c.end(); it++)
		cout << *it << " ";
	return 0;
}*/
/*期望值和方程组//Random walk
char gird[3][10] = { {'.','#','.','.','.','#','.','.','.','#'},
					 {'.','#','.','#','.','#','.','#','.','#'},
					 {'.','.','.','#','.','.','.','#','.','.'} };
int N = 3, M = 10;
bool can_goal[3][10];//can_goal[x][y]为true的话,(x,y)可以到达终点
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
//搜索可以到达终点的点
void dfs(int x,int y)
{
	can_goal[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && gird[nx][ny] != '#'  &&!can_goal[nx][ny])
			dfs(nx, ny);
	}
}
void main()
{
	mat A(N * M, vec(N * M, 0));
	vec b(N * M, 0);
	memset(can_goal, 0, sizeof(can_goal));
	dfs(N - 1, M - 1);
	//构建矩阵
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++) {
			if (x == N - 1 && y == M - 1 || !can_goal[x][y]) {
				//到达终点或者是(x,y)无法到达终点的情况
				A[x * M + y][x * M + y] = 1;
				continue;
			}
			//其余情况
			int move = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < M && gird[nx][ny] == '.') {
					A[x * M + y][nx * M + ny] = -1;
					move++;
				}
			}
			b[x * M + y] = A[x * M + y][x * M + y] = move;
		}
	vec res = gauss_jordan(A, b);
	cout << res[0] << endl;
}*/
/*模运算的世界
//1.逆元：满足ax=1(mod m)，x叫做a的逆元//求解线性同余方程//如果gcd(a,m)!=1，则逆元不存在  (转化为ax-mk=1)
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int extgcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int ans = extgcd(b, a % b, x, y);
	int temp = x;
	x = y;
	y = temp - (a / b) * x;
	return ans;
}
int mod_inverse(int a, int m)
{
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}*/
/*费马小定理
//在p是素数的情况下,对任意整数x都有x^p=x(mod p)
//如果x无法被p整除,有x^(p-1)=1(mod p)
//求欧拉函数的值
int euler_phi(int n)
{
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (; n % i == 0; n /= i)
				;
		}
	}
	if (n != 1)
		res = res / n * (n - 1);
	return res;
}
int euler[1000];
void euler_phi2(int n)
{
	for (int i = 0; i < 1000; i++)
		euler[i] = i;
	for (int i = 2; i < 1000; i++)
		if (euler[i] == i)
			for (int j = i; j < 1000; j += i)
				euler[j] = euler[j] / i * (i - 1);
}*/
//线性同余方程组
//中国剩余定理
/*n的阶乘
int fact[1000];//预处理的n! mod p的表
//分解n!=ap^e,返回a mod p O(log p n)
int mod_fact(int n, int p, int& e)
{
	e = 0;
	if (n == 0)
		return 1;
	//计算p的倍数的部分
	int res = mod_fact(n / p, p, e);
	e += n / p;
	//由于(p-1)!=-1,因此(p-1)!^(n/p)只需要知道n/p的奇偶性就可以计算了
	if (n / p % 2 != 0)
		return res * (p - fact[n % p]) % p;
	return res * fact[n % p] % p;
}*/
/*Cnk mod p O(log p n)
int mod_comb(int n, int k, int p)
{
	if (n < 0 || k < 0 || n < k)
		return 0;
	int e1, e2, e3;
	int a1 = mod_fact(n, p, e1), a2 = mod_fact(n, p, e2), a3 = mod_fact(n, p, e3);
	if (e1 > e2 + e3)
		return 0;
	return a1 * mod_inverse(a2 * a3 % p, p) % p;
}*/
/*容斥原理
int a[1000] = { 2,3 };
int n = 100, m = 2;
void solve()
{
	ll res = 0;
	for (int i = 1; i < (1 << m); i++) {
		int num = 0;
		for (int j = i; j != 0; j >>= 1)
				num += j & 1;
		ll lcm = 1;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				lcm = lcm / gcd(lcm, a[j]) * a[j];
				if (lcm > n)//如果lcm大于n，则n/lcm=0，因此在溢出前break
					break;
			}
		}
		if (num % 2 == 0)
			res -= n / lcm;
		else
			res += n / lcm;
	}
	cout << res;
}*/
/*莫比乌斯函数
//没有周期性的字符串的计数
//把n的约数的莫比乌斯函数值用map的形式返回 O(根号n)
map<int, int> moebius(int n)
{
	map<int, int> res;
	vector<int> primes;

	//枚举n的质因数
	for (int i = 2; i * i < n; i++)
		if (n % i == 0) {
			primes.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n != 1)
		primes.push_back(n);
	int m = primes.size();
	for (int i = 0; i < (1 << m); i++) {
		int mu = 1, d = 1;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				mu *= -1;
				d *= primes[j];
			}
		}
		res[d] = mu;
	}
	return res;
}
const int MOD = 10009;
//输入
int n = 15315300;
int mod_pow(int x, int n, int mod)
{
	if (n == 0)
		return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1)
		res = res * x % mod;
	return res;
}
void solve()
{
	int res = 0;
	map<int, int> mu = moebius(n);
	for (auto it = mu.begin(); it != mu.end(); ++it) {
		res += it->second * mod_pow(26, n / it->first, MOD);
		res = (res % MOD + MOD) % MOD;
	}
	cout << res << endl;
}*/
/*具有对称性的计数//Polya计数定理//和容斥原理不同,先把所有方案重复计算了相同的次数,然后再把结果除以重复的次数,这样的计数方法,称为Polya计数定理
//石头染色方案计数问题//n块石头排成一排,要用m种颜色染这n块石头,问一共有多少种不同的染色方案
ll mod_pow(ll x, ll n, ll mod)
{
	if (n == 0)
		return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1)
		res = res * x % mod;
	return res;
}
//约数枚举 O(根号n)
vector<int> divisor(int n)
{
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (n / i != i)
				res.push_back(n / i);
		}
	}
	return res;
}
//整数分解 O(根号n)
map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res[i] = 0;
			while (n % i == 0) {
				++res[i];
				n /= i;
			}
		}
	}
	if (n != 1)
		res[n] = 1;
	return res;
}
const int MOD = 1000000007;
int n = 1000000000, m = 1000000000;
void solve()
{
	map<int, int> primes = prime_factor(n);
	vector<int> divs = divisor(n);
	ll res = 0;
	for (unsigned int i = 0; i < divs.size(); i++) {
		//求divs[i]的函数值
		ll euler = divs[i];
		for (auto it = primes.begin(); it != primes.end(); ++it) {
			int p = it->first;
			if (divs[i] % p == 0)
				euler = euler / p * (p - 1);
		}
		res += euler * mod_pow(m, n / divs[i], MOD) % MOD;
		res %= MOD;
	}
	//最后除以n//注意是模的除法,不一样***
	cout << res * mod_pow(n, MOD - 2, MOD) % MOD;
}
int main()
{
	solve();
	return 0;
}*/
//找出游戏的必胜策略
/*硬币游戏
int X = 10, K = 2, A[1000] = { 1,4 };
bool win[1001];//动态规划数组
void solve()
{
	//轮到自己没有币了
	win[0] = false;
	for (int j = 1; j <= X; j++) {
		win[j] = false;
		for (int k = 0; k < K; k++)
			win[j] |= A[k] <= j && !win[j - A[k]];
	}
	if (win[X])
		puts("Alice");
	else
		puts("Bob");
}
*/
/*A funny Game//圈的游戏其实是智力游戏
int n;
void solve()
{
	if (n <= 2)
		puts("Alice");
	else
		puts("Bob");
}*/
/*Euclid's Game
int a, b;
void solve()
{
	bool f = true;
	for (;;) {
		if (b > a)
			swap(a, b);
		//b是a的倍数时毕胜
		if (a % b == 0)
			break;
		//如果是解说中的第二种情况必胜
		if (a - b > b)
			break;
		a -= b;
		f = !f;
	}
	if (f)
		puts("Stan wins");
	else
		puts("Ollien wins");
}*/
/*Nim的经典游戏,该游戏的策略成为了许多游戏的基础
//有n堆石子,每堆各有ai颗石子。Alice和Bob分别轮流从非空的石子堆中取走至少一颗石子。
//Alice先取,取光所有石子的一方获胜,当双方都采取最优策略时,谁会获胜?
//异或就行
int N = 3, A[1000] = { 1,2,4 };
void solve()
{
	int x = 0;
	for (int i = 0; i < N; i++)
		x ^= A[i];
	if (x != 0)
		puts("Alice");
	else
		puts("Bob");
}*/
/*Georgia and Bob
//移动棋子的游戏
const int MAX_N = 1000;
int N, P[1000];
void solve()
{
	if (N % 2 == 1)
		P[N++] = 0;
	sort(P, P + N);
	int x = 0;
	for (int i = 0; i + 1 < N; i+=2) {
		x ^= (P[i + 1] - P[i] - 1);
	}
	if (x == 0)
		puts("Bob will win");
	else
		puts("Georgia will win");
}*/
//Grundy数
/*硬币游戏升级版
//给定k个数字a1,a2,...,ak.一开始有n堆硬币，每堆各有xi枚硬币
int n = 3, k = 3, a[3] = { 1,3,4 }, x[3] = { 5,6,7 };
//利用动态规划计算grundy值的数组
int grundy[8];
void solve()
{
	//轮到自己时剩0枚则毕败
	grundy[0] = 0;
	//计算grundy值
	for (int i = 1; i <= *max_element(x, x + 3); i++) {
		set<int> s;
		for (int j = 0; j < k; j++)
			if (i >= a[j])
				s.insert(grundy[i - a[j]]);
		int g = 0;
		while (s.count(g) != 0)
			g++;
		grundy[i] = g;
	}
	//判断胜负
	int y = 0;
	for (int i = 0; i < n; i++)
		y ^= grundy[x[i]];
	if (y != 0)
		puts("Alice");
	else
		puts("Bob");
}*/
/*Cutting Game//2<=w,h<=200
int w = 2, h = 2;
int mem[10][10];
int grundy(int w, int h)
{
	if (mem[w][h] != -1)
		return mem[w][h];
	set<int> s;
	for (int i = 1; w - i >= 2; i++)
		s.insert(grundy(i, h) ^ grundy(w - i, h));
	for (int i = 1; h - i >= 2; i++)
		s.insert(grundy(w, i) ^ grundy(w, h - i));
	int g = 0;
	while (s.count(g) != 0)
		g++;
	return mem[w][h] = g;
}
void solve()
{
	memset(mem, -1, sizeof(mem));
	if (grundy(w, h) != 0)
		puts("WIN");
	else
		puts("LOSE");
}*/
//成为图论大师
/*强连通分量分解
//任意有向图都可以分解成若干不相交的强连通分量，这就是强连通分量分解。
//把分解后的强连通分量缩成一个顶点，就得到了一个DAG（有向无环图）。
int V;//顶点数
vector<int> G[1000];//图的邻接表表示
vector<int> rG[1000];//把边反向后的图
vector<int> vs;//后序遍历顺序顶点列表
bool used[1000];//访问标记
int cmp[1000];//所属强连通分量的拓扑序
void add_edge(int from, int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); i++)
		if (!used[G[v][i]])
			dfs(G[v][i]);
	vs.push_back(v);
}
void rdfs(int v, int k)
{
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < (int)rG[v].size(); i++)
		if (!used[rG[v][i]])
			rdfs(rG[v][i], k);
}
int scc()
{
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++)
		if (!used[v])
			dfs(v);
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--)
		if (!used[vs[i]])
			rdfs(vs[i], k++);
	return k;
}*/
/*Popular Cows
int N = 3, M = 3;
int A[3] = { 1,2,2 }, B[3] = { 2,1,3 };
void solve()
{
	V = N;
	for (int m = 0; m < M; m++)
		add_edge(A[m] - 1, B[m] - 1);
	int n = scc();

	// 统计备选解的个数
	int u = 0, v, num = 0;
	for (int v = 0; v < V; v++)
		if (cmp[v] == n - 1) {
			u = v;
			num++;
		}

	// 检查是否从所有点可达
	memset(used, 0, sizeof(used));
	rdfs(u, 0);// 重用强连通分量分解的代码
	for (int v = 0; v < V; v++)
		if (!used[v]) {
			// 从该点不可达
			cout << 0 << endl;
			return;
		}
	cout << num << endl;
}*/
/*2-SAT//给定一个布尔方程，判断是否存在一组布尔变量的真值指派使整个方程为真的问题，被称为布尔方程的可满足性问题（SAT）
//利用强连通分量分解，可以在布尔公式子句数的线性时间内解决2-SAT问题
//首先，利用⇒（蕴涵）将每个子句(a ∨ b)改写成等价形式(¬ a ⇒ b ∧¬ b ⇒ a)
//这样原布尔公式就变成了把 a ⇒ b 形式的布尔公式用∧连接起来的形式
//(a∨¬b)∧(b∨c)∧(¬c∨¬a)所对应的图   //x 所在的强连通分量的拓扑序在¬ x 所在的强连通分量之后 ⇔  x 为真
int main()
{
	// 布尔公式为(a∨ ¬b)∧ (b∨ c)∧ (¬c∨ ¬a)时
	// 构造6个顶点，分别对应a、b、c、¬a、¬b、¬c//0,1,2,3,4,5
	V = 6;
	add_edge(3, 4);
	add_edge(1, 0);
	add_edge(4, 2);
	add_edge(5, 1);
	add_edge(2, 3);
	add_edge(0, 5);
	scc();
	for (int i = 0; i < 3; i++)
		if (cmp[i] == cmp[i + 3]) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES";
	for (int i = 0; i < 3; i++) {
		if (cmp[i] > cmp[i + 3])
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
	return 0;
}*/
/*Priest John’s Busiest Day
const int MAX_N = 1000;
int N = 2;
int S[MAX_N] = { 480,495 }, T[MAX_N] = { 540,540 }, D[MAX_N] = { 30,20 }; //S和T是换算成分钟后的时间
void solve()
{
	// 0~N-1：x_i
	// N~2N-1: ¬x_i
	V = N * 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++) {
			if (min(S[j] + D[j], S[i] + D[i]) > max(S[j], S[i])) {
				add_edge(i, N + j);
				add_edge(j, N + i);
			}
			if (min(S[i] + D[i], T[j]) > max(S[i], T[j] - D[j])) {
				add_edge(i, j);
				add_edge(N + j, N + i);
			}
			if (min(T[j], T[i]) > max(T[j] - D[j], T[i] - D[i])) {
				add_edge(N + i, j);
				add_edge(N + j, i);
			}
			if (min(S[j] + D[j], T[i]) > max(S[j], T[i] - D[i])) {
				add_edge(N + i, N + j);
				add_edge(j, i);
			}
		}
	scc();
	for (int i = 0; i < N; i++)
		if (cmp[i] == cmp[i + N]) {
			cout << "NO" << endl;
			return;
		}
	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		if (cmp[i] > cmp[N + i]) {
			// x_i为真，即在结婚仪式开始时举行
			printf("%02d:%02d %02d:%02d\n", S[i] / 60, S[i] % 60, (S[i] + D[i]) / 60,
				(S[i] + D[i]) % 60);
		}
		else {
			// x_i为假，即在结婚仪式结束时举行
			printf("%02d:%02d %02d:%02d\n", (T[i] - D[i]) / 60, (T[i] - D[i]) % 60,
				T[i] / 60, T[i] % 60);
		}
	}
}*/
//LCA//最近公共祖先
//基于二分搜索的算法
// 输入
/*const int MAX_V = 1000;
vector<int> G[MAX_V]; // 图的邻接表表示
int root; // 根节点的编号
int parent[MAX_V]; // 父亲节点（根节点的父亲记为-1）
int depth[MAX_V]; // 节点的深度
void dfs(int v, int p, int d)
{
	parent[v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
}
void init()//预处理
{
	dfs(root, -1, 0);
}
int lca(int u, int v)
{
	while (depth[u] > depth[v])
		u = parent[u];
	while (depth[v] > depth[u])
		v = parent[v];
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}*/
/*int V;
const int MAX_V = 1000;
const int MAX_LOG_V = 32;
vector<int> G[MAX_V]; // 图的邻接表表示
int root; // 根节点的编号
int parent[MAX_LOG_V][MAX_V]; // 父亲节点（根节点的父亲记为-1）
int depth[MAX_V]; // 节点的深度
void dfs(int v, int p, int d)
{
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
}
void init()//预处理
{
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < MAX_LOG_V; k++) {
		for (int v = 0; v < V; v++) {
			if (parent[k][v] < 0)
				parent[k + 1][v] = -1;
			else
				parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}
int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = 0; k < MAX_LOG_V; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v)
		return u;
	//利用二分搜索计算LCA
	for (int k = MAX_LOG_V; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}*/
//基于RMQ的算法
/*const int MAX_V = 1000;
vector<int> G[MAX_V]; // 图的邻接表表示
int root;
int vs[MAX_V * 2 - 1]; // DFS访问的顺序
int depth[MAX_V * 2 - 1]; // 节点的深度
int id[MAX_V]; // 各个顶点在vs中首次出现的下标
void dfs(int v, int p, int d, int &k)
{
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p) {
			dfs(G[v][i], v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
		}
}
void init(int V)
{
	// 预处理出vs、depth和id
	int k = 0;
	dfs(root, -1, 0, k);
	// 预处理出RMQ（返回的不是最小值，而是最小值对应的下标）
	//rmq_init(depth, V * 2 - 1);
}
int lca(int u,int v)
{
	return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}*/
/*Housewife Wind//结合之前的线段树和树状数组
const int MAX_V = 1000000;
const int MAX_Q = 1000000;
struct edge { int id, to, cost; };
int n, q, s;
int a[MAX_V - 1], b[MAX_V - 1], w[MAX_V - 1];
int type[MAX_Q];//0:A 1:B
int x[MAX_Q], t[MAX_Q];

vector<edge> G[MAX_V];//图的邻接表表示
int root;

int vs[MAX_V * 2 - 1];//DFS访问的顺序
int depth[MAX_V * 2 - 1];//节点的深度
int id[MAX_V];//各个顶点在vs中首次出现的下标
int es[(MAX_V - 1) * 2];//边的下标(i*2+(叶子方向:0,根方向:1))

void dfs(int v,int p,int d,int &k)
{
	id[v] = k;
	vs[k] = v;
	depth[k++] = v;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (e.to != p) {
			add(k, e.cost);
			es[e.id * 2] = k;
			dfs(e.to, v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
			add(k, -e.cost);
			es[e.id * 2 + 1] = k;
		}
	}
}
//预处理
void init(int V)
{
	//初始化BIT
	bit_n = (V - 1) * 2;
	//预处理出vs,depth,id和es
	int k = 0;
	dfs(root, -1, 0, k);
	//预处理出RMQ
	rmq_init(depth, V * 2 - 1);
}
int lca(int u, int v)
{
	return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}
void solve()
{
	//预处理
	root = n / 2;//不论以哪个节点为根都没有问题
	for (int i = 0; i < n - 1; i++) {
		G[a[i] - 1].push_back((edge){ i, b[i] - 1, w[i] });
		G[b[i] - 1].push_back((edge){ i, a[i] - 1, w[i] });
	}
	init(n);
	//处理查询
	int v = s - 1;//当前位置
	for (int i = 0; i < q; i++) {
		if (type[i] == 0) {
			int u = x[i] - 1;
			int p = lca(u, v);
			//利用BIT计算p到v和p到u的费用之和，即区间(id[p], id[v]]和(id[p], id[u]]的权重和
			cout << sum(id[u]) - sum(id[p]) + sum(id[v]) - sum(id[p]) << endl;
			v = u;
		}
		else {
			//将通过道路x[i]的权重改为t[i]
			int k = x[i] - 1;
			add(es[k * 2], t[i] - w[k]);
			add(es[k * 2 + 1], w[k] - t[i]);
			w[k] = t[i];
		}
	}
}*/
//常用技巧精选
/*栈的运用
int n = 7;
int h[7] = { 2,1,4,5,1,3,3 };
int L[7], R[7];
int stack[7];
void solve()
{
	int top = 0;
	for (int i = 0; i < n; i++) {
		while (top > 0 && h[stack[top - 1]] >= h[i])
			--top;
		L[i] = (top == 0 ? 0 : stack[top - 1] + 1);
		stack[top++] = i;
	}
	top = 0;
	for (int i = n-1; i >= 0; i--) {
		while (top > 0 && h[stack[top - 1]] >= h[i])
			--top;
		R[i] = (top == 0 ? n - 1 : stack[top - 1]);
		stack[top++] = i;
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (h[i] * (R[i] - L[i]) > max)
			max = h[i] * (R[i] - L[i]);
	}
	cout << max << endl;
}*/
/*双端队列的运用
int n = 5, k = 3;
int a[5] = { 1,3,5,4,2 };
int b[3];
int st[5];
void solve()
{
	int s = 0, t = 0;
	for (int i = 0; i < n; i++) {
		while (s < t && a[st[t - 1]] >= a[i])
			t--;
		st[t++] = i;
		if (i - k + 1 >= 0) {
			b[i - k + 1] = a[st[s]];
			if (st[s] == i - k + 1)
				s++;
		}
	}
	for (int i = 0; i < n - k + 1; i++)
		cout << b[i] << " ";
}*/
//多重背包问题
/*const int n = 3, W = 12;
int w[3] = { 3,2,4 }, v[3] = { 2,4,3 }, m[3] = { 5,1,3 };

int dp[13];//DP循环数组(循环使用)
int dep[13];//双端队列(保存数组下标)
int depv[13];//双端队列(保存值)

void solve()//O(nW)
{
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < w[i]; a++) {
			int s = 0, t = 0;//双端队列的头部和尾部
			for (int j = 0; a + j * w[i] <= W; j++) {
				//向双端队列的尾部加入j
				int val = dp[a + j * w[i]] - j * v[i];
				while (s < t && depv[t - 1] <= val)
					t--;
				dep[t] = j;
				depv[t++] = val;
				dp[a + j * w[i]] = depv[s] + j * v[i];
				if (dep[s] == j - m[i])
					s++;
			}
		}
	}
	cout << dp[W] << endl;
}*/
//完全背包问题
/*void solve()//O(nlogW)
{
	int dp[W + 1] = { 0 };
	for (int i = 0; i < n; i++) {
		int num = m[i];
		for (int k = 1; num > 0; k <<= 1) {
			int mul = min(k, num);
			for (int j = W; j >= w[i] * mul; j--)
				dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
			num -= mul;
		}
	}
	cout << dp[W];
}*/
/*int n = 7;
int k = 3;
int a[7] = { 2,2,3,4,4,5,5 };

ll dp[8];//DP数组
ll S[8];//a的和
ll dep[7];//双端队列

//直线f_j在i位置的值
ll f(ll j, ll i)
{
	return dp[j] - (i - j) * a[j] - S[j];
}
//判断f2是否有可能成为最小值
bool check(ll f1, ll f2, ll f3)
{
	ll a1 = a[f1], b1 = dp[f1] - S[f1] + a[f1] * f1;
	ll a2 = a[f2], b2 = dp[f2] - S[f2] + a[f2] * f2;
	ll a3 = a[f3], b3 = dp[f3] - S[f3] + a[f3] * f3;
	return (a2 - a1) * (b3 - b2) <= (b2 - b1) * (a3 - a2);
}
void solve()
{
	//和的计算
	for (int i = 0; i < n; i++)
		S[i + 1] = S[i] + a[i];
	//双端队列的优化
	int s = 0, t = 1;
	dep[0] = 0;
	dp[0] = 0;
	for (int i = k; i <= n; i++) {
		if (i - k >= k) {
			//从末尾删除不再可能成为最小值的直线
			while (s + 1 < t && check(dep[t - 2], dep[t - 1], i - k))
				t--;
			//往双端队列中加入i-k
			dep[t++] = i - k;
		}
		//若头部的值不是最小值了则删去
		while (s + 1 < t && f(dep[s], i) >= f(dep[s + 1], i))
			s++;
		dp[i] = S[i] + f(dep[s], i);
	}
	cout << dp[n] << endl;
}*/
//倍增法
/*int N = 3, M = 10;
int s[6] = { 0,2,6 }, t[6] = { 5,7,9 };
pair<int, int> ps[6];//为了按照结束时间排序而使用的数对的数组
void solve()
{
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (t[i] < s[i])
			t[i] += M;
		s[N + i] = s[i] + M;
		t[N + i] = t[i] + M;
	}
	for (int i = 0; i < N * 2; i++)
		ps[i] = make_pair(t[i], s[i]);
	sort(ps, ps + 2 * N);
	//确定一个最开始选择的区间
	for (int i = 0; i < N; i++) {//因为是圆周，因此从哪里开始都可以
		//剩下的部分使用贪心法求解
		int tmp = 0, last = 0;
		for (int j = i; ps[j].first <= ps[i].second + M; j++) {
			if (last <= ps[j].second) {
				tmp++;
				last = ps[j].first;
			}
		}
		res = max(res, tmp);
	}
	cout << res << endl;
}*/
/*int N = 3, M = 10;
int s[6] = { 0,2,6 }, t[6] = { 5,7,9 };
pair<int, int> ps[12];
int neext[6];//用来存放每个区间的下一个区间的数组
void solve()
{
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (t[i] < s[i])
			t[i] += M;
		s[N + i] = s[i] + M;
		t[N + i] = t[i] + M;
	}
	for (int i = 0; i < N * 2; i++) {
		ps[i] = make_pair(t[i], i);
		ps[2 * N + i] = make_pair(s[i], 2 * N + i);
	}
	sort(ps, ps + 4 * N);
	//计算next
	int last = -1;
	for (int i = 4 * N - 1; i >= 0; i--) {
		int id = ps[i].second;
		if (id < 2 * N)
			neext[id] = last;
		else {
			id -= 2 * N;
			if (last < 0 || t[last] > t[id])
				last = id;
		}
	}
	//确定一个开始选择区间
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = i; t[j] < t[i] + M; j = neext[j])
			tmp++;
		res = max(res, tmp);
	}
	cout << res << endl;
}*/
/*int MAX_LOG_N = 10;
int N = 3, M = 10;
int s[6] = { 0,2,6 }, t[6] = { 5,7,9 };
pair<int, int> ps[12];
int neext[10][6];//用来存放每个区间的下一个区间的数组
void solve()
{
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (t[i] < s[i])
			t[i] += M;
		s[N + i] = s[i] + M;
		t[N + i] = t[i] + M;
	}
	for (int i = 0; i < N * 2; i++) {
		ps[i] = make_pair(t[i], i);
		ps[2 * N + i] = make_pair(s[i], 2 * N + i);
	}
	sort(ps, ps + 4 * N);
	//计算next[0]
	int last = -1;
	for (int i = 4 * N - 1; i >= 0; i--) {
		int id = ps[i].second;
		if (id < 2 * N)
			neext[0][id] = last;
		else {
			id -= 2 * N;
			if (last < 0 || t[last] > t[id])
				last = id;
		}
	}
	for (int k = 0; k + 1 < MAX_LOG_N; k++) {
		for (int i = 0; i < N * 2; i++) {
			if (neext[k][i] < 0)
				neext[k + 1][i] = -1;
			else
				neext[k + 1][i] = neext[k][neext[k][i]];
		}
	}
	for (int i = 0; i < N; i++) {
		//进行二分搜索
		int tmp = 0, j = i;
		for (int k = MAX_LOG_N - 1; k >= 0; k--) {
			int j2 = neext[k][j];
			if (j2 >= 0 && t[j2] <= s[i] + M) {
				j = j2;
				tmp |= 1 << k;
			}
		}
		res = max(res, tmp + 1);
	}
	cout << res << endl;
}*/
//智慧搜索
//剪枝
//调整搜索的顺序//数独//从分支少的部分开始搜索//从影响大的部分开始搜索
//没有更优则剪枝
/*已经找到的最优解
//////////////////////////////////////
//int min_res;
//////////////////////////////////////
int M, S;
//m[i][j]==true 火柴棒i属于正方形j
bool m[MAX_MATCH][MAX_SQUARE];
//mmax[i] = 正方形i中火柴棒的最大编号
int mmax[MAX_SQUARE];
//考虑p以后的火柴时解的下界
int hstar(int p, vector<bool> state)
{
	vector<pair<int, int>> ps;
	for (int i = 0; i < S; i++)
		if (state[i]) {
			//统计剩余正方形所包含的火柴棒数
			int num = 0;
			for (int j = p; j < M; j++)
				if (m[j][i])
					num++;
			ps.push_back(make_pair(num, i));
		}
	//按火柴棒数从小到大排序
	sort(ps.begin(), ps.end());
	int res = 0;
	//used[i]==true X中已经有包含火柴棒i的正方形了
	vector<bool> used(M, false);
	for (int i = 0; i < ps.size(); i++) {
		int id = ps[i].second;
		bool ok = true;
		//是否将正方形id加入到X中
		for (int j = p; j < M; j++)
			if (used[j] && m[j][id])
				ok = false;
		if (ok) {
			res++;
			for (int j = p; j < M; j++)
				if (m[j][id])
					used[j] = true;
		}
	}
	return res;
}
//p是当前考察的火柴棒的编号,num是至今已经移除的火柴棒的根数
//state[i]==true 正方形i尚未被破坏
int dfs(int p, int num, vector<bool> state)
{
	//如果检查完了所有的火柴棒,也就破坏了所有的正方形
	if (p == M)
		return min_res = num;

	//////////////////////////////////////
	//如果比已知的最优解要差，则不继续搜索
	if (num + hstar(p, state) >= min_res)
		return INF;
	//////////////////////////////////////

	//如果一定要移除火柴棒p,则use==true
	//如果一定不要移除火柴棒p,则nouse==true
	bool use = false, nouse = true;
	for (int i = 0; i < S; i++) {
		//只剩火柴棒p能破坏正方形i了,所以必须移除
		if (state[i] && mmax[i] == p)
			use = true;
		//火柴棒会破坏正方形i,所以可以移除
		if (state[i] && m[p][i])
			nouse = false;
	}
	int res = INF;
	//不移除火柴棒p的分支
	if (!use)
		res = min(res, dfs(p + 1, num, state));
	//移除火柴棒p的分支
	for (int i = 0; i < S; i++) {
		if (state[i] && m[p][i])
			state[i] = false;
	}
	if (!nouse)
		res = min(res, dfs(p + 1, num + 1, state));
	return res;
}
void solve()
{
	vector<bool> state(S, true);
	cout << dfs(0, 0, state);

	将程序改成判断是否有不超过某个x的解
	//////////////////////////////////////
	min_res = 0;
	while (dfs(0, 0, state) == INF)
		min_res++;
	cout << min_res << endl;
	//////////////////////////////////////
}*/
//IDA*//通过估算下界提前剪枝优化后的算法则称为IDA*
//A*和IDA*分别是针对宽度优先搜索和深度优先搜索的优化算法
//深度优先搜索和宽度优先搜索和Dijkstra算法都可以利用下界优化
//分治法：划分、解决、合并
//数列上的分治法//逆序对
/*归并排序以及逆序对统计
vector<int> A = { 5,1,4,2,1,3 };//输入
ll merge_count(vector<int> &a)
{
	int n = a.size();
	if (n <= 1)
		return 0;
	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());
	ll cnt = 0;
	cnt += merge_count(b);
	cnt += merge_count(c);
	//此时b,c已经分别拍好序了
	ll ai = 0, bi = 0, ci = 0;
	//分治法
	while (ai < n) {
		if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci]))
			a[ai++] = b[bi++];
		else {
			cnt += n / 2 - bi;
			a[ai++] = c[ci++];
		}
	}
	return cnt;
}
void solve()
{
	cout << merge_count(A) << endl;
}*/
/*树上的分治法//重心分解
struct edge { int to, length; };
int N = 5, K = 4;
vector<edge> G[5] = { {edge{1,3},edge{2,1},edge{3,2}},
					  {edge{0,3}},
					  {edge{0,1},edge{4,1}},
					  {edge{0,2}},
					  {edge{2,1}} };
bool centroid[5];//顶点是否已经作为重心删除的标记
int subtree_size[5];//以该顶点为根的子树的大小(查找重心时使用)
int ans;//答案
//计算子树的大小的递归函数
int compute_subtree_size(int v, int p)
{
	int c = 1;
	for (unsigned int i = 0; i < G[v].size(); i++) {
		int w = G[v][i].to;
		if (w == p || centroid[w])//除去父节点
			continue;
		c += compute_subtree_size(G[v][i].to, v);
	}
	return subtree_size[v] = c;
}
//查找重心的递归函数。t是整个连通分量的大小
//在以v为根的子树中寻找一个顶点,使得删除该顶点后得到的最大子树的顶点数最少
//返回值为 pair(最大子树的顶点数,重心顶点编号)
pair<int, int> search_centroid(int v, int p, int t)
{
	pair<int, int> res = make_pair(INF, -1);
	int s = 1, m = 0;
	for (unsigned int i = 0; i < G[v].size(); i++) {
		int w = G[v][i].to;
		if (w == p || centroid[w])
			continue;
		res = min(res, search_centroid(w, v, t));
		m = max(m, subtree_size[w]);
		s += m;
	}
	m = max(m, t - s);
	res = min(res, make_pair(m, v));
	return res;
}
//计算子树中的所有顶点到重心的距离的递归函数
void enumerate_paths(int v, int p, int d, vector<int> &ds)
{
	ds.push_back(d);
	for (unsigned int i = 0; i < G[v].size(); i++) {
		int w = G[v][i].to;
		if (w == p || centroid[w])
			continue;
		enumerate_paths(w, v, d + G[v][i].length, ds);
	}
}

//////////////////////////////////////////////////////////////
//统计不超过K的顶点的对数
int count_pairs(vector<int> &ds)
{
	int res = 0;
	sort(ds.begin(), ds.end());
	int j = ds.size();
	for (unsigned int i = 0; i < ds.size(); i++) {
		while (j > i && ds[i] + ds[j - 1] > K)
			--j;
		res += j - i - 1;
	}
	return res;
}
//////////////////////////////////////////////////////////////

//对顶点v所在的子树,查找中心并分割求解的递归函数
void solve_subproblem(int v)
{
	//查找重心s
	compute_subtree_size(v, -1);
	int s = search_centroid(v, -1, subtree_size[v]).second;
	centroid[s] = true;

	//(1)统计按顶点s分割后的子树中的对数
	for (unsigned int i = 0; i < G[s].size(); i++) {
		if (centroid[G[s][i].to])
			continue;
		solve_subproblem(G[s][i].to);
	}
	//(2)(3)统计经过s的对数
	vector<int> ds;
	ds.push_back(0);//包含顶点s的部分
	for (unsigned int i = 0; i < G[s].size(); i++) {
		if (centroid[G[s][i].to])
			continue;

		vector<int> tds;
		enumerate_paths(G[s][i].to, s, G[s][i].length, tds);
		ans -= count_pairs(tds);//先把会重复统计的部分减掉
		ds.insert(ds.end(), tds.begin(), tds.end());
	}
	ans += count_pairs(ds);
	centroid[s] = false;
}
void solve()
{
	ans = 0;
	solve_subproblem(0);
	cout << ans << endl;
}*/
/*平面上的分治法//最近点对问题
bool compare_y(P a, P b)
{
	return a.second < b.second;
}
typedef pair<double, double> P;//first保存x坐标,second保存y坐标
int N = 5;
P A[5] = { make_pair(0, 2), make_pair(6, 67), make_pair(43, 71), make_pair(39, 107), make_pair(189, 140) };
//传入的a已经按x坐标排好序了
double closest_pair(P *a, int n)
{
	if (n <= 1)
		return INF;
	int m = n / 2;
	double x = a[m].first;
	double d = min(closest_pair(a, m), closest_pair(a + m, n - m));
	inplace_merge(a, a + m, a + n, compare_y);

	vector<P> b;//将到直线的距离小于d的点加入
	for (int i = 0; i < n; i++) {
		if (fabs(a[i].first - x) >= d)
			continue;
		//从后往前检查b中y坐标相差小于d的点
		for (int j = 0; j < b.size(); j++) {
			double dx = a[i].first - b[b.size() - j - 1].first;
			double dy = a[i].second - b[b.size() - j - 1].second;
			if (dy >= d)
				break;
			d = min(d, sqrt(dx * dx + dy * dy));
		}
		b.push_back(a[i]);
	}
	return d;
}
void solve()
{
	sort(A, A + N);//按x坐标排序
	cout << closest_pair(A, N);
}*/
//华丽地处理字符串//字符串上的动态规划算法//单字符串的情况
/*禁止字符串//动态规划的是剩余字符的个数和最后的k-1个字符
const int MAX_K = 100;
const int MAX_N = 10000;
const char *AGCT = "AGCT";
const int MOD = 10009;
//输入// K:状态数
int N = 3;
int K = 2;
string S = "AT";

int neext[MAX_K][4];
int dp[MAX_N + 1][MAX_K];

void solve()
{
	//预处理//O(k^3)//从某个状态添加某个字符后的状态转移表
	//next[i][j]是当前状态为i,添加了字符j以后的状态值
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) {
			//在S长度为i的前缀后添加一个字符
			string s = S.substr(0, i) + AGCT[j];
			//反复删除第一个字符,直到成为S的前缀
			while (S.substr(0, s.length()) != s)
				s = s.substr(1);
			neext[i][j] = s.length();
		}
	}
	//O(kn)//动态规划边界的初值
	dp[0][0] = 1;
	for (int i = 1; i < K; i++)
		dp[0][i] = 0;
	//动态规划
	for (int t = 0; t < N; t++) {
		for (int i = 0; i < K; i++)
			dp[t + 1][i] = 0;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 4; j++) {
				int ti = neext[i][j];
				if (ti == K)//不允许出现S
					continue;
				dp[t + 1][ti] += dp[t][i];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < K; i++)
		ans += dp[N][i];
	cout << ans << endl;
}*/
//以字符串的前缀为状态的动态规划，被称为Trie上的动态规划
/*多字符串的情况//DNA repair
const char *AGCT = "AGCT";
//输入
int N = 2;
string S = "TGAATG";
string P[2] = { "A","TG" };
//预处理得到的数据
int neext[4][4];//添加某个字符后转移到的状态
bool ng[4];    //是否是禁止转移到的状态

int dp[7][4];
void solve()
{
	//首先枚举出所有的字符串前缀
	vector<string> pfx;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= P[i].length(); j++)
			pfx.push_back(P[i].substr(0, j));
	//排序去重
	sort(pfx.begin(), pfx.end());
	pfx.erase(unique(pfx.begin(), pfx.end()), pfx.end());
	int K = pfx.size();
	//计算各个状态的相关信息
	for (int i = 0; i < K; i++) {
		//如果后缀和禁止模式匹配的话，就是禁止转移到的状态
		ng[i] = false;
		for (int j = 0; j < N; j++)
			ng[i] |= (P[j].length() <= pfx[i].length()) && (pfx[i].substr(pfx[i].length() - P[j].length(),P[j].length()) == P[j]);
		for (int j = 0; j < 4; j++) {
			//添加一个字符后得到的字符串
			string s = pfx[i] + AGCT[j];
			//反复删除第一个字符，知道等于某个状态的字符串，该状态就是转移到的状态
			int k;
			for (;;) {
				k = lower_bound(pfx.begin(), pfx.end(), s) - pfx.begin();
				if (k < K && pfx[k] == s)
					break;
				s = s.substr(1);
			}
			neext[i][j] = k;
		}
	}
	//动态规划的边界初值
	dp[0][0] = 1;
	for (int i = 1; i < K; i++)
		dp[0][i] = 0;
	//动态规划
	//这里dp[i][j]表示长度为i的S的前i个字符组成的子串走到长度为i的状态j需要改变的最少次数
	for (int t = 0; t < S.length(); t++) {
		for (int i = 0; i < K; i++)
			dp[t + 1][i] = INF;
		for (int i = 0; i < K; i++) {
			if (ng[i])
				continue;
			for (int j = 0; j < 4; j++) {
				int k = neext[i][j];
				dp[t + 1][k] = min(dp[t + 1][k], dp[t][i] + (int)(S[t] != AGCT[j]));
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < K; i++) {
		if (ng[i])
			continue;
		ans = min(ans, dp[S.length()][i]);
	}
	if (ans == INF)
		puts("-1");
	else
		cout << ans << endl;
}*/
//字符串匹配
/*利用滚动哈希的字符串比较算法
typedef unsigned long long ull;
const ull B = 100000007;//哈希的基数
//a是否在b中出现
bool contain(string a, string b)
{
	int al = a.length(), bl = b.length();
	if (al > bl)
		return false;
	//计算B的al次方
	ull t = 1;
	for (int i = 0; i < al; i++)
		t *= B;
	//计算a和b长度为al的前缀对应的哈希值
	ull ah = 0, bh = 0;
	for (int i = 0; i < al; i++)
		ah = ah * B + a[i];
	for (int i = 0; i < al; i++)
		bh = bh * B + b[i];
	//对b不断右移一位，更新哈希值并判断
	for (int i = 0; i + al <= bl; i++) {
		if (ah == bh)
			return true;//b从位置i开始长度为al的字符串子串等于a
		if (i + al < bl)
			bh = bh * B + b[i + al] - b[i] * t;
	}
	return false;
}*/
/*星座
typedef unsigned long long ull;
//输入
int N = 3, M = 3, T = 2, P = 2, Q = 2;//N*M P*Q
char filed[3][3] = {'*','0','0',
					'0','*','*',
					'*','0','0'};//匹配对象
char patterns[2][3][3] = { {'*','*',',',  '0','0',',',  ',',',',','},
						  {'*','0',',',  '*','*',',',  ',',',',','} };//匹配模式
ull haash[3][3], tmp[3][3];
//计算a的所有PxQ子阵对应的哈希值
void compute_hash(char a[3][3], int n, int m)
{
	const ull B1 = 9973;
	const ull B2 = 100000007;

	ull t1 = 1;//B1的Q次方
	for (int j = 0; j < Q; j++)
		t1 *= B1;

	//按行方向计算哈希值
	for (int i = 0; i < n; i++) {
		ull e = 0;
		for (int j = 0; j < Q; j++)
			e = e * B1 + a[i][j];
		for (int j = 0; j + Q <= m; j++) {
			tmp[i][j] = e;
			if (j + Q < m)
				e = e * B1 - t1 * a[i][j] + a[i][j + Q];
		}
	}

	ull t2 = 1;//B2的P次方
	for (int i = 0; i < P; i++)
		t2 *= B2;

	//按列方向计算哈希值
	for (int j = 0; j + Q <= m; j++) {
		ull e = 0;
		for (int i = 0; i < P; i++)
			e = e * B2 + tmp[i][j];
		for (int i = 0; i + P <= n; i++) {
			haash[i][j] = e;
			if (i + P < n)
				e = e * B2 - t2 * tmp[i][j] + tmp[i + P][j];
		}
	}
}
void solve()
{
	multiset<ull> unseen;
	for (int k = 0; k < T; k++) {
		compute_hash(patterns[k], P, Q);
		unseen.insert(haash[0][0]);
	}
	compute_hash(filed, N, M);
	for (int i = 0; i + P <= N; i++)
		for (int j = 0; j + Q <= M; j++)
			unseen.erase(haash[i][j]);
	int ans = T - unseen.size();
	cout << ans << endl;
}*/
/*后缀数组
int n, k;
int raank[1001];
int tmp[1001];
//比较(rank[i],rank[i+k]),(rank[j],rank[j+k])
bool compare_sa(int i, int j)
{
	if (raank[i] != raank[j])
		return raank[i] < raank[j];
	else {
		int ri = i + k <= n ? raank[i + k] : -1;
		int rj = j + k <= n ? raank[j + k] : -1;
		return ri < rj;
	}
}
//计算字符串S的后缀
void construct_sa(string S, int *sa)
{
	n = S.length();
	//初始长度为1,rank直接取字符的编码
	for (int i = 0; i <= n; i++) {
		sa[i] = i;
		raank[i] = i < n ? S[i] : -1;
	}
	//利用对长度为k的排序的结果对长度为2k的排序
	for (k = 1; k <= n; k *= 2) {
		sort(sa, sa + n + 1, compare_sa);
		tmp[sa[0]] = 0;
		for (int i = 1; i <= n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= n; i++) {
			raank[i] = tmp[i];
		}
	}
}*/
/*基于后缀数组的字符串匹配
bool contain(string S, int *sa, string T)
{
	int a = 0, b = S.length();
	while (b - a > 1) {
		int c = (a + b) / 2;
		if (S.compare(sa[c], T.length, T) < 0)
			a = c;
		else
			b = c;
	}
	return S.compare(sa[b], T.length(), T) == 0;
}*/
/*后缀数组的应用
int N = 5;
int A[5] = { 10,1,2,3,4 };

int rev[10], sa[10];
void solve()
{
	//将A反转，并计算其后缀数组
	reverse_copy(A, A + N, rev);
	construct_sa(rev, sa, N);//计算整数序列后缀数组的函数

	//确定第一段的分割位置
	int p1;
	for (int i = 0; i < N; i++) {
		p1 = N - sa[i];
		if (p1 >= 1 && N - p1 >= 2)
			break;
	}

	//将p1之后的字符串反转并重复两次，再计算其后缀数组
	int m = N - p1;
	reverse_copy(A + p1, A + N, rev);
	reverse_copy(A + p1, A + N, rev + m);
	construct_sa(rev, sa, 2 * m);

	//确定后两段的分割位置
	int p2;
	for (int i = 0; i <= 2 * m; i++) {
		p2 = 2 * m - sa[i];
		if (p2 - m >= 1 && m - sa[i] >= 1) {
			break;
		}
	}
	p2 = p1 + p2 - m;
	reverse(A, A + p1);
	reverse(A + p1, A + p2);
	reverse(A + p2, A + N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
}*/
/*高度数组
//记后缀数组为sa,高度数组为lcp,则有后缀S[sa[i]...]与S[sa[i+1]...]的最长公共前缀的长度为lcp[i]
//记rank[i]为位置i开始的后缀在后缀数组中的顺序
//传入字符串S和对应的后缀数组sa,计算高度数组lcp
void construct_lcp(string S, int *sa, int *lcp)
{
	int n = S.length();
	for (int i = 0; i <= n; i++)
		raank[sa[i]] = i;

	int h = 0;
	lcp[0] = 0;
	for (int i = 0; i < n; i++) {
		int j = sa[raank[i] - 1];

		if (h > 0)
			h--;
		for (; j + h < n && i + h < n; h++) {
			if (S[j + h] != S[i + h])
				break;
		}
		lcp[raank[i] - 1] = h;
	}
}
//最长公共子串
//将两个字符串拼成一个字符串
string S = "ABRACADABRA", T = "ECADADABRBCRDAR";
int sa[1000], lcp[1000];
void solve()
{
	int s1 = S.length();
	S += '\0' + T;
	construct_sa(S, sa);
	construct_lcp(S, sa, lcp);
	int ans = 0;
	for (int i = 0; i < S.length(); i++) {
		if ((sa[i] < s1) != (sa[i + 1] < s1))
			ans = max(ans, lcp[i]);
	}
	cout << ans;
}*/
//最长回文子串
//给定字符串S，计算其中是回文的最长字符串子串的长度
/*输入
string S;
int sa[1001], lcp[1001], raank[1001];
void solve()
{
	int n = S.length();
	string T = S;
	reverse(T.begin(), T.end());
	S += '$' + T;
	construct_sa(S, sa);
	construct_lcp(S, sa, lcp);
	for (int i = 0; i <= S.length(); i++)
		raank[sa[i]] = i;
	construct_rmq(lcp, S.length() + 1);
	int ans = 0;
	//以第i个字符对称的奇数长回文
	for (int i = 0; i < n; i++) {
		int j = 2 * n - i;
		int l = query_rmq(min(raank[i], raank[j]), max(raank[i], raank[j]));
		ans = max(ans, 2 * l - 1);
	}
	//以第i-1和第i个字符对称的偶数长回文
	for (int i = 1; i < n; i++) {
		int j = 2 * n - i + 1;
		int l = query_rmq(min(raank[i], raank[j]), max(raank[i], raank[j]));
		ans = max(ans, 2 * l);
	}
	cout << ans << endl;
}
int main()
{
	solve();
	return 0;
}*/