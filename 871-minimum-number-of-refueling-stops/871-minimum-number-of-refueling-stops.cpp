class Solution {
public:
    int minSteps(vector<vector<int>>& stations, int i, int n, int fuelLeft, int target, int distCovered, vector<vector<int>>& dp) {
        
        if(i >= n) return target - distCovered <= fuelLeft ? 0 : 1e9;
        if((long long) stations[i][0] - fuelLeft - distCovered > 0) return 1e9;
        if(dp[fuelLeft][distCovered] != -1) return dp[fuelLeft][distCovered];
        
        int movedfromPrevStation = stations[i][0] - distCovered;
        
        return dp[fuelLeft][distCovered] = min(1 + minSteps(stations, i+1, n, (long long) fuelLeft - movedfromPrevStation + stations[i][1], target, stations[i][0], dp), minSteps(stations, i+1, n, fuelLeft - movedfromPrevStation, target, stations[i][0], dp));
        
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        if(startFuel >= target) return 0;
        
        int stops = 0;
        priority_queue<int> pq;
        int i = 0;
        int currFuel = startFuel;
        
        while(currFuel < target) {
            
            while(i < n && currFuel >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) return -1;
            
            currFuel += pq.top();
            pq.pop();
            stops++;
            
        }
        
        return stops;
        
//         // OR: Will give TLE
//         vector<vector<int>> dp(target+1, vector<int>(target+1, -1));
        
//         int res = minSteps(stations, 0, n, startFuel, target, 0, dp);
//         return res>n ? -1 : res;
    }
};