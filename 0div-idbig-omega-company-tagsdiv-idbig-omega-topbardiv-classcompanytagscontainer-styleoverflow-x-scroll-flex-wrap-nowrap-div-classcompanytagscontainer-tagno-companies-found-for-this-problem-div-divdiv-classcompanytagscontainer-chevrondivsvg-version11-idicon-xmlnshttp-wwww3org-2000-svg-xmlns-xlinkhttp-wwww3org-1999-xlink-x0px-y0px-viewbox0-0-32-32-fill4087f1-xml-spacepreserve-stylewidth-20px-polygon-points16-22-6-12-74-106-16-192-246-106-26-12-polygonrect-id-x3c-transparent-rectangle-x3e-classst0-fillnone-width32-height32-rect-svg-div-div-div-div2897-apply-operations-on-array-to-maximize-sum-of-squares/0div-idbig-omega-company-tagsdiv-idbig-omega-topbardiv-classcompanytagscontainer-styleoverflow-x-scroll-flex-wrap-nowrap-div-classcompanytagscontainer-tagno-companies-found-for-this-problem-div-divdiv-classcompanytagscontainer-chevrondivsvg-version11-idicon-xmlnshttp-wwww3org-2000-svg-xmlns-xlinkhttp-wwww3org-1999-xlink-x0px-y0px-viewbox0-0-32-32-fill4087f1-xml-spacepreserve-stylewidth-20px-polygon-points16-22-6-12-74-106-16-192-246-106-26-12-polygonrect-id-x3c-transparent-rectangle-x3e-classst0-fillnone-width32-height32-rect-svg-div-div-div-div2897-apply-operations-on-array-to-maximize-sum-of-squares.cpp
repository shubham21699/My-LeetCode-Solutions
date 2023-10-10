class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int maxSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> count;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<32 ; j++) {
                if(nums[i] & (1 << j)) count[j]++;
            }
        }
        
        int result = 0;
        
        for(int i=0 ; i<k ; i++) {
            int num = 0;
            
            for(int j=0 ; j<32 ; j++) {
                if(count[j] > 0) {
                    count[j]--;
                    num += 1 << j;
                }
            }
            
            result = (result + (1L * num * num) % mod) % mod;
        }
        
        return result;
    }
};