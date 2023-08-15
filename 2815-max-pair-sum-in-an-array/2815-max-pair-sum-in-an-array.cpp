class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i=0 ; i<n ; i++) {
            int maxDigit = 0;
            int x = nums[i];
            while(x) {
                maxDigit = max(maxDigit, x % 10);
                x /= 10;
            }
            
            mp[maxDigit].push_back(nums[i]);
        }
        
        int result = -1;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            auto v = it->second;
            if(v.size() > 1) {
                sort(v.rbegin(), v.rend());
                result = max(result, v[0] + v[1]);
            }
        }
        
        return result;
    }
};