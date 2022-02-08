class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        
        sort(strs.begin(), strs.end());
        string result = "";
        
        for(int i=0 ; i<strs[0].length() ; i++) {
            if(strs[0][i] != strs[n-1][i]) break;
            result += strs[0][i];
        }
        
        return result;
    }
};