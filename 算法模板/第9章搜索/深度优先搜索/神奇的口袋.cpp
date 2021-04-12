//(����) ����Ŀڴ� https://www.nowcoder.com/practice/9aaea0b82623466a8b29a9f1a00b5d35
#include<bits/stdc++.h>
using namespace std;
#define MAXN 21
int N;
int V[MAXN];
int num = 0;
void dfs(int left, int index)
{
    if (left == 0) {
        num++;
        return;
    }
    if (index == 0)
        return;
    for (int i = min(1, left / V[index]);i >= 0;i--)
        dfs(left - i * V[index], index - 1);
    return;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 1;i <= N;i++)
        cin >> V[i];
    sort(V + 1, V + N + 1);
    dfs(40, N);
    cout << num << endl;
    return 0;
}
/*
��̬�滮����
dp[i][j]��ʾ����i����Ʒʱ���ճ����Ϊj�ķ�����
���ڵ�i����Ʒ��ֻ���úͲ�������ѡ���������ķ�����������+���õķ�������
dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i]]
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[21][41];  //dp[i][j]��ʾ����i����Ʒʱ���ճ����Ϊj�ķ�����
int v[21];  //���

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1; //��Ŀ�����Ϊ0ʱ��ֻ��1�ַ�������ȫ����
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=40; j++){
                if(j>=v[i]){//Ŀ��������ڵ�ǰ��Ʒ���
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i]];//����+�õķ�����
                }
                else{
                    dp[i][j] = dp[i-1][j];//ֻ��ѡ����
                }
                
            }
        }
        cout<<dp[n][40]<<endl;
    }
    return 0;
}
*/