class Solution {
    void combination(vector<vector<int>>& result, vector<int>& v, int n, int k, int index) {
        
        if(v.size() == k) {
            result.push_back(v);
            return;
        }
        if(index > n) return;
        
        for(int i=index ; i<=n ; i++) {
            v.push_back(i);
            combination(result, v, n, k, i+1);
            v.pop_back(); // Backtrack
        }
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        
        if(n == 1) return {{ 1 }};
        if(n == k) {
            vector<int> v(n);
            iota(v.begin(), v.end(), 1);
            return { v };
        }
        
        vector<vector<int>> result;
        vector<int> v;
        combination(result, v, n, k, 1);
        
        return result;
    }
};