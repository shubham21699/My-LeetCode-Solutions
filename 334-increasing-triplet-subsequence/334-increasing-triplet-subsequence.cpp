class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int min = INT_MAX;
        int mid = INT_MAX;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] <= min) min = nums[i]; // This will be the min number so far
            else if(nums[i] <= mid) mid = nums[i]; // This will be just bigger than min element get so far 
            else return true; // If current nums[i] is greater than both min and mid numbers
        }
        
        return false;
    }
};