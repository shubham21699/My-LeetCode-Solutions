class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int result = 0;
        
        vector<int> left = height;
        vector<int> right = height;
        
        for(int i=1 ; i<n ; i++) left[i] = max(left[i], left[i-1]);
        for(int i=n-2 ; i>=0 ; i--) right[i] = max(right[i], right[i+1]);
        
        for(int i=1 ; i<n-1 ; i++) {
            result += max(0, min(left[i], right[i]) - height[i]);
        }
        
        return result;
    }
};