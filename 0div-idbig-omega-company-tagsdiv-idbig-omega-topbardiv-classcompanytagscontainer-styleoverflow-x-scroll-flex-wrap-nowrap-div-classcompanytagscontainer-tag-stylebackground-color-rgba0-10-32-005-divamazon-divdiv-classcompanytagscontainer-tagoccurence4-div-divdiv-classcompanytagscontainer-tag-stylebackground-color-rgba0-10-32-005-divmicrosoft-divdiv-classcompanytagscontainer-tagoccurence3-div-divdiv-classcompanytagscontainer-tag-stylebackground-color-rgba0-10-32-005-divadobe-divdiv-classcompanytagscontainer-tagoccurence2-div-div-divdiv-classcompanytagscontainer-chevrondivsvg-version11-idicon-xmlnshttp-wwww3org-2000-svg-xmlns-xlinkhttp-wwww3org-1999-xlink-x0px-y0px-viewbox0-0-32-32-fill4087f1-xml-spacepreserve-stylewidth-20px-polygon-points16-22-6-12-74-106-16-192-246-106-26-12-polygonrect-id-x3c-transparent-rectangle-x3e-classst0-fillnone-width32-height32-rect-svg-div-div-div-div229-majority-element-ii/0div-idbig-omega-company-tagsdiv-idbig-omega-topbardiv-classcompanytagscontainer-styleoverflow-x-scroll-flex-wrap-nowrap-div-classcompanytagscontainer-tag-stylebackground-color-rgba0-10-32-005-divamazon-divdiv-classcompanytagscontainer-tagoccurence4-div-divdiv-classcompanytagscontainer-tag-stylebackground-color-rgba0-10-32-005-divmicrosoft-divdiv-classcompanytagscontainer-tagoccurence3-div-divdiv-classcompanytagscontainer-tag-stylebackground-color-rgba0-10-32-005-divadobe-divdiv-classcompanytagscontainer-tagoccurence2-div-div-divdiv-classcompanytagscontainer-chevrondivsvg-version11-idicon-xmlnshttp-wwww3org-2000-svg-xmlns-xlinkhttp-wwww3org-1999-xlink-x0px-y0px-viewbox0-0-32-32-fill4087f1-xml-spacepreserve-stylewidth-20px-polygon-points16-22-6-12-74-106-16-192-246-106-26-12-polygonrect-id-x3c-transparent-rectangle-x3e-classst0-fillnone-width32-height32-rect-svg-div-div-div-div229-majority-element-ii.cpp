class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums;
        
        unordered_map<int, int> freq;
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) freq[nums[i]]++;
  
        for(auto it : freq) {
            if(it.second > n/3) result.push_back(it.first);
        }
        
        return result;
    }
};