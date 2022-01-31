class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n, 0);
        if(n == 1) return result;
        
        // Using Monotonic Stack Approach here:
        stack<int> s;
        s.push(n-1); // Push last temperature index in stack first.
        
        // Move from right to left.
        for(int i=n-1 ; i>=0 ; i--) {
            
            // Pop untill we get next greater element to the right of temperatures[i].
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            
            // If stack is not empty, then element index at top of stack is the next greatest 
            // element of temperatures[i] and so our result[i] will be difference of its index 
            // and current index will be the number of days to wait to get warmer temperature.
            if(!s.empty()) result[i] = s.top()-i;
            
            // Push the current temperature index in the stack which will be same as 
            // pushing current temperature in the stack.
            s.push(i);
            
        }
        
        return result;
    }
};