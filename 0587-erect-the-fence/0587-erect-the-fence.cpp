class Solution {
public:
    bool isClockwiseTurn(vector<int>& a, vector<int>& b, vector<int>& c) {
        
        int xa = a[0], xb = b[0], xc = c[0];
        int ya = a[1], yb = b[1], yc = c[1];
        bool isConvex = ((yc - yb) * (xb - xa)) - ((yb - ya) * (xc - xb)) >= 0;
        
        return isConvex;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        int n = trees.size();
        
        sort(trees.begin(), trees.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> fence;
        
        for(int i=0 ; i<n ; i++) {
            
            while(fence.size() > 1 && !isClockwiseTurn(fence[fence.size()-2], fence[fence.size()-1], trees[i])) {
                fence.pop_back();
            }
            
            fence.push_back(trees[i]);
        }
         
        for(int i=n-1 ; i>=0 ; i--) {
            
            while(fence.size() > 1 && !isClockwiseTurn(fence[fence.size()-2], fence[fence.size()-1], trees[i])) {
                fence.pop_back();
            }
            
            fence.push_back(trees[i]);
        }
        
        fence.pop_back();
        
        sort(fence.begin(), fence.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        fence.erase(unique(fence.begin(), fence.end()), fence.end());
        
        return fence;
    }
};