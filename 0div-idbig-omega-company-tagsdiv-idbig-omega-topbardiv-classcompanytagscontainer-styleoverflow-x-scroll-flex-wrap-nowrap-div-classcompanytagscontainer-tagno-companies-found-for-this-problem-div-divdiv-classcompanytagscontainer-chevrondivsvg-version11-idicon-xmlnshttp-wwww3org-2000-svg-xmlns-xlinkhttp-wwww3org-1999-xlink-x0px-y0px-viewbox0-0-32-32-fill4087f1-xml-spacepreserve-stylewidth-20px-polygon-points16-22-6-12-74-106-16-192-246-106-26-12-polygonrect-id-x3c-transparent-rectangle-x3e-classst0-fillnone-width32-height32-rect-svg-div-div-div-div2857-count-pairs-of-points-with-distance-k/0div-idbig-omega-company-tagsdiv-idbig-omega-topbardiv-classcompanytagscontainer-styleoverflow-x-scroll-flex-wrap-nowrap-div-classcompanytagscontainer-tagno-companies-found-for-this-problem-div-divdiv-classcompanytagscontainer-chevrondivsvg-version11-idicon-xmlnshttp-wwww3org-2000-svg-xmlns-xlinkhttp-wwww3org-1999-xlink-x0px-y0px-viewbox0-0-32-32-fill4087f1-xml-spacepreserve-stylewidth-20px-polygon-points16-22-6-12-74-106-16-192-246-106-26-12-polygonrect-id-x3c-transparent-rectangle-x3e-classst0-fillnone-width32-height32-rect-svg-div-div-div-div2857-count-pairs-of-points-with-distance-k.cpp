class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        
        int n = coordinates.size();
        map<pair<int, int>, int> mp;
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            // Finding all possible (x,y) which gives : 
            // coordinates[i][0]^x + coordinates[i][1]^y = k       (0)
            // Consider above is true, then
            // if,  coordinates[i][0]^x = val                      (1)
            // then coordinates[i][1]^y = k-val                    (2)
            
            // We can definitely find all possible values of val (0 to k inclusive) 
            // using a^b = c , then a^c = b
            // from (1), we have coordinates[i][0]^val = x;
            // from (2), we have coordinates[i][1]^(k-val) = y;
            // So we need to traverse through all possible values of val to get pairs(x,y) satisfying eq.(0) 
            
            for(int val=0 ; val<=k ; val++) {
                int x = coordinates[i][0] xor val;
                int y = coordinates[i][1] xor (k-val);
                count += mp[{ x, y }];
            }
            
            mp[{ coordinates[i][0], coordinates[i][1] }]++;
        }
        
        return count;
    }
};