// Senior's Gun http://acm.hdu.edu.cn/showproblem.php?pid=5281
/** 证明:
     如果n<m 把B中最小的n个拿出来就好。 如果n>m把A中最大的m个拿出来就好。 所以只考虑n=m的情况。
  考虑A中的两个元素P,Q,P<=Q. B中的两个元素S,T，S<=T.   
  如果Q<S，那么不能匹配任意一个.  
  如果P>=T，那么可以随便怎么匹配,得分为P+Q-S-T。 可以认为是PT,QS匹配。
  除去上面的两种情况,也就是Q>=S,P<T的时候。这时候一定是QS匹配最优。我们可以从赚差值的角度理解。
  假设如果A[i]-A[j]<0也可以匹配,但实际得分却是0,这样我们就赚了
  这个负的值。所以要想尽可能多赚这个负的值,要让A中小的P和B中大的T匹配。
*/
//注意ll
//注意cin.tie(0) 否则超时
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
typedef long long ll;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int T;
    cin >> T;//测试样例个数
    vector<ll> a(MAXN);
    vector<ll> b(MAXN);
    int n, m;
    ll ans = 0;
    for (int i = 0;i < T;i++) {
        ans = 0;
        cin >> n >> m;
        for (int j = 0;j < n;j++)
            cin >> a[j];
        for (int j = 0;j < m;j++)
            cin >> b[j];
        sort(&a[0], &a[n], cmp);
        sort(&b[0], &b[m]);
        for (int j = 0;j < min(n, m);j++) {
            if (a[j] < b[j])
                break;
            ans += a[j] - b[j];
        }
        cout << ans << endl;
    }
    return 0;
}