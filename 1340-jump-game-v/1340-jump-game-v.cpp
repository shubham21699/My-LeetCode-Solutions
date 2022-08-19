class Solution {
public:
    int jumps(vector<int>& arr, int i, int n, int d, vector<int>& dp) {
        
        if(i >= n || i < 0) return 0;
        if(i == 0 && arr[i] <= arr[i+1]) return 0;
        if(i == n-1 && arr[i] <= arr[i-1]) return 0;
        if(i>0 && i<n && arr[i] <= arr[i-1] && arr[i] <= arr[i+1]) return 0;
        if(dp[i] != -1) return dp[i];
        
        int count = 0;
        
        for(int j=i-1 ; j>=i-d && j>=0 ; j--) {
            if(arr[i] > arr[j]) count = max(count, 1 + jumps(arr, j, n, d, dp));
            else break;
        }
        
        for(int j=i+1 ; j<=i+d && j<n ; j++) {
            if(arr[i] > arr[j]) count = max(count, 1 + jumps(arr, j, n, d, dp));
            else break;
        }
        
        return dp[i] = count;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int maxi = 1;
        vector<int> dp(n, -1);
        
        for(int i=0 ; i<n ; i++) {
            maxi = max(maxi, 1 + jumps(arr, i, n, d, dp));
        }
        
        return maxi;
    }
};