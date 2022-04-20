class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // Using Monotonic Stack Approach:
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) {
            
            // result.size() is the no. of elements in the stack right now and
            // nums.size()-i can still be pushed in it to make its size equal to K.
            // So, if result.size()+nums.size()-i > k, then we can pop from the stack.
            while(!result.empty() && result.back() > nums[i] && result.size()+n-i > k) {
                result.pop_back();
            }
            
            if(result.size() < k) result.push_back(nums[i]);
        }
        
        return result;
    }
};