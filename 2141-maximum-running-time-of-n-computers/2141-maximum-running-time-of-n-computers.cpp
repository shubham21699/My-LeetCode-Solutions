class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        int m = batteries.size();
        long long low = 1;
        long long high = 0;
        
        for(int i=0 ; i<m ; i++) high += batteries[i];
        high /= n;
        
        long long ans = -1;
        
        while(low <= high) {
            
            long long mid = low + (high - low) / 2;
            
            long long time = 0;
            for(int i=0 ; i<m ; i++) time += min(mid, (long long) batteries[i]);
            
            // Now if 1 computer take mid time then n computer take mid * n time.
            // So, if time >= mid * n then there is some time left to run more computer.
            if(time >= mid * n) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
            
        }
        
        return ans;
    }
};