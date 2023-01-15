class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int n = nums.size();
        long long elementSum = 0;
        long long digitSum = 0;
        
        for(int i=0 ; i<n ; i++) {
            elementSum += nums[i];
            
            while(nums[i]) {
                digitSum += nums[i] % 10;
                nums[i] /= 10;
            }
            
        }
        
        return abs(elementSum - digitSum);
    }
};