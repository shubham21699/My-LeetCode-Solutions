class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return {};
        if(n == 1) return { to_string(nums[0]) };
        
        vector<string> result;
        
        if(n == 2) {
            string s = "";
            
            if(nums[1] - nums[0] == 1) {
                s = to_string(nums[0]) + "->" + to_string(nums[1]);
                result.push_back(s);
            }
            else {
                result.push_back(to_string(nums[0]));
                result.push_back(to_string(nums[1]));
            }
                
            return result;
        }
        
        string s = "";
        int start = nums[0];
        int end = nums[0];
        int i = 1;
        
        while(i < n) {
            
            while(i<n && nums[i] == nums[i-1] + 1) {
                end = nums[i];
                i++;
            }
            
            if(i == n) break;
            
            if(start != end) s = to_string(start) + "->" + to_string(end);
            else s = to_string(start);
                
            start = nums[i];
            end = nums[i];
            i++;
            
            result.push_back(s);
        }
        
        if(i == n) {
            if(start != end) s = to_string(start) + "->" + to_string(end);
            else s = to_string(start);
            result.push_back(s);
        }
        
        return result;
    }
};