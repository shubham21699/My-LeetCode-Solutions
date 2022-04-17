class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 2) return arr[0]*arr[1];
        
        // Using Monotonic Stack Approach:
        stack<int> s;
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!s.empty() && s.top() <= arr[i]) {
                int x = s.top();
                s.pop();
                result += x * min(s.empty() ? INT_MAX : s.top(), arr[i]);
            }
            
            s.push(arr[i]);
            
        }
        
        int top = s.top();
        s.pop();
        
        while(!s.empty()) {
            int x = s.top();
            s.pop();
            result += x * min(s.empty() ? INT_MAX : s.top(), top);
            top = x;
        }
     
        return result;
    }
};