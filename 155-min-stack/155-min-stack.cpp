class MinStack {
    deque<pair<int, int> > d;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        int mini;
        
        if(d.empty()) mini = val;
        else mini = min(val, d.back().second);
        
        d.push_back({ val, mini });
    }
    
    void pop() {
        d.pop_back();
    }
    
    int top() {
        return d.back().first;
    }
    
    int getMin() {
        return d.back().second;
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