//???? https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec
//????dp
/*
    ???????
    ?????????2???????2?????1?2?4?6?8...???????????????1?

    ???????N?
    1.N??????N??????????1???2?????1??????????????????
    ?? f(N)=f(N-1)
    ???
    5=?1+4?=?1+2+2?=?1+1+1+2?=?1+1+1+1+1? ;?????????
    4=?4? =?2+2? =?1+1+2? = (1+1+1+1) ;????????

    2.N???????????????
    2.1 N????1?N????1???N??????????f(N-1)
    ???
    4=?4?=?2+2?=?1+1+2?=?1+1+1+1?
    3=?1+2?=?1+1+1?
    2.2 N?????1
    ????1??????????????????????2???N???2m????2????m???????f(N)?
    ???
    4=?4?=?2+2? ????1

    ????2.1?2.2??????????????4????
    ????N????????f(N)=f(N-1)+f(N/2)
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2;i <= n;i++) {
        if (i % 2 == 0)
            dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
        else
            dp[i] = dp[i - 1] % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}
