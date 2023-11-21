class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int reverse(int n) {
        
        int num = 0;
        
        while(n) {
            num = num*10 + (n % 10);
            n /= 10;
        }
        
        return num;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            int x = nums[i] - reverse(nums[i]);
            
            if(mp.find(x) != mp.end()) count = (count + mp[x]) % mod;
            
            mp[x]++;
        }
        
        return count;
    }
};