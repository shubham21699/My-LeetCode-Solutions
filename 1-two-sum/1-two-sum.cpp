class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> result(2);
        
        unordered_map<int, int> m;
        unordered_map<int, int> mi;
        for(int i=0 ; i<n ; i++) {
            m[nums[i]]++;
            mi[nums[i]] = i;
        }
        
        for(int i=0 ; i<n ; i++) {
            m[nums[i]]--;
            if(m[target-nums[i]] > 0) {
                result[0] = i;
                result[1] = mi[target-nums[i]];
                break;
            }
        }
        
        return result;
    }
};