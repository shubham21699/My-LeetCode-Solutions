class Solution {    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n < 4) return {};
    
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> v;
        
        for(int i=0 ; i<n ; i++) {
            int target3 = target - nums[i];
            
            for(int j=i+1 ; j<n ; j++) {
                int target2 = target3 - nums[j];
                
                int k = j+1;
                int l = n-1;
                
                while(k < l) {
                    
                    int two_sum = nums[k] + nums[l];
                    
                    if(two_sum == target2) {
                        result.push_back({ nums[i], nums[j], nums[k], nums[l] });
                        int x = nums[k];
                        int y = nums[l];
                        
                        while(nums[k] == x && k<l) k++;
                        while(nums[l] == y && k<l) l--;
                        
                    }
                    else if(two_sum > target2)
                        l--;
                    else k++;
                }
                
                while(j+1<n && nums[j] == nums[j+1]) j++;
            }
            
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }
        
        return result;
    }
};