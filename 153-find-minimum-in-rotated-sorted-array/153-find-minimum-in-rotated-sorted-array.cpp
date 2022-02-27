class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        if(n == 3) return min({ nums[0], nums[1], nums[2] });
        if(nums[n-1] < nums[n-2]) return nums[n-1]; // If Min. Element present at last index.
        if(nums[0] < nums[n-1]) return nums[0]; // If Min. Ekement present at first index.
        
        int left = 0;
        int right = n-1;
        
        while(left < right) {
            
            if(nums[left] < nums[right]) return nums[left];
            
            int mid = left + (right - left)/2;
            
            if(nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
            
        }
        
        return nums[left];
    }
};