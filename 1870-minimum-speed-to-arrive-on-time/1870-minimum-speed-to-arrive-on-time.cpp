class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed, int n) {
        
        double time = 0;
        
        for(int i=0 ; i<n-1 ; i++) {
            time += ceil((dist[i] * 1.0) / speed);
            if(time > hour) return false;
        }
        
        time += (dist[n-1] * 1.0) / speed;
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n = dist.size();
        if(hour < n-1) return -1;
        
        int left = 1;
        int right = 1e7;
        int ans = -1;
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            if(isPossible(dist, hour, mid, n)) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
            
        }
        
        return ans;
    }
};