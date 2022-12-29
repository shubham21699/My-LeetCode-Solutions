class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            long long lcm = 1;
            
            for(int j=i ; j<n ; j++) {
                lcm = (lcm * nums[j]) / __gcd(lcm, (long long) nums[j]); 
                
                if(lcm == k) count++;
                if(lcm > k) break;
            }
            
        }
        
        return count;
    }
};