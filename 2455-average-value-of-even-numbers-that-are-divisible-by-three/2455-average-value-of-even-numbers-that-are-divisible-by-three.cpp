class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int countEle = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] % 6 == 0) {
                sum += nums[i];
                countEle++;
            }
        }
        
        return sum == 0 ? 0 : (sum / countEle);
    }
};