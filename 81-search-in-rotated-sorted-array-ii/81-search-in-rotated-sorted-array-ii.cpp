class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == target) return true;
            return false;
        }
        if(n == 2) {
            if(nums[0] == target || nums[1] == target) return true;
            return false;
        }
        if(nums[0] == target || nums[n-1] == target) return true;
        
        int left = 0;
        int right = n-1;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            if(nums[mid] == target) return true;
            
            if(nums[left] < nums[mid]) {
                if(target < nums[mid] && target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            else if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
            else {
                if(nums[left] == nums[mid]) left++;
                if(nums[right] == nums[mid]) right--;
            }
            
        }
        
        return false;
    }
};