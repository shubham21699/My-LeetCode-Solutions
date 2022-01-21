class Solution {
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        
        while(start <= end) {
            
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) start = mid+1;
            else end = mid-1;
            
        }
        
        return start;
        
    }
    
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        if(n == 1) {
            if(nums[0] == target || nums[0] > target) return 0;
            return 1; 
        }
        
        return binarySearch(nums, target, 0, n-1);
        
    }
};