class MyCalendar {
public:
    set<pair<int, int>> st;
    
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        
        if(st.empty()) {
            st.insert({ start, end });
            return true;
        }
        
        for(auto it : st) {
            if(max(it.first, start) < min(it.second, end)) return false;
        }
        
        st.insert({ start, end });
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */