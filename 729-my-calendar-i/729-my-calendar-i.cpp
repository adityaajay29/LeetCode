class MyCalendar {
public:
    unordered_map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x : mp)
        {
            if(start < x.second && end > x.first)
                return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */