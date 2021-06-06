//A+B for Matrices https://www.nowcoder.com/practice/e431b3ae9efa4726b45a659b71abe124
#include<iostream>
using namespace std;
struct Matrix
{
    int matrix[10][10];
    int row,col;
    Matrix(int r,int c):row(r),col(c){}
};
Matrix sum(Matrix x,Matrix y)
{
    Matrix answer(x.row,x.col);
    for(int i=0;i<answer.row;i++)
    {
        for(int j=0;j<answer.col;j++)
        {
            answer.matrix[i][j]=x.matrix[i][j]+y.matrix[i][j];
        }
    }
    return answer;
}
int judge(Matrix x)
{
    int num=0;
    for(int i=0;i<x.row;i++)//判断横行
    {
         int flag=1;
         for(int j=0;j<x.col;j++)
         {
             if(x.matrix[i][j]!=0)
             {
                 flag=0;
                 break;
             }
         }
         if(flag){
            num++;
         }
    }
    for(int j=0;j<x.col;j++)//判断列
    {
         int flag=1;
         for(int i=0;i<x.row;i++)
         {
             if(x.matrix[i][j]!=0)
             {
                 flag=0;
                 break;
             }
         }
         if(flag){
            num++;
         }
    }
    return num;
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m==0)
        {
            break;
        }
        Matrix x(m,n);
        Matrix y(m,n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x.matrix[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>y.matrix[i][j];
            }
        }
        Matrix answer=sum(x,y);
        cout<<judge(answer)<<endl;
    }
    return 0;
}
