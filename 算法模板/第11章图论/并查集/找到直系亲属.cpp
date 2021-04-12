#include<bits/stdc++.h>
using namespace std;
//使用孩子数组，从孩子到父亲遍历，只有唯一路径，即倒过来遍历更加容易
int child[27];
void Init()
{
    for (int i = 0;i < 27;i++)
        child[i] = i;
}
//判断y是否是x的直系子节点
bool Find(int x, int y)
{
    while(x != y) {
        if (x == child[x])
            return false;
        x = child[x];
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    while (cin >> n >> m) {
        Init();
        string str;
        for (int i = 0;i < n;i++) {
            cin >> str;
            if (str[1] != '-')
                child[str[1] - 'A'] = str[0] - 'A'; 
            if (str[2] != '-')
                child[str[2] - 'A'] = str[0] - 'A';
        }
        for (int i = 0;i < m;i++) {
            cin >> str;
            int depth = 0;
            if (Find(str[0] - 'A', str[1] - 'A')) {
                int fath = str[0] - 'A', chil = str[1] - 'A';
                while (fath != chil) {
                    fath = child[fath];
                    depth++;
                }
                while (depth > 2) {
                    cout << "great-";
                    depth--;
                }
                cout << (depth == 1 ? "parent" : "grandparent") << endl;
            } else if (Find(str[1] - 'A', str[0] - 'A')) {
                int fath = str[1] - 'A', chil = str[0] - 'A';
                while (fath != chil) {
                    fath = child[fath];
                    depth++;
                }
                while (depth > 2) {
                    cout << "great-";
                    depth--;
                }
                cout << (depth == 1 ? "child" : "grandchild") << endl;
            } else 
                cout << '-' << endl;
        }
    }
    return 0;
}