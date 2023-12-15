class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        int n = paths.size();
        if(n == 1) return paths[0][1];
        
        unordered_set<string> city;
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            city.insert(paths[i][0]);
        }
        
        for(int i=0 ; i<n ; i++) {
            if(city.find(paths[i][1]) == city.end()) {
                result = paths[i][1];
                break;
            }
        }
        
        return result;
    }
};