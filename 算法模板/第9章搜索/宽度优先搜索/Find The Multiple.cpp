//Find The Multiple http://poj.org/problem?id=1426
//long long 范围 > 10^18
//int 范围 > 10^9
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
void bfs(int n) 
{
    queue<ll> que;
    que.push(1);
    while (1) {
        ll l = que.front(); que.pop();
        if (l % n == 0) {
            cout << l << endl;
            return;
        }
        que.push(l * 10);
        que.push(l * 10 + 1);
    }
}
int main()
{
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        bfs(n);  
    }
    return 0;
}