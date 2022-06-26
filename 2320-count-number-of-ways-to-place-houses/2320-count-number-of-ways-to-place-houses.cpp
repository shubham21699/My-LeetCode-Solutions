class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int countHousePlacements(int n) {
        
        if(n == 1) return 4;
        
        vector<long long> houses(n+1, 0);
        houses[0] = 1;
        houses[1] = 2;
        long long result = 0;
        
        for(int i=2 ; i<=n ; i++) {
            houses[i] = (houses[i-1] + houses[i-2]) % mod;
            result = (houses[i] * houses[i]) % mod;
        }
        
        return result;
    }
};