class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1) return n;
        if(n == 2) {
            if(abs(nums[0]-nums[1]) == 1) return 2;
            return 1;
        }
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();
        
        int maxLen = 1;
        int len = 1;
        
        for(int i=1 ; i<n ; i++) {
            if(nums[i]-nums[i-1] == 1) len++;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        
        maxLen = max(maxLen, len);
        return maxLen;
    }
};