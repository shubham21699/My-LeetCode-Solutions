class Solution {
    void create(string s, vector<string>& result, int index, int n) {
        
        if(index >= n) return;
        
        for(int i=index ; i<n ; i++) {
            
            if(s[i] >= 'a' && s[i] <= 'z') {
                char ch = s[i];
                
                s[i] = toupper(ch);
                result.push_back(s);
                
                create(s, result, i+1, n);
                
                s[i] = tolower(ch); // Backtrack
                
            }
            
        }
        
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        
        int n = s.length();
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
        }
        
        vector<string> result;
        result.push_back(s);
        
        create(s, result, 0, n);
        return result;
    }
};