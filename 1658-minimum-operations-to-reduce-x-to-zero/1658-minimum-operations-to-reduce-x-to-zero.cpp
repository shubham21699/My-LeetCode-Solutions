class Solution {  
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        if(n == 1) return nums[0]==x;
        if(n == 2) {
            if(x-nums[0] == 0 || x-nums[1] == 0) return 1;
            if(x-nums[0]-nums[1] == 0) return 2;
            return -1;
        }
        
        int i = 0;
        int j = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int steps = INT_MAX;
        
        while(i <= j) {
            if(sum >= x) {
                if(sum == x) steps = min(steps, i+n-j);
                if(j < n) sum -= nums[j++];
                else break;
            }
            else sum += nums[i++];
        }
        
        return steps == INT_MAX ? -1 : steps;
    }
};