class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        int m = score.size();
        int n = score[0].size();
        
        sort(score.begin(), score.end(), [&](vector<int>& a, vector<int>& b) {
            return a[k] > b[k]; 
        });
        
        return score;
    }
};