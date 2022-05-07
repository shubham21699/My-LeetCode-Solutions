class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n = students.size();
        vector<int> permute(n);
        for(int i=0 ; i<n ; i++) permute[i] = i;
        
        int maxScore = 0;
        
        do {
            int score = 0;
            
            for(int i=0 ; i<n ; i++) {
                int bit = 0;
                int k = permute[i];
                
                for(int j=0 ; j<students[i].size() ; j++) {
                    bit += !(students[i][j] xor mentors[k][j]);
                }
                
                score += bit;
            }
            
            maxScore = max(maxScore, score);
            
        } while(next_permutation(permute.begin(), permute.end()));
        
        return maxScore;
    }
};