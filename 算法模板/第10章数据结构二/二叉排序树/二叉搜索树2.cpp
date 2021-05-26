//(华科大) 二叉排序树 https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3
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
    else if (t > root->val) {
        if (root->right == NULL) {
            root->right = new T(t);
            return;
        }
        insert(root->right, t);
    }
    else//重复元素不考虑
        return;
}
void print1(T* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print1(root->left);
    print1(root->right);
}
void print2(T* root)
{
    if (root == NULL)
        return;
    print2(root->left);
    cout << root->val << " ";
    print2(root->right);
}
void print3(T* root)
{
    if (root == NULL)
        return;
    print3(root->left);
    print3(root->right);
    cout << root->val << " ";
}
int main()
{
    int n, t;
    while (cin >> n >> t) {
        T* root = new T(t);
        for (int i = 1;i < n;i++) {
            cin >> t;
            insert(root, t);
        }
        print1(root);cout << endl;
        print2(root);cout << endl;
        print3(root);cout << endl;
    }
    return 0;
}