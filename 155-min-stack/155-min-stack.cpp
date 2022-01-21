class MinStack {
    deque<int> d;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        d.push_back(val);
    }
    
    void pop() {
        d.pop_back();
    }
    
    int top() {
        return d.back();
    }
    
    int getMin() {
        
        int ans = INT_MAX;
        
        for(auto it=d.begin() ; it!=d.end() ; it++) {
            ans = min(ans, *it);
        }
        
        return ans;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */