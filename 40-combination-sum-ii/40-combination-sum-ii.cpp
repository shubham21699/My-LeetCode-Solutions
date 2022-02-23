class Solution {
    void combination(vector<int>& candidates, vector<vector<int>>& result, vector<int>& v, int target, int index, int n) {
        
        if(target == 0) {
            result.push_back(v);
            return;
        }
        
        if(index >= n) return;
        
        for(int i=index ; i<n ; i++) {
            if(candidates[i] > target) return;
            if(i > 0 && candidates[i] == candidates[i-1] && i > index) continue;
            
            v.push_back(candidates[i]);    
            combination(candidates, result, v, target - candidates[i], i+1, n);
            v.pop_back(); // Backtrack
        } 
        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        if(n == 1) {
            if(candidates[0] == target) return { candidates };
            return {};
        }
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> v;
        combination(candidates, result, v, target, 0, n);
        
        return result;
    }
};