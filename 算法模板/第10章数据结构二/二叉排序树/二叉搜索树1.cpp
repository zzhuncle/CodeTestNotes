// (华科大) 二叉排序树 https://www.nowcoder.com/practice/30a0153649304645935c949df7599602
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
            cout << root->val << endl;
            root->left = new T(t);
            return;
        }
        insert(root->left, t);
    }
    else {
        if (root->right == NULL) {
            cout << root->val << endl;
            root->right = new T(t);
            return;
        }
        insert(root->right, t);
    }
}
int main()
{
    int n, t;
    cin >> n >> t;
    T* root = new T(t);
    cout << -1 << endl;
    for (int i = 1;i < n;i++) {
        cin >> t;
        insert(root, t);
    }
    return 0;
}