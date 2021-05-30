//最大子矩阵 https://www.nowcoder.com/practice/a5a0b05f0505406ca837a3a76a5419b3
/*  本题是一道求最大子矩阵的典型例题。不过当i!=j时，不必将原始矩阵中的第i行到第j行中的所有元素次累加起来得到一维
数组，而事先用一个辅助二维数组记录原始矩阵从上到下加起来的累加矩阵，于是求第i行到第j行的一维数组只需将辅助矩阵
进行一次减法便可以得到，而不需要逐行进行多次累加。
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int matrix[MAXN][MAXN];//原始矩阵
int total[MAXN][MAXN]; //辅助矩阵
int arr[MAXN];         //一维矩阵
int dp[MAXN];

int MaxSubsequence(int n)
{
    int maxi = INT_MIN;
    for (int i = 0;i < n;i++) {
        if (i == 0)
            dp[i] = arr[i];
        else
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int MaxSubmatrix(int n)
{
    int maxi = INT_MIN;
    for (int i = 0;i < n;i++)
        for (int j = i;j < n;j++) {
            for (int k = 0;k < n;k++) {
                if (i == 0)
                    arr[k] = total[j][k];
                else
                    arr[k] = total[j][k] - total[i - 1][k];
            }
            maxi = max(maxi, MaxSubsequence(n));
        }
    return maxi;
}
int main()
{
    int n;
    cin >> n;//矩阵的维度
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> matrix[i][j];
    //初始化辅助矩阵
    for (int j = 0;j < n;j++)
        for (int i = 0;i < n;i++) {
            if (i == 0)
                total[i][j] = matrix[i][j];
            else
                total[i][j] = matrix[i][j] + total[i - 1][j];
        }
    int ans = MaxSubmatrix(n);
    cout << ans << endl;
    return 0;
}
