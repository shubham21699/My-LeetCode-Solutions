class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n <= 2) return 0;
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            unordered_map<long double, int> mp;
            
            for(int j=0 ; j<n ; j++) {
                if(i == j) continue;
                long double dist = sqrt(pow(points[i][0] - points[j][0], 2) + 
                                        pow(points[i][1] - points[j][1], 2));
                mp[dist]++;
            }
        
            for(auto it=mp.begin() ; it!=mp.end() ; it++) {
                if(it->second > 1) count += it->second * (it->second - 1);
            }
            
        }
        
        return count;
    }
};