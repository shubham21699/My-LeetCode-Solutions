class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n == 1) {
            if(nums[0] == target) return 0;
            return -1;
        }
        
        // BINARY SEARCH:
        int left = 0;
        int right = n-1;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            if(nums[mid] == target) return mid;
            
            // There exists rotation, the middle elements is in left part of array
            if(nums[mid] > nums[right]) {
                if(target < nums[mid] && target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            // There exists rotation, the middle element is in right part of array
            else if(nums[mid] < nums[left]) {
                if(target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
            // There is no rotation, so normal Binary Search
            else {
                if(target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
            
        }
        
        return -1;
    }
};