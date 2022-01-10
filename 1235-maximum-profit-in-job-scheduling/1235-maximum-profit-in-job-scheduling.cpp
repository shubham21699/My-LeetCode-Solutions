class Solution {  
    
    // Binary Search optimised function to find latest non-overlapping interval
    int latest_non_overlapping_interval(vector<vector<int> >& v, int index) {
        
        int low = 0;
        int high = index-1;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(v[mid][0] <= v[index][1]) {
                if(v[mid+1][0] <= v[index][1]) low = mid+1;
                else return mid;
            }
            else {
                high = mid-1;
            }
            
        }
        
        return -1;
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        if(n == 1) return profit[0];
        
        vector<vector<int> > v;
        
        for(int i=0 ; i<n ; i++) {
            v.push_back({ endTime[i], startTime[i], profit[i] });
        }
        
        sort(v.begin(), v.end());
        
        vector<int> dp(n, 0);
        dp[0] = v[0][2];
        
        for(int i=1 ; i<n ; i++) {
            
            int inclusive = v[i][2];
            int exclusive = dp[i-1];
            
            int index = latest_non_overlapping_interval(v, i);
            
            if(index != -1) {
                inclusive += dp[index];
            }
            
            dp[i] = max(inclusive, exclusive);
            
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};