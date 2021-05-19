//Case of Fugitive https://codeforces.com/group/xrTA2IaQje/contest/250162/problem/C
//使用cin cout超时
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 200001;
typedef long long ll;
//贪心算法
//对于每个区间，设立最大长度max和最小值min，并对区间按照最小值minimum进行排序，
//    再对桥的长度length进行排序
//之后，按照桥从小到大的方式来选择搭建的区间，在所有minimum<=length<=maxmum的区间
//    中，选择maxmum最小的那个作为该桥搭建的区间即可
struct Island {
    ll left; //岛屿左端点
    ll right;//岛屿右端点
};
struct Bridge {
    ll length;//桥的长度
    ll index; //桥的编号
};
struct Interval {
    ll minimum;//区间最小值
    ll maxmum; //区间最大值
    ll index;  //区间编号
    bool operator<(Interval x) const {//优先队列使用
        return maxmum > x.maxmum;
    }
};
Island island[MAX];
Bridge bridge[MAX];
Interval interval[MAX];
ll answer[MAX];
bool IntervalCmp(Interval x, Interval y)
{
    if (x.minimum == y.minimum)
        return x.maxmum < y.maxmum;
    else
        return x.minimum < y.minimum;
}
bool BridgeCmp(Bridge x, Bridge y)
{
    return x.length < y.length;
}
bool solve(int n, int m)
{
    priority_queue<Interval> que;
    int position = 0;//当前区间下标
    int number = 0;  //搭建桥的数目
    for (int i = 0; i < m; i++) {
        while (!que.empty() && que.top().maxmum < bridge[i].length)
            que.pop();//当前区间无法搭建
        while (position < n - 1 && interval[position].minimum <= bridge[i].length && interval[position].maxmum >= bridge[i].length) {
            que.push(interval[position]);
            position++;
        }
        if (!que.empty()) {
            Interval cur = que.top();
            que.pop();
            answer[cur.index] = bridge[i].index;
            number++;
        }
    }
    return number == n - 1;
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(island, 0, sizeof(island));
        memset(bridge, 0, sizeof(bridge));
        memset(interval, 0, sizeof(interval));
        memset(answer, 0, sizeof(answer));
        for (int i = 0; i < n; i++)
            scanf("%lld%lld", &island[i].left, &island[i].right);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &bridge[i].length);
            bridge[i].index = i + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            interval[i].minimum = island[i + 1].left - island[i].right;
            interval[i].maxmum = island[i + 1].right - island[i].left;
            interval[i].index = i;
        }
        sort(interval, interval + n - 1, IntervalCmp);
        sort(bridge, bridge + m, BridgeCmp);
        if (solve(n, m)) {
            printf("Yes\n");
            for (int i = 0; i < n - 1; i++)
                printf("%lld\n", answer[i]);
        }
        else
            printf("No\n");
    }
    return 0;
}
