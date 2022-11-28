class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        int n = matches.size();
        map<int, int> winners, loosers;
        
        for(int i=0 ; i<n ; i++) {
            winners[matches[i][0]]++;
            loosers[matches[i][1]]++;
        }
        
        vector<vector<int>> result(2);
        
        for(auto it=winners.begin() ; it!=winners.end() ; it++) {
            if(loosers.find(it->first) == loosers.end()) {
                result[0].push_back(it->first);
            }
        }
        
        for(auto it=loosers.begin() ; it!=loosers.end() ; it++) {
            if(it->second == 1) result[1].push_back(it->first);
        }
        
        return result;
    }
};