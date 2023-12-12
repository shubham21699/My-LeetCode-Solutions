class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int biggest = 0, secBiggest = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] > biggest) {
                secBiggest = biggest;
                biggest = nums[i];
            }
            else secBiggest = max(secBiggest, nums[i]);
        }
        
        return (biggest-1) * (secBiggest-1);
    }
};