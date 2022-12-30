class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] < k) nums[i] = -1;
            else if(nums[i] > k) nums[i] = 1;
            else nums[i] = 0;
        } 
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int balance = 0;
        bool isKPresent = false;
        
        for(int i=0 ; i<n ; i++) {
            
            balance += nums[i];
            if(nums[i] == 0) isKPresent = true;
            
            if(isKPresent) {
                // find x in prefix hashmap 
                // greater - smaller == 0 or 1
                // => prefix[i] - prefix[x] == 0 or 1
                // => curBalance - prefix[x] == 0 or curBalance - prefix[x] == 1
                // => prefix[x] == curBalance or prefix[x] == curBalance - 1
                count += mp[balance] + mp[balance - 1];
            }
            else mp[balance]++;
        }
        
        return count;
    }
};