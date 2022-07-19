class Solution {
public:
    int find(vector<int>& nums, int i, int j) {
        
        int n = nums.size();
        
        if(i <= j) {
            
            int mid = i + (j-i)/2;
            
            if(mid > 0 && mid < n-1 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) 
                return nums[mid];
            
            int left = find(nums, i, mid-1);
            int right = find(nums, mid+1, j);
            
            // Return -1 if not find in both left and right to mid otherwise return that single element.
            return max(left, right);
        }
        
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0]; // If 1st element is the one which occurred once.
        if(nums[n-1] != nums[n-2]) return nums[n-1]; // If last element is the one which occurred once.
        
        return find(nums, 0, n-1);
    }
};