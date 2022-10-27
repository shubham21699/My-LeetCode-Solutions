class Solution {
public:    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        vector<pair<int, int>> img1sCoordinates, img2sCoordinates;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(img1[i][j] == 1) img1sCoordinates.push_back({ i, j });
                if(img2[i][j] == 1) img2sCoordinates.push_back({ i, j });
            }
        }
        
        int result = 0;
        map<pair<int, int>, int> mp;
        
        for(auto [i1, j1] : img1sCoordinates) {
            for(auto [i2, j2] : img2sCoordinates) {
                // Distance between those coordinates of both images will remain the same which 
                // will overlap them after translating them.
                mp[{ i1-i2, j1-j2 }]++;
                result = max(result, mp[{ i1-i2, j1-j2 }]);
            }
        }
        
        return result;
    }
};