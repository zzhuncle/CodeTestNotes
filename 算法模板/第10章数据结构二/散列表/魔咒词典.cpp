//魔咒词典 https://www.nowcoder.com/practice/c6ca566fa3984fae916e6d7beae8ea7f
#include<bits/stdc++.h>
using namespace std;
map<string, string> mp1;
map<string, string> mp2;
int main()
{
    string str;
    while (getline(cin, str)) {
        if (str == "@END@")
            break;
        int index = str.find(']');
        mp1[str.substr(1, index - 1)] = str.substr(index + 2);
        mp2[str.substr(index + 2)] = str.substr(1, index - 1);
    }
    int n;
    cin >> n;
    getchar();//吃掉回车
    for (int i = 0;i < n;i++) {
        getline(cin, str);
        if (str[0] == '[') {
            if (mp1.find(str.substr(1, str.find(']') - 1)) != mp1.end())
                cout << mp1[str.substr(1, str.find(']') - 1)] << endl;
            else
                cout << "what?" << endl;
        }
        else {
            if (mp2.find(str) != mp2.end())
                cout << mp2[str] << endl;
            else
                cout << "what?" << endl;
        }
    }
    return 0;
}
