#include<iostream>
#include<cstdio>
using namespace std;
#define MAXM 1000
#define MAXN 10000

int n, m;

int nextTable[MAXM];
char pattern[MAXM];
char text[MAXN];
void GetNextTable(int m)
{
    int i = 0;
    nextTable[i] = -1;
    int j = -1;
    while (i < m) {
        if (j == -1 || pattern[j] == pattern[i]) {
            i++;
            j++;
            nextTable[i] = j;
        } else {
            j = nextTable[j];
        }
    }
    return;
}
int KMP(int n, int m) {
    GetNextTable(m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = nextTable[j];
        }
    }
    if (j == m) {
        return i - j + 1;
    } else {
        return -1;
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n;i++) 
    {
        scanf("%d", &text[i]);
    }
    for (int j = 0;j < m;j++) 
    {
        scanf("%d", &pattern[j]);
    }
    printf("%d\n", KMP(n, m));
    return 0;
}