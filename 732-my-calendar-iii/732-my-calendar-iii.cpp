class MyCalendarThree {
public:
    map<int, int> mp;
    
    int book(int start, int end) {
        mp[start]++, mp[end]--; 
        int curr = 0 , i = 0;
        for (auto x : mp)
            i = max(i, curr += x.second);
        return i;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */