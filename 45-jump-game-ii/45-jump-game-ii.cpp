class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return 0;        
        if(n == 2) return 1;
        
///////////////  Greedy Approach  ////////////////
        int steps = 0;
        int start = 0;
        int end = 0;
        
        while(end < n-1) {
            
            steps++;
            int maxEnd = end+1;
            
            for(int i=start ; i<=end ; i++) {
                if(i+nums[i] >= n-1) return steps;
                maxEnd = max(maxEnd, i+nums[i]);
            }
            
            start = end+1;
            end = maxEnd;
        }
        
        return steps;
        
///////////////  OR: DP Approach  ////////////////////
//         vector<int> jumps(n, INT_MAX);
//         jumps[0] = 0;
        
//         // Find minimum number of jumps to reach nums[i] from nums[0],
//         // and assign this value to jumps[i]
//         for(int i=1 ; i<n ; i++) {
//             for(int j=0 ; j<i ; j++) {
//                 if(j+nums[j] >= i && jumps[j] != INT_MAX) {
//                     jumps[i] = min(jumps[i], jumps[j]+1);
//                     break;
//                 }
//             }
//         }
        
//         return jumps[n-1];
        
    }
};