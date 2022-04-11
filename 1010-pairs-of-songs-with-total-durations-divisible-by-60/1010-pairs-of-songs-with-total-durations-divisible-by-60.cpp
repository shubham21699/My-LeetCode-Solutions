class Solution {   
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        if(n == 1) return 0;
        if(n == 2) return (time[0] + time[1]) % 60 == 0;
        
        int count = 0;
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            int x = time[i] % 60;
            int y = (60 - x) % 60;
            
            count += mp[y];
            mp[x]++;
        }
        
        return count;
    }
};