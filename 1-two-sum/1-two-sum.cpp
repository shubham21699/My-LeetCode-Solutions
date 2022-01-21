class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> result(2);
        
        unordered_map<int, int> m;
        
        for(int i=0 ; i<n ; i++) {
            if(m.find(target-nums[i]) != m.end()) {
                result[0] = i;
                result[1] = m[target-nums[i]];
                break;
            }
            
            m[nums[i]] = i;
        }
        
        return result;
    }
};