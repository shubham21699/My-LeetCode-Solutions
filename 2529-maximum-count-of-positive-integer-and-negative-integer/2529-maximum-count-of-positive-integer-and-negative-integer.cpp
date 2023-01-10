class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();
        
        int pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        return max(n-pos, neg);
        
//         // OR:
//         int pos = 0, neg = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             if(nums[i] > 0) pos++;
//             else if(nums[i] < 0) neg++;
//         }
        
//         return max(pos, neg);
    }
};