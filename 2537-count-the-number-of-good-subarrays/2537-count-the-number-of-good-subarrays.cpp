class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long count = 0;
        long long pairs = 0;
        unordered_map<int, int> freq;
        int j = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            pairs += freq[nums[i]];
            freq[nums[i]]++;
            
            while(pairs >= k) {
                count += n-i;
                pairs -= freq[nums[j]] - 1;
                freq[nums[j]]--;
                j++;
            }
        }
        
        return count;
    }
};