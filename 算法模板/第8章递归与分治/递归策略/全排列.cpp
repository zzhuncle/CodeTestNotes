#include<bits/stdc++.h>
using namespace std;
string in;
set<string> st; //按字典序遍历 所以使用set
void swap(char &x,char &y)
{
    char temp = x;
    x = y;
    y = temp;
}
void dfs(int cur)
{
    if (cur == in.size()){
        st.insert(in);
        return ;
    }
    for(int i = cur;i < in.size();i++){
        swap(in[cur], in[i]);
        dfs(cur + 1);
        swap(in[cur], in[i]);
    }
}
int main()
{
    cin >> in;
    dfs(0);
    for(auto i = st.begin();i != st.end();i++)
        cout << *i << endl;
    return 0;
} 