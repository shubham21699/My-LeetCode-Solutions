class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
        int n = nums.size();
        long long totalSum = 0;
        
        for(int i=0 ; i<n ; i++) {
            totalSum += nums[i];
            if(totalSum == target || nums[i] == target) return 0;
        }
        
        if(totalSum < target) return -1;
        
        sort(nums.begin(), nums.end());
        int result = 0;
        
        while(target > 0) {
            int x = nums.back();
            nums.pop_back();
            
            if(totalSum - x >= target) {
                totalSum -= x;
            }
            else if(x <= target) {
                totalSum -= x;
                target -= x;
            }
            else {
                nums.push_back(x / 2);
                nums.push_back(x / 2);
                result++;
            }
        }
        
        return result;
    }
};