class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int topEle = 0;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()) topEle = x;
        s1.push(x);
    }
    
    int pop() {
        
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int ans = s2.top();
        s2.pop();
        topEle = !s2.empty() ? s2.top() : 0;
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return ans;
        
    }
    
    int peek() {
        return topEle;
        
///////////////// OR //////////////         
//         while(!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
        
//         int ans = s2.top();
        
//         while(!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
        
//         return ans;
        
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */