class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        
        // Find least index creating mismatch and largest index creating mismatch by doing 
        // two traversals, left to right and right to left respectively.
        
        int start = n;
        int end = -1;
        
        // Using Monotonic Stack Approach:
        stack<int> s;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!s.empty() && nums[s.top()] > nums[i]) {
                start = min(start, s.top());
                s.pop();
            }
            
            s.push(i);
        }
        
        if(start == n) return 0;
        
        while(!s.empty()) {
            s.pop();
        }
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            while(!s.empty() && nums[s.top()] < nums[i]) {
                end = max(end, s.top());
                s.pop();
            }
            
            s.push(i);
        }
        
        return end-start+1;
    }
};