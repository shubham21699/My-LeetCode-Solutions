class Solution {
    void combination(vector<vector<int>>& result, vector<int>& v, int k, int n, int value) {
        
        if(v.size() == k && n == 0) {
            result.push_back(v);
            return;
        }
        if(n <= 0 || value > 9) return;
        
        for(int i=value ; i<=9 ; i++) {
            v.push_back(i);
            combination(result, v, k, n-i, i+1);
            v.pop_back(); // Backtrack
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> v;
        
        combination(result, v, k , n, 1);
        return result;
    }
};