class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> power(n, 1);
        
        for(int i=1 ; i<n ; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }
        
        int count = 0;
        int left = 0, right = n-1;
        
        while(left <= right) {
            if(nums[left] + nums[right] > target) right--;
            else {
                count = (count + power[right - left]) % mod;
                left++;
            }
        }
        
        return count;
    }
};