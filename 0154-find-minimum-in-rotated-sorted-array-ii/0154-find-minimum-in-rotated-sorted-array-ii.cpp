class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high) {
         
            int mid = low + (high - low)/2;
            
            if(nums[mid] > nums[high]) low = mid+1;
            else if(nums[mid] > nums[low]) high = mid-1;
            else high--; // When num[mid] == num[high], we couldn't sure the position of minimum in mid's left or right, so just let upper bound reduce by one.
            
        }
        
        return nums[low];
    }
};