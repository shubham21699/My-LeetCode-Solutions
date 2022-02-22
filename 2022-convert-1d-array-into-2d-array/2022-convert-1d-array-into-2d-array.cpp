class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        int k = original.size();
        if(m*n != k) return {};
        
        vector<vector<int>> result;
        
        for(int i=0 ; i<k ; i+=n) {
            result.push_back(vector<int>(original.begin() + i, original.begin() + i + n));
        }
        
        return result;
    }
};