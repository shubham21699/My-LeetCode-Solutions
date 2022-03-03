class Solution {
    bool check(vector<int>& nums, vector<bool>& visited, int current_sum, int k, int current_index, int target) {
        
        // If we've filled all the subsets then definitely a valid partition exists so return true
        if(k == 1) return true;
        
        if(current_index >= nums.size() || current_sum > target) return false;
        
        // If we've filled one subset completely, we'll focus on filling the next subset 
        // starting from the 0th index
        if(current_sum == target) return check(nums, visited, 0, k-1, 0, target);
        
        // Now we'll try to fill our current subset
        for(int i=current_index ; i<nums.size() ; i++) {
            
            // if an element is unvisited and can be added to the current subset sum (i.e. adding that
            // element to our current subset won't exceed it's sum from the desired value , then add it)
            if(!visited[i] && current_sum+nums[i] <= target) {
                visited[i] = true;
                
                if(check(nums, visited, current_sum+nums[i], k, i+1, target)) return true;
                
                visited[i] = false;
            }
            
        }
        
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return true; 
        
        int sum = 0;
        for(int i=0 ; i<n ; i++) sum += nums[i];
        
        // if sum is not divisable by k then it can not be partitioned 
        if(n < k || sum % k != 0) return false;
        
        int target = sum/k;
        vector<bool> visited(n, false);
        
        return check(nums, visited, 0, k, 0, target);
    }
};