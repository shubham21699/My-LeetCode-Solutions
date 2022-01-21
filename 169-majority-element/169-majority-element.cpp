class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        int i = 0;
        
        while(i < n) {
            m[nums[i]]++;
            if(m[nums[i]] > floor(n/2)) break;
            
            i++;
        }
        
        return nums[i];
    }
};