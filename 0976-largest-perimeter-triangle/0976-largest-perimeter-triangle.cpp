class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();
        int result = 0;
        
        sort(nums.rbegin(), nums.rend());
        
        for(int i=0 ; i<n-2 ; i++) {
            
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            
            if(a < b+c) {
                result = max(result, a + b + c);
            }
            
        }
        
        return result;
    }
};