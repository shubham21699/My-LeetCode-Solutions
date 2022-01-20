class Solution {
    unordered_map<char, string> m = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" }, 
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };
    
    void find(string digits, string s, vector<string>& result, int index, int n) {
                
        if(s.length() == n) {
            result.push_back(s);
            return;
        }
        
        if(index >= n) return;
        
        string x = m[digits[index]];
        
        for(int i=0 ; i<x.length() ; i++) {
            s.push_back(x[i]);
            find(digits, s, result, index+1, n);
            s.pop_back();
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();
        vector<string> result;
        
        if(n == 0) return result;
        if(n == 1) {
            string s = m[digits[0]];
            for(int i=0 ; i<s.length() ; i++) {
                string x = "";
                result.push_back(x + s[i]);
            }
            return result;
        }
        
        string s = "";
        find(digits, s, result, 0, n);
        return result;
    }
};