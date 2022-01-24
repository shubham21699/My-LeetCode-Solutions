class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> result(2, -1);
        
        if(n == 0) return result;
        if(n == 1) {
            if(nums[0] == target) {
                result[0] = 0;
                result[1] = 0;
            }
            return result;
        }
        if(n == 2) {
            if(nums[0] == target && nums[1] == target) {
                result[0] = 0; result[1] = 1;
            }
            else if(nums[0] == target) result[0] = result[1] = 0;
            else if(nums[1] == target) result[0] = result[1] = 1;
            
            return result;
        }
        
        if(nums[0] == target) {
            int end = 0;
            while(nums[end] == target && end < n) end++;
            
            result[0] = 0;
            result[1] = end-1;
            return result;
        }
        
        if(nums[n-1] == target) {
            int start = n-1;
            while(nums[start] == target && start >= 0) start--;
            
            result[0] = start+1;
            result[1] = n-1;
            return result;
        }
        
        int left = 0;
        int right = n-1;
        
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                int start = mid;
                int end = mid;
                while(nums[start] == target && start >= 0) start--;
                while(nums[end] == target && end < n) end++;
                result[0] = start+1;
                result[1] = end-1;
                return result;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
            
        }
        
        return result;
        
    }
};