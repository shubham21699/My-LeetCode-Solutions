class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxFreq = 0;
        
        for(int i=0 ; i<n ; i++) {
            mp[nums[i]]++;
            maxFreq = max(maxFreq, mp[nums[i]]);
        }
        
        vector<vector<int>> result(maxFreq);
        
        for(auto it : mp) {
            int i = 0;
            while(it.second > 0) {
                result[i].push_back(it.first);
                i++;
                it.second--;
            }
        }
        
        return {result};
    }
};