class Solution {
    int atMostK(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            mp[nums[i]]++;
            
            while(mp.size() > k) {
                mp[nums[j]]--;
                
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
            
            count += (i - j + 1);
            
        }
        
        return count;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // Exactly(K) = atMost(K) - atMost(K-1);
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};