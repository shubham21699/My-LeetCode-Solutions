class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0] != 0;
        
        int count = 0;
        
        while(*max_element(nums.begin(), nums.end()) != 0) {
            
            int mini = INT_MAX;
            
            for(int i=0 ; i<n ; i++) {
                if(nums[i] == 0) continue;
                mini = min(mini, nums[i]);
            }
            
            for(int i=0 ; i<n ; i++) {
                if(nums[i] == 0) continue;
                nums[i] -= mini;
            }
            
            count++;
        }
        
        return count;
    }
};