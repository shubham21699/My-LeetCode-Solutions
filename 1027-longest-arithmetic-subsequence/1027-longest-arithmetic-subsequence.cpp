class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
       /* In this solution, we use dynamic programming to store intermediate results in order to build our          final answer.

        Clearly, if the sequence is of size 2, then that is our final answer, since our arithmetic                  subsequence would just be our first and second element.

        Otherwise, we arrive at the following dynamic programming relation: dp[i][difference] = dp[j]               [difference] + 1, where i > j and difference = A[i] - A[j], where each entry is the longest                 arithmetic subsequence up to index i that has common difference difference. Note that the difference         could be negative, so in the true implementation we offset the difference by its maximum value to           ensure we would never have a negative index in our tabulation.

        To understand this, consider some arithmetic subsequence that has common difference k, which as n           elements currently. If we had another element to this subsequence which is equal to the last element         of the original subsequence plus the common difference, then we have arrived at a new subsequence           that is still an arithmetic progression, but is exactly one element longer. Therefore, to find our           answer, we are keeping track of the longest possible arithmetic subsequence a given element can have         relative to all elements before it, which each have a specific difference, and using this to build           our final answer. We must also keep a maxLen variable, since we don't know which value of difference         will give us the correct final answer, and thus we must update it as we go along.

        Since we are creating a two-dimensional matrix to store our subproblem values as we go along, we             require quadratic space, and for a given entry, we are looping over all entries which are behind it,         giving us quadratic time complexity. */
        
        int n = nums.size();
        if(n == 2) return 2;
        
        vector<vector<int>> dp(n, vector<int>(1001, 1)); // dp[index][diff]
        int result = 2;
        
        for(int i=1; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                
                int diff = nums[i] - nums[j] + 500;
                
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                result = max(result, dp[i][diff]);
                
            }
        }
        
        return result;
    }
};