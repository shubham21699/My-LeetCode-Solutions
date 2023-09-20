class Solution {
public:
    int countWays(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int selected = 0;
        int count = 0;
        
        if(nums[0] != 0) count = 1; // Not Selecting AnyOne
        
        for(int i=0 ; i<n ; i++) {
            selected++;
            
            if(selected > nums[i]) { // No. of Selected Students is strictly greater than nums[i].
                if(i+1 < n && selected < nums[i+1]) // Considering from (i+1) to n Students is not Selected.
                    count++; 
                else if(i+1 == n) count++; // Last Student
            }
            
        }
        
        return count;
    }
};