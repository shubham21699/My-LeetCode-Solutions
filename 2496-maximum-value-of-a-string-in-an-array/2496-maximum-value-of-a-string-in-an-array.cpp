class Solution {
public:
    int maximumValue(vector<string>& strs) {
        
        int n = strs.size();
        int result = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            bool isAlphanumeric = false;
            
            for(int j=0 ; j<strs[i].length() ; j++) {
                if(!isdigit(strs[i][j])) {
                    result = max(result, int(strs[i].length()));
                    isAlphanumeric = true;
                    break;
                }
            }
            
            if(!isAlphanumeric) result = max(result, stoi(strs[i]));
            
        }
        
        return result;
    }
};