class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2) return n;
        int position = 2;
        
        for(int i=2 ; i<n ; i++) {
            if(nums[i] != nums[position-2]) {
                nums[position++] = nums[i];
            }
        }
        
        return position;
    }
};