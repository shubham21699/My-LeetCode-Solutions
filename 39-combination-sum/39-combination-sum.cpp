class Solution {
    void find(vector<int>& candidates, int target, vector<vector<int> >& result, vector<int>& v, int index, int n, int sum) {
        
        if(sum == target) {
            result.push_back(v);
            return;
        }
        if(sum > target || index >= n) {
            return;
        }
        
        
        for(int i=index ; i<n ; i++) {
            v.push_back(candidates[i]);

            find(candidates, target, result, v, i, n, sum+candidates[i]);

            v.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int> > result;
        
        if(n == 1) {
            if(target < candidates[0]) {
                return result;
            }
        }
        
        vector<int> v;
        int sum = 0;
        find(candidates, target, result, v, 0, n, sum);
        return result;
    }
};