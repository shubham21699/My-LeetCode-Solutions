const int mod = 1e9 + 7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        long int maxHorDist = 0;
        long int maxVertDist = 0;
        
        int prevH = 0;
        int prevW = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        // Calculating maximum distance between horizontal cuts.
        for(int i=0 ; i<n ; i++) {
            maxHorDist = max(maxHorDist, (long int) horizontalCuts[i] - prevH);
            maxHorDist %= mod;
            prevH = horizontalCuts[i];
        }
        maxHorDist = max(maxHorDist, (long int) h - prevH);
        maxHorDist %= mod;
        
        // Calculating maximum distance between vertical cuts.
        for(int i=0 ; i<m ; i++) {
            maxVertDist = max(maxVertDist, (long int) verticalCuts[i] - prevW);
            maxVertDist %= mod;
            prevW = verticalCuts[i];
        }
        maxVertDist = max(maxVertDist, (long int) w - prevW);
        maxVertDist %= mod;
        
        return (maxHorDist * maxVertDist) % mod;
    }
};