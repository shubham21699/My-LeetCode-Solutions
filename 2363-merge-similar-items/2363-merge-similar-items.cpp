class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        int n = items1.size();
        int m = items2.size();
        map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) mp[items1[i][0]] = items1[i][1];
        for(int i=0 ; i<m ; i++) mp[items2[i][0]] += items2[i][1];
        
        vector<vector<int>> res;
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            res.push_back({ it->first, it->second });
        }
        
        return res;
    }
};