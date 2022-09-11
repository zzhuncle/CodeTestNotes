//729. 我的日程安排表 I
class MyCalendar {
private:
    unordered_set<int> lazy, tree;
public:
    MyCalendar() {

    }
    
    //区间查询
    bool query(int start, int end, int l, int r, int idx) {
        if (r < start || end < l)//没有任何交集
            return false;
        //如果区间被预定，直接返回
        if (lazy.count(idx))
            return true;
        if (start <= l && r <= end) 
            return tree.count(idx);
        int mid = (l + r) >> 1;
        return query(start, end, l, mid, 2 * idx) ||
            query(start, end, mid + 1, r, 2 * idx + 1);
    }
    
    //区间修改
    bool update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l)
            return false;
        if (start <= l && r <= end) {
            lazy.insert(idx);
            tree.insert(idx);
        }
        else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree.insert(idx);
            if (lazy.count(2 * idx) && lazy.count(2 * idx + 1)) {
                lazy.insert(idx);
            }
        }
        return true;
    }
    
    bool book(int start, int end) {
        if (query(start, end - 1, 0, 1e9, 1))
            return false;
        update(start, end - 1, 0, 1e9, 1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
