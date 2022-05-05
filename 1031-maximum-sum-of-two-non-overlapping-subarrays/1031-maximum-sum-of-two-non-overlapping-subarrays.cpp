class Solution {
    int check(vector<int>& nums, int fl, int sl) {
        
        int n = nums.size();
        int sumFL = 0;
        int sumSL = 0;
        int maxi = 0;
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            sumFL += nums[i];
            
            if(i >= fl) {
                sumFL -= nums[i-fl];
                sumSL += nums[i-fl];
            }
            
            if(i-fl >= sl) {
                sumSL -= nums[i-fl-sl];
            }
            
            maxi = max(maxi, sumSL);
            result = max(result, sumFL + maxi);
        }
        
        return result;
    }
    
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        return max(check(nums, firstLen, secondLen), check(nums, secondLen, firstLen));
    }
};