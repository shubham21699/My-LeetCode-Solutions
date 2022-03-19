class FreqStack {
    unordered_map<int, stack<int>> st;
    unordered_map<int, int> mp;
    int maxFreq = 0;
    
public:
    FreqStack() {
        st.clear();
        mp.clear();
        maxFreq = 0;
    }
    
    void push(int val) {
        mp[val]++;
        maxFreq = max(maxFreq, mp[val]);
        st[mp[val]].push(val);
    }
    
    int pop() {
        
        int x = st[maxFreq].top();
        st[maxFreq].pop();
        mp[x]--;
        
        if(st[maxFreq].size() == 0) {
            maxFreq--;
        }
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */