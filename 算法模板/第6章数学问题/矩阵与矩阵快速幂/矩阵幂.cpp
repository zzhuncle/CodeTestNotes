//矩阵幂 https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a
#include<bits/stdc++.h>
using namespace std;
struct Matrix
{
    int matrix[10][10];
    int row, col;
    Matrix(int r, int c): row(r), col(c) { }
};
Matrix Multiply(Matrix x, Matrix y)//矩阵乘法
{
    Matrix answer(x.row, y.col);
    for (int i = 0;i < answer.row;i++)
        for (int j = 0;j < answer.col;j++) {
            answer.matrix[i][j] = 0;
            for (int k = 0;k < x.col;k++) 
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
        }
    return answer;
}
void PrintMatrix(Matrix x)//打印矩阵
{
    for (int i = 0;i < x.row;i++) {
        for (int j = 0;j < x.col;j++) {
            if (j != 0)
                cout << " ";
            cout << x.matrix[i][j];
        }
        cout << endl;
    }
}
Matrix fastpow(Matrix x, int k)
{
    Matrix ans(x.row, x.col);
    for (int i = 0;i < x.row;i++)
        for (int j = 0;j < x.col;j++) {
            if (i == j)
                ans.matrix[i][j] = 1;
            else 
                ans.matrix[i][j] = 0;
        }
    while (k != 0) {
        if (k % 2)
            ans = Multiply(ans, x);
        x = Multiply(x, x);
        k /= 2;
    }
    return ans;
}
int main()
{
    int n, k;
    while (cin >> n >> k) {
        Matrix x(n, n);
        for (int i = 0;i < x.row;i++)
            for (int j = 0;j < x.col;j++)
                cin >> x.matrix[i][j];
        Matrix ans = fastpow(x, k);
        PrintMatrix(ans);
    }
    return 0;
}