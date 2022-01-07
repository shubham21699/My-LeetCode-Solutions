class Solution {
    int find(vector<int>& nums, int left, int right, vector<int> pre, vector<int> suf) {
        
        if(left == right) return nums[left];
        
        int mid = (right + left)/2;
        
        return max({ pre[mid] + suf[mid+1], find(nums, left, mid-1, pre, suf), find(nums, mid+1, right, pre, suf) });
        
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) {
            return max(nums[0]+nums[1], max(nums[0], nums[1]));
        }
        
        vector<int> prefix_sum = nums;
        vector<int> suffix_sum = nums;
        
        for(int i=1 ; i<n ; i++) {
            prefix_sum[i] += max(0, prefix_sum[i-1]);
        }
        
        return *max_element(prefix_sum.begin(), prefix_sum.end());
        
        for(int i=n-2 ; i>=0 ; i--) {
            suffix_sum[i] += (0, suffix_sum[i+1]);
        }
        
        return find(nums, 0, n-1, prefix_sum, suffix_sum);
        
        
        
//////////////////////////// OR ///////////////////////////////         
//         int maxSum = nums[0];
//         int sum = nums[0];
        
//         for(int i=1 ; i<n ; i++) {
//             sum = max(nums[i], sum+nums[i]);
//             maxSum = max(maxSum, sum);
//         }
        
//         return maxSum;
        
/////////////////////////// OR ///////////////////////////////         
//         int maxSum = nums[0];
//         int sum = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             sum += nums[i];
//             maxSum = max(maxSum, sum);
//             if(sum < 0) sum = 0;
//         }
        
//         return maxSum;
        
    }
};