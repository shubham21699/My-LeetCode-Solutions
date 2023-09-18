class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k == 0) return nums[0];
        if(n == 1) return 0;
        
        int result = 0;
        
        for(int i=1 ; i<n ; i++) {
            
            int count = 0;
            int x = i;
            
            while(x) {
                if(x & 1) count++;
                x >>= 1;
            }
            
            if(count == k) result += nums[i];
        }
        
        return result;
    }
};