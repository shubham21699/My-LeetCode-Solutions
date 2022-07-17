class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, priority_queue<int>> mp;
        
        for(int i=0 ; i<n ; i++) {
            int x = nums[i];
            int sum = 0;
            while (x != 0) {
                sum = sum + x % 10;
                x = x / 10;
            }
            
            mp[sum].push(nums[i]);
        }
        
        int result = -1;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            priority_queue<int> p = it->second;
            
            if(p.size() >= 2) {
                int a = p.top();
                p.pop();
                int b = p.top();
                p.pop();
                result = max(result, a + b);
            }
            
        }
        
        return result;
    }
};