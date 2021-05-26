//(浙大) 二叉搜索树 https://www.nowcoder.com/practice/3d6dd9a58d5246f29f71683346bb8f1b
#include<bits/stdc++.h>
using namespace std;
class T
{
public:
    T* left;
    T* right;
    int val;
    T(int v)
    {
        left = right = NULL;
        val = v;
    }
};
void insert(T* root, int t)
{
    if (t < root->val) {
        if (root->left == NULL) {
            root->left = new T(t);
            return;
        }
        insert(root->left, t);
    }
    else {
        if (root->right == NULL) {
            root->right = new T(t);
            return;
        }
        insert(root->right, t);
    }
}
void delet(T* root)//释放内存
{
    if (root == NULL)
        return;
    delet(root->left);
    delet(root->right);
    delete root;
}
bool cmp(T* ori_root, T* cur_root)
{
    if (ori_root == NULL && cur_root == NULL)
        return true;
    if ((ori_root == NULL && cur_root) || (ori_root && cur_root == NULL)
       || (ori_root->val != cur_root->val))
        return false;
    if (!cmp(ori_root->left, cur_root->left))
        return false;
    if (!cmp(ori_root->right, cur_root->right))
        return false;
    return true;
}
int main()
{
    int n;
    string ori, cur;
    while (cin >> n) {
        if (n == 0)
            return 0;
        cin >> ori;
        T* ori_root = new T(ori[0] - '0');
        for (int i = 1;i < ori.length();i++) 
            insert(ori_root, ori[i] - '0');
        for (int i = 1;i <= n;i++) {
            cin >> cur;
            T* cur_root = new T(cur[0] - '0');
            for (int i = 1;i < cur.length();i++) 
                insert(cur_root, cur[i] - '0');
            cout << (cmp(ori_root, cur_root) ? "YES" : "NO") << endl;
            delet(cur_root);
        }
        delet(ori_root);
    }
    return 0;
}