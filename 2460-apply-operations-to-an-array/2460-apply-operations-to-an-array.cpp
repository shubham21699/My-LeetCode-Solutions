class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0 ; i<n-1 ; i++) {
            if(nums[i] == 0) continue;
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
                i++;
            }
        }
        
        int i = 0;
        while(i < n) {
            if(nums[i] == 0) {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                n--;
            }
            else i++;
        }
        
        return nums;
    }
};