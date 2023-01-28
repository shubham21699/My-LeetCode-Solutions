class SummaryRanges {
public:
    set<int> st;
    
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>> result;
        
        for(auto it=st.begin() ; it!=st.end() ; ) {
            
            int start = *it;
            int end = *it;
            auto it2 = next(it, 1);
            auto it3 = it;
            
            while(it2 != st.end() && *it3 == *it2-1) {
                end = *it2;
                it3 = it2;
                it2++;
            }
            
            it = it2;
            result.push_back({ start, end });
        }
        
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */