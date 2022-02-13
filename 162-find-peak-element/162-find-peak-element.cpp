class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) {
            if(nums[0] < nums[1]) return 1;
            return 0;
        }
        
        int left = 0;
        int right = n-1;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            // Compare middle element with its neighbours (if neighbours exist)
            if((mid==0 || nums[mid] >= nums[mid-1]) && (mid==n-1 || nums[mid] >= nums[mid+1])) return mid;
            
            // If middle element is not peak and its left neighbour is greater than it,
            // then left half must have a peak element
            else if(mid>0 && nums[mid] < nums[mid-1]) right = mid-1;
            
            // If middle element is not peak and its right neighbour is greater than it,
            // then right half must have a peak element
            else left = mid+1;
            
        }
        
        return 0;
    }
};