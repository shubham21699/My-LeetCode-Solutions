class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1];
        
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        
        while(nums[n-1] != maxi) {
            int x = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), x);
            count++;
        }
        
        for(int i=1 ; i<n ; i++) {
            if(nums[i] < nums[i-1]) return -1;
        }
        
        return count;
    }
};