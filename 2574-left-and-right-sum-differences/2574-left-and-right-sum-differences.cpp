class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        int n = nums.size();
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> answer(n);
        
        for(int i=0 ; i<n ; i++) {
            rightSum -= nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return answer;
    }
};