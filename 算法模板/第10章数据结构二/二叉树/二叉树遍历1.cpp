//(北大) 二叉树遍历 https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef
#include<bits/stdc++.h>
using namespace std;
string s;
class T
{
public:
    T* left;
    T* right;
    char ch;
    T(char c) 
    {
        left = right = NULL;
        ch = c;
    }
};
void print(T* root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->ch << " ";
    print(root->right);
}
T* create(int& index)//完全二叉树
{
    if (s[index] == '#')
        return NULL;
    T* root = new T(s[index]);
    root->left = create(++index);
    root->right = create(++index);
    return root;
}
int main()
{
    cin >> s;
    int index = 0;
    T* root = create(index);
    print(root);
    return 0;
}