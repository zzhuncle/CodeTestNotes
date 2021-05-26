//查找第K小的数 https://www.nowcoder.com/practice/204dfa6fcbc8478f993d23f693189ffd
//最小堆思想
//维护一个只有k个元素的最大堆，这样复杂度只有O(nlogk)，当目前元素小于堆顶元素时，弹出堆顶，压入新元素
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    vector<int> num(n, 0);
    //首先去重
    int temp, i = 0;
    set<int> st;
    priority_queue<int> que;
    for (int i = 0;i < n;i++) {
        cin >> temp;
        st.insert(temp);
    }
    for (auto it = st.begin();it != st.end();it++)
        num[i++] = *it;
    cin >> k;
    for (int j = 0;j < i;j++) {
        if (que.size() < k)
            que.push(num[j]);
        else {
            if (num[j] < que.top()) {
                que.pop();
                que.push(num[j]);
            }
        }
    }
    cout << que.top() << endl;
    return 0;
}*/
//2 1 2 
//快速排序思想
//Todo