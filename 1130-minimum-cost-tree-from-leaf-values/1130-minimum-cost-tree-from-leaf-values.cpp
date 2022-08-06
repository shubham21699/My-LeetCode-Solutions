class Solution {
public:
    int solve(int l, int r, vector<vector<int>>& dp, vector<int>& arr) {
        
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int ans = INT_MAX;
        
        for(int i=l ; i<r ; i++) {
            
            int leftMax = *max_element(arr.begin()+l, arr.begin()+i+1);
            int rightMax = *max_element(arr.begin()+i+1, arr.begin()+r+1);
            
            ans = min(ans, leftMax*rightMax + solve(l, i, dp, arr) + solve(i+1, r, dp, arr));
        }
        
        return dp[l][r] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 2) return arr[0]*arr[1];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, dp, arr);
        
//         // OR - Using Monotonic Stack Approach:
//         stack<int> s;
//         int result = 0;
        
//         for(int i=0 ; i<n ; i++) {
            
//             while(!s.empty() && s.top() <= arr[i]) {
//                 int x = s.top();
//                 s.pop();
//                 result += x * min(s.empty() ? INT_MAX : s.top(), arr[i]);
//             }
            
//             s.push(arr[i]);
            
//         }
        
//         int top = s.top();
//         s.pop();
        
//         while(!s.empty()) {
//             int x = s.top();
//             s.pop();
//             result += x * min(s.empty() ? INT_MAX : s.top(), top);
//             top = x;
//         }
     
//         return result;
    }
};