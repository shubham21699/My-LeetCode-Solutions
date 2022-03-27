class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        
        for(int i=0 ; i<n ; i++) {
            int soldiers = 0;
            for(int j=0 ; j<m ; j++) {
                soldiers += mat[i][j];
            }
            p.push({ soldiers, i });
        }
        
        vector<int> result;
        
        while(!p.empty() && k--) {
            result.push_back(p.top().second);
            p.pop();
        }
        
        return result;
    }
};