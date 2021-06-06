//递推数列 https://www.nowcoder.com/practice/d0e751eac618463bb6ac447369e4aa25
//递推公式转化为快速矩阵幂
#include<bits/stdc++.h>
using namespace std;
const int mod = 10000;
struct Matrix
{
    int matrix[10][10];
    int row, col;
    Matrix(int r, int c): row(r), col(c) { }
};
Matrix Mul(Matrix x, Matrix y)
{
    Matrix ans(x.row, y.col);
    for (int i = 0;i < x.row;i++)
        for (int j = 0;j < y.col;j++) {
            ans.matrix[i][j] = 0;
            for (int k = 0;k < x.col;k++)
                ans.matrix[i][j] = (ans.matrix[i][j] + x.matrix[i][k] * y.matrix[k][j]) % mod;
        }
    return ans;
}
Matrix quickpow(Matrix x, int k)
{
    int n = x.row;
    Matrix ans(n, n);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) {
            if (i == j)
                ans.matrix[i][j] = 1;
            else
                ans.matrix[i][j] = 0;
        }
    while (k != 0) {
        if (k % 2)
            ans = Mul(ans, x);
        x = Mul(x, x);
        k /= 2;
    }
    return ans;
}
int main()
{
    int a0, a1, p, q, k;
    while (cin >> a0 >> a1 >> p >> q >> k) {
        Matrix a(2, 2);
        a.matrix[0][0] = p;
        a.matrix[0][1] = q;
        a.matrix[1][0] = 1;
        a.matrix[1][1] = 0;
        a = quickpow(a, k - 1);
        if (k == 0)
            cout << a0 << endl;
		else if (k == 1) 
            cout << a1 << endl;
        else
            cout << ((a.matrix[0][0] % mod) * (a1 % mod) % mod + (a.matrix[0][1] % mod) * (a0 % mod) % mod) % mod << endl;
    }
    return 0;
}