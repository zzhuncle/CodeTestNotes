//Catch that cow http://poj.org/problem?id=3278
#include<queue>
#include<iostream>
using namespace std;
#define MAXN 100001
//�ҵ�������С�Ľ⣬����������н� ʹ��BFS�Ϻ�
typedef pair<int, int> P;
bool used[MAXN];//�ӿ��ٶ�
int bfs(int n, int k)
{
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, n));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        if (p.second < 0 || p.second >= MAXN || used[p.second])//ע�����Ʒ�Χ����ֹ����Խ��
            continue;
        used[p.second] = true;
        if (p.second == k)
            return p.first;
        que.push(P(p.first + 1, p.second - 1));
        que.push(P(p.first + 1, p.second + 1));
        que.push(P(p.first + 1, p.second * 2));
    }
}
int main()
{
    int n, k;//John��λ�� ţ��λ��
	cin >> n >> k; 
    cout << bfs(n, k) << endl;
    return 0;
}