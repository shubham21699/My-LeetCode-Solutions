class Solution {
public:
    int mod = pow(10, 9) + 7;

    int numberOfWays(string corridor) {
        
        int n = corridor.size();
        
        int seats = 0;
        for(int i=0 ; i<n ; i++) if(corridor[i] == 'S') seats++;
        
        if(seats % 2 != 0 || seats < 2) return 0;
        if(seats == 2) return 1;
        if(seats == n) return 1;
        
        int startInd = 0;
        int endInd = n-1;
        while(corridor[startInd] == 'P') startInd++;
        while(corridor[endInd] == 'P') endInd--;
        
        seats = 0;
        int result = 1;
        
        for(int i=startInd ; i<=endInd ; i++) {
            
            if(corridor[i] == 'S') seats++;
            
            if(seats == 2 && i+1 <= endInd) {
                int j = i+1;
                int plants = 0;
                while(j < n && corridor[j] == 'P') {
                    plants++;
                    j++;
                }
                
                result = (1LL * result * (plants + 1)) % mod;
                seats = 0;
                i = j-1;
            }
            
        }
        
        return result;
    }
};