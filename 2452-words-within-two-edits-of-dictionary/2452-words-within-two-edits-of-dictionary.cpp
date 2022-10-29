class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        int n = queries.size();
        int m = dictionary.size();
        int r = queries[0].length();
        vector<string> result;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int editDiff = 0;
                
                for(int k=0 ; k<r ; k++) {
                    editDiff += queries[i][k] == dictionary[j][k] ? 0 : 1;
                }
                
                if(editDiff <= 2) {
                    result.push_back(queries[i]);
                    break;
                }
                
            }
        }
        
        return result;
    }
};