//(华科大) 二叉树遍历 https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce
//根据前序和中序遍历求解后序字符串
#include<bits/stdc++.h>
using namespace std;
string before, middle;
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
    print(root->right);
    cout << root->ch;
}
T* create(string before, string middle)
{
    if (before == "" && middle == "")//注意边界条件NULL的判断
        return NULL;
    T* root = new T(before[0]);
    int index = middle.find(before[0]);
    root->left = create(before.substr(1, index), middle.substr(0, index));
    root->right = create(before.substr(index + 1), middle.substr(index + 1));
    return root;
}
int main()
{
    while (cin >> before >> middle) {
        T* root = create(before, middle);
        print(root);
        cout << endl;
    }
    return 0;
}