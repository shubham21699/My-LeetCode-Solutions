class Solution {
public:
    bool isPossible(vector<int>& time, int totalTrips, long long trips) {
        
        int n = time.size();
        long long total = 0;
        
        for(int i=0 ; i<n ; i++) {
            total += (trips/time[i]);
            if(total >= totalTrips) return true;
        }
        
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        int n = time.size();
        long long left = 1;
        long long right = 1e14;
        long long minTime = 0;
        
        while(left <= right) {
            
            long long mid = left + (right - left)/2;
            
            if(isPossible(time, totalTrips, mid)) {
                minTime = mid;
                right = mid-1;
            }
            else left = mid+1;
            
        }
        
        return minTime;
    }
};